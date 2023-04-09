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

    char getLevel() { return level; }

    void setExp(char pExp) {
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

    void movePalyer(Vector2 clickPosition) {

        // Actualizar la posición del círculo gradualmente hacia la posición del clic
        if (getCurrentPos().x < clickPosition.x) setCurrentPosX(getCurrentPos().x + getSpeed());
        else if (getCurrentPos().x > clickPosition.x) setCurrentPosX(getCurrentPos().x - getSpeed());

        if (getCurrentPos().y < clickPosition.y) setCurrentPosY(getCurrentPos().y + getSpeed());
        else if (getCurrentPos().y > clickPosition.y) setCurrentPosY(getCurrentPos().y - getSpeed());

        // Si el círculo está cerca de la posición del clic, detener el movimiento y restablecer la variable de movimiento
        if (CheckCollisionCircles(getCurrentPos(), getRadius(), clickPosition, 0.1f)) {
            setIsMoving(false);
        }    
    }

    void drawPlayer() {

        playerImg = LoadTexture("resources/Player/player_right.png");

        DrawCircleV(getCurrentPos(), getRadius(), GREEN);
        DrawTexture(playerImg, getCurrentPos().x-getRadius(), getCurrentPos().y-getRadius(), WHITE);
    
    }


    //UI
    void drawUI() {

        levelUI = LoadTexture("resources/UI/level.png");
        heartUI = LoadTexture("resources/UI/heartUI.png");
         
        DrawTexture(levelUI, 0, 0, BLACK);
        DrawText("1", 17, 10, 25, BLACK);

        for (int i = 0; i < getHealthMax(); ++i) {

            if (i > getHealth()) DrawTexture(heartUI, 50 + WIDGET_POS_X + (WIDGET_SIZE * i), WIDGET_POS_Y, BLACK);
            else DrawTexture(heartUI, 50 + WIDGET_POS_X + (WIDGET_SIZE * i), WIDGET_POS_Y, WHITE);
        }

    }
};