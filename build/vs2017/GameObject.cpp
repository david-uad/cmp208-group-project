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