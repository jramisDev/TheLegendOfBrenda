#pragma once
#include "raylib.h"

class CharacterBase {

    unsigned char speed;
    unsigned char health;
    unsigned char healthMax;
    bool isPlayer;

    Vector2 currentPos;
    float radius;

    Texture2D img;

public:
    CharacterBase() {
        speed = 2;
        healthMax = 5;
        health = 2;
        isPlayer = false;
        currentPos = startCharacterPosition(false);
        radius = 25.0f;
    }
    CharacterBase(Texture2D pImg) {
        speed = 2;
        healthMax = 5;
        health = 2;
        isPlayer = false;
        currentPos = startCharacterPosition(false);
        radius = 25.0f;
        img = pImg;
    }

    char getSpeed() { return speed; }
    void setSpeed(char pSpeed) { speed = pSpeed; }

    char getHealthMax() { return healthMax; }
    char getHealth() { return health; }

    bool getIsPlayer() { return isPlayer; }
    void setIsPlayer(bool pIsPlayer) { isPlayer = pIsPlayer; }

    Vector2 getCurrentPos() { return currentPos; }
    void setCurrentPosX(float pNewPosition) { currentPos.x = pNewPosition; }
    void setCurrentPosY(float pNewPosition) { currentPos.y = pNewPosition; }

    float getRadius() { return radius; }

    Texture2D getImg() { return img; }

    void drawEnemy() {

        DrawCircleV(getCurrentPos(), getRadius(), BLUE);
    }
};