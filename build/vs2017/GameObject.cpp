#include "GameObject.h"

GameObject::GameObject()
{
	// Initial transform
	scale_ = gef::Vector4(1, 1, 1);
	rotation_ = gef::Vector4(0, 0, 0);
	position_ = gef::Vector4(0, 0, 0);
}

GameObject::~GameObject()
{

}

void GameObject::Init(gef::Renderer3D* r, b2World* w)
{
	world_ = w;
	renderer_ = r;
}

void GameObject::Render()
{
	renderer_->DrawMesh(*this);
}

void GameObject::InitBox2d(bool isStatic, b2Vec2 pos, b2Vec2 box)
{
	// type static
	if (isStatic)
	{
		bdDef_.type = b2_staticBody;
	}
	// type dynamic
	else
	{
		bdDef_.type = b2_dynamicBody;
	}
	// set position
	bdDef_.position.Set(pos.x, pos.y);
	// create body
	world_->CreateBody(&bdDef_);
	// set bounding box
	boundingBox_.SetAsBox(box.x, box.y);
	// define fixture definition
	fixDef_.shape = &boundingBox_;
	fixDef_.density = 1.0f;
	fixDef_.friction = 0.3f;
	// create fixture and attach to body
	body_->CreateFixture(&fixDef_);
}

void GameObject::SetTransform()
{
	// Matrices for transform
	gef::Matrix44 scale_mat, rotateX_mat, rotateY_mat, rotateZ_mat, translate_mat;
	// Set scaling matrix
	scale_mat.SetIdentity();
	scale_mat.Scale(scale_);
	// Rotation matrix
	rotateX_mat.RotationX(rotation_.x());
	rotateY_mat.RotationY(rotation_.y());
	rotateZ_mat.RotationZ(rotation_.z());
	// Translation matrix
	translate_mat.SetIdentity();
	translate_mat.SetTranslation(position_);
	// Final transform matrix (SxyRxRyRzT)
	gef::Matrix44 final_matrix = scale_mat * rotateX_mat * rotateY_mat * rotateZ_mat * translate_mat;
	set_transform(final_matrix);
}