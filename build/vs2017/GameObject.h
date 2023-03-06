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

	void Init();
	void Update();

private:
	b2World* world = nullptr;
	b2BodyDef bdDef_; // body definition
	b2Body* body_; // body pointer
	b2PolygonShape boundingBox_; // bounding box
	b2FixtureDef fixDef_; // fixture definition
};

