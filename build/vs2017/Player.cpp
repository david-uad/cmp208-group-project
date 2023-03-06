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