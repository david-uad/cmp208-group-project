#include "Player.h"

Player::Player()
{
	// set default values
	player->health = 100.0;
	player->x, player->y = 0;
}

Player::~Player()
{

}

void Player::InitInput(gef::InputManager* in)
{
	input_manager_ = in;
}

void Player::Update(float dt)
{
	handleInput(dt);

	SetTransform();
}

void Player::handleInput(float dt)
{
	// Local variables
	const gef::SonyController* controller = nullptr;
	const gef::Keyboard* keyboard = nullptr;
	float x_mod = 0, y_mod = 0;

	//// *** CONTROLLER INPUT ***
	//// Pointer to controller
	//controller = input_manager_->controller_input()->GetController(0);

	//// Get values for x and y axis movement
	//x_mod = controller->left_stick_x_axis();
	//y_mod = controller->left_stick_y_axis();

	// *** KEYBOARD INPUT ***
	// Pointer to keyboard
	keyboard = input_manager_->keyboard();

	// Handle inputs

	// Movement
	if (keyboard->IsKeyDown(gef::Keyboard::KC_W))
	{
		y_mod = 1;
	}
	if (keyboard->IsKeyDown(gef::Keyboard::KC_S))
	{
		y_mod = -1;
	}
	if (keyboard->IsKeyDown(gef::Keyboard::KC_D))
	{
		x_mod = 1;
	}
	if (keyboard->IsKeyDown(gef::Keyboard::KC_A))
	{
		x_mod = -1;
	}
	// Rotation
	if (keyboard->IsKeyDown(gef::Keyboard::KC_RIGHT))
	{
		// Add to current rotation
		rotation_.set_z(rotation_.z() - gef::DegToRad(1));
	}
	if (keyboard->IsKeyDown(gef::Keyboard::KC_LEFT))
	{
		// Add to current rotation
		rotation_.set_z(rotation_.z() + gef::DegToRad(1));
	}

	// Calculate displacement per frame
	gef::Vector4 s = gef::Vector4(x_mod * speed_ * dt, y_mod * speed_ * dt, 0);
	// Add displacement to position
	position_ = position_ + s;
}

float Player::getHealth()
{
	return health;
}

void Player::setHealth(float h)
{
	health = h;
}

void Player::setPlayerX(int pos)
{
	player->x = pos;
}

void Player::setPlayerY(int pos)
{
	player->y = pos;
}

int Player::getPlayerX()
{
	return player->x;
}

int Player::getPlayerY()
{
	return player->y;
}