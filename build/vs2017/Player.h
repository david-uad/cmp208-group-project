#pragma once
#include "GameObject.h"
#include "input/input_manager.h"
#include <input/keyboard.h>
#include <input/sony_controller_input_manager.h>

class Player : public GameObject
{
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
    void setPlayerPos(float x, float y);
    gef::Vector4 getPlayerPos();
    

private:
    gef::InputManager* input_manager_ = nullptr;
    float health;
};