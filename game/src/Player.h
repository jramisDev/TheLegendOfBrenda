#pragma once
#include "raylib.h"

class Player :public CharacterBase {

    unsigned char exp;
    unsigned char expMax = 100;
    unsigned char level;
    unsigned char attributePoints;

    bool isMoving;

    Vector2 posHealthWidget;

public:
    Player() {
        exp = 0;
        level = 1;
        attributePoints = 2;
        setIsPlayer(true);
        isMoving = false;

        //UI
        posHealthWidget = { WIDGET_POS_X , WIDGET_POS_Y };
    }
    Player(Texture2D pImg) {
        exp = 0;
        level = 1;
        attributePoints = 2;
        setIsPlayer(true);
        isMoving = false;
        setImg(pImg);

        //UI
        posHealthWidget = { WIDGET_POS_X , WIDGET_POS_Y };
    }

    char getLevel() { return level; }

    void addExp(char pExp) {
        if(pExp + exp >= expMax){
            level++;
            attributePoints++;
            exp = (pExp + exp) - expMax;        
        } else {        
            exp += pExp;
        }
    }

    char getAttributePoints() { return attributePoints; }
    void subtractAttributePoints() { attributePoints--; }

    bool getIsMoving() { return isMoving; }
    void setIsMoving(bool pIsMoving) { isMoving = pIsMoving; }

    void movePalyer() {

        Vector2 movement;
        movement.x = 0;
        movement.y = 0;

        if (IsKeyDown(KEY_A)) {
            if (getCurrentPos().x >= 2)  movement.x = -1;
        }
        if (IsKeyDown(KEY_D)) {
            if (getCurrentPos().x <= 698) movement.x = 1;
        }
        if (IsKeyDown(KEY_W)) {
            if (getCurrentPos().y >= 2) movement.y = -1;
        }
        if (IsKeyDown(KEY_S)) {
            if (getCurrentPos().y <= 385) movement.y = 1;
        }

        setCurrentPosX(getCurrentPos().x + (movement.x * getSpeed()));
        setCurrentPosY(getCurrentPos().y + (movement.y * getSpeed()));

    }

    void drawPlayer() {
        DrawCircleV(getCurrentPos(), getRadius(), GREEN);
        DrawTexture(getImg(), getCurrentPos().x - getRadius() - 10, getCurrentPos().y - getRadius() - 10, WHITE);
    
    }

    void drawUI() {

        //char levelAux = getLevel();
         
        DrawTexture(levelUI, 0, 0, BLACK);
        //DrawText(level, 17, 10, 25, BLACK);
        //DrawText("1", 17, 10, 25, BLACK);

        for (int i = 0; i < getHealthMax(); ++i) {

            if (i > getHealth()) DrawTexture(heartUI, 50 + WIDGET_POS_X + (WIDGET_SIZE * i), WIDGET_POS_Y, BLACK);
            else DrawTexture(heartUI, 50 + WIDGET_POS_X + (WIDGET_SIZE * i), WIDGET_POS_Y, WHITE);
        }

    }
};