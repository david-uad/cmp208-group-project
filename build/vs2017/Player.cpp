#include "Player.h"

Player::Player()
{
	// set default values
	health = 100.0;
}

Player::~Player()
{

}

void Player::handleInput(float dt)
{
	// Handle keyboard input to control player movement
	if (player->isKeyDown('w'))
	{
		// move player forward (++ y-axis)
	}

	if (player->isKeyDown('a'))
	{
		// move player left (-- x-axis)
	}

	if (player->isKeyDown('s'))
	{
		// move player backward (-- x-axis)
	}

	if (player->isKeyDown('d'))
	{
		// move player right (++ x-axis)
	}
}

void Player::setKeyDown(unsigned char key)
{
	if (key >= 0)
	{
		keys[key] = true;
	}
}

void Player::setKeyUp(unsigned char key)
{
	if (key >= 0)
	{
		keys[key] = false;
	}
}

bool Player::isKeyDown(int key)
{
	if (key >= 0)
	{
		return keys[key];
	}
	return false;
}

float Player::getHealth()
{
	return health;
}

void Player::setHealth(float h)
{
	health = h;
}