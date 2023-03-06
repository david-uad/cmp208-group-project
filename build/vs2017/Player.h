#pragma once
#include "GameObject.h"
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
    void Update(float dt);

    // Getters and setters for keys
    bool isKeyDown(int key);

    // Getters and setters for player stats, etc.
    float getHealth();
    void setHealth(float h);

    // Getters and setters for player position
    void setPlayerX(int lx);
    void setPlayerY(int ly);
    int getPlayerX();
    int getPlayerY();
    

private:
    // Boolean array, element per key
    bool keys[256]{ false };
};