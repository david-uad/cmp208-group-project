#ifndef _SCENE_APP_H
#define _SCENE_APP_H

#include <system/application.h>
#include <maths/vector2.h>
#include "primitive_builder.h"
#include <graphics/mesh_instance.h>
#include "box2d/box2d.h"

// FRAMEWORK FORWARD DECLARATIONS
namespace gef
{
	class Platform;
	class SpriteRenderer;
	class Font;
	class InputManager;
	class Renderer3D;
}

class SceneApp : public gef::Application
{
public:
	SceneApp(gef::Platform& platform);
	void Init();
	void CleanUp();
	bool Update(float frame_time);
	void Render();
private:
	void InitFont();
	void CleanUpFont();
	void DrawHUD();
	void SetupLights();


    
	gef::SpriteRenderer* sprite_renderer_;
	gef::Font* font_;
	gef::Renderer3D* renderer_3d_;

	PrimitiveBuilder* primitive_builder_;

	gef::MeshInstance player_;
	b2BodyDef plyr_bdDef_; // player body definition
	b2Body* plyr_bd_; // player body
	b2PolygonShape plyr_bb_; // // player bounding box
	b2FixtureDef plyr_fd_; // fixture definition

	b2World* b2world_; // box2d world
	b2Vec2 gravity_ = { 0, 9.81 }; // gravity vector

	float fps_;

};

#endif // _SCENE_APP_H
