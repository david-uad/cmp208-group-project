#pragma once
#include "GameObject.h"
#include "input/input_manager.h"
#include <input/keyboard.h>
#include <input/sony_controller_input_manager.h>

class Player : public GameObject
{
    Player* player;
    float health;
    float moveSpeed;
    int x, y;

public:
    Player();
    ~Player();

    void handleInput(float dt);
    void InitInput(gef::InputManager* in);
    void Update(float dt);

    // Getters and setters for player stats, etc.
    float getHealth();
    void setHealth(float h);

    // Getters and setters for player position
    void setPlayerX(int lx);
    void setPlayerY(int ly);
    int getPlayerX();
    int getPlayerY();
    

private:
    gef::InputManager* input_manager_ = nullptr;
};