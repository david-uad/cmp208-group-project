#include "Player.h"

Player::Player()
{
	// set default values
	health = 100.0;
}

Player::~Player()
{

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