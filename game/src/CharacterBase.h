#pragma once
#include "raylib.h"

class CharacterBase {

    unsigned char speed;
    unsigned char health;
    unsigned char healthMax;
    bool isPlayer;

    Vector2 currentPos;

    Texture2D img;

    Rectangle rect;

public:
    CharacterBase() {
        speed = 2;
        healthMax = 5;
        health = 2;
        isPlayer = false;
        currentPos = startCharacterPosition(false);
        rect = { currentPos.x,currentPos.y, 40, 40 };
        img = enemyImg;

    }
    CharacterBase(Texture2D pImg) {
        speed = 2;
        healthMax = 5;
        health = 2;
        isPlayer = false;
        currentPos = startCharacterPosition(false);
        rect = { currentPos.x,currentPos.y, 40, 40 };
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

    Rectangle getRectangle() { return rect; }    
    void setRectangle(Rectangle pRectangle) { rect = pRectangle; }

    Texture2D getImg() { return img; }
    void setImg(Texture2D pImg) { img = pImg; }

    void drawEnemy() {

//        DrawCircleV(getCurrentPos(), getRadius(), RED);
    }

    void addHealth() {
        if (health < healthMax) health++;
    }
};