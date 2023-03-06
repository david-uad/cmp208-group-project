#pragma once
#include "GameObject.h"
class Player : public GameObject
{
    Player* player;
    float health;

public:
    Player();
    ~Player();

    void handleInput(float dt);

    // Getters and setters for keys
    void setKeyDown(unsigned char key);
    void setKeyUp(unsigned char key);
    bool isKeyDown(int key);

    // Getters and setters for player stats, etc.
    float getHealth();
    void setHealth(float h);

private:
    // Boolean array, element per key
    bool keys[256]{ false };
};