#pragma once
#include "raylib.h"

class CharacterBase {

    unsigned char speed;
    unsigned char health;
    unsigned char healthMax;

    unsigned char damage;


    Vector2 currentPos;

    Texture2D img;

    Rectangle rect;

public:
    CharacterBase() {
        speed = 2;
        healthMax = 5;
        health = healthMax;
        currentPos = startCharacterPosition(false);
        rect = { currentPos.x,currentPos.y, 30, 30 };
        damage = 1;

    }
    CharacterBase(Texture2D pImg, char pDamage, char pHealthMax) {
        speed = 2;
        healthMax = pHealthMax;
        health = pHealthMax;
        currentPos = startCharacterPosition(false);
        rect = { currentPos.x,currentPos.y, 30, 30 };
        img = pImg;
        damage = pDamage;
    }

    char getSpeed() { return speed; }
    void setSpeed(char pSpeed) { speed = pSpeed; }

    char getHealthMax() { return healthMax; }
    char getHealth() { return health; }

    char getDamage() { return damage; }
    void setDamage(char pDamage) { damage = pDamage; }

    Vector2 getCurrentPos() { return currentPos; }
    void setCurrentPosX(float pNewPosition) { currentPos.x = pNewPosition; }
    void setCurrentPosY(float pNewPosition) { currentPos.y = pNewPosition; }

    Rectangle getRectangle() { return rect; }    
    void setRectangle(Rectangle pRectangle) { rect = pRectangle; }

    Texture2D getImg() { return img; }
    void setImg(Texture2D pImg) { img = pImg; }

    void drawEnemy() {

        DrawRectangleRec(rect,RED);
        DrawTexture(getImg(), getCurrentPos().x, getCurrentPos().y, WHITE);
    }

    void addHealth() {
        if (health < healthMax) health++;
    }

    void removeHealth(char pHealtErease) {
        std::cout << int(health) << "MUERTO\n";
                
        if (health > 0) health -= pHealtErease;
        else std::cout << "MUERTO\n";

        std::cout << int(health) << "MUERTO\n";
    }
};