#include "box2d/box2d.h"
#include "primitive_builder.h"
#include <graphics/renderer_3d.h>
#include <maths/math_utils.h>
#include "graphics\mesh_instance.h"

#pragma once
class GameObject : gef::MeshInstance
{
public:
	GameObject();
	~GameObject();

	void Init(gef::Renderer3D* r, b2World* w);
	void InitBox2d(bool isStatic, b2Vec2 pos, b2Vec2 box);
	void Render();

protected:
	// Call inside an update function after changing rotation_ scale_ or position_
	void SetTransform();

	gef::Renderer3D* renderer_ = nullptr;
	b2World* world_ = nullptr;
	b2Body* body_ = nullptr; // body pointer
	b2BodyDef bdDef_; // body definition
	b2PolygonShape boundingBox_; // bounding box
	b2FixtureDef fixDef_; // fixture definition

	float speed_;
	gef::Vector4 scale_, rotation_, position_;
};

