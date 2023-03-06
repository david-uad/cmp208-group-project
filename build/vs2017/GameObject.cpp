#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::~GameObject()
{

}

void GameObject::Init(gef::Renderer3D* r, b2World* w)
{
	world_ = w;
	renderer_ = r;
}

void GameObject::Update(float dt)
{

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