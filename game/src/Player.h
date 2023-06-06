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

    void movePalyer(Vector2 delta) {


        setCurrentPosX(getCurrentPos().x + (delta.x * getSpeed()));
        setCurrentPosY(getCurrentPos().y + (delta.y * getSpeed()));

        //// Actualizar la posición del círculo gradualmente hacia la posición del clic
        //if (getCurrentPos().x < clickPosition.x) setCurrentPosX(getCurrentPos().x + getSpeed());
        //else if (getCurrentPos().x > clickPosition.x) setCurrentPosX(getCurrentPos().x - getSpeed());

        //if (getCurrentPos().y < clickPosition.y) setCurrentPosY(getCurrentPos().y + getSpeed());
        //else if (getCurrentPos().y > clickPosition.y) setCurrentPosY(getCurrentPos().y - getSpeed());

        //// Si el círculo está cerca de la posición del clic, detener el movimiento y restablecer la variable de movimiento
        //if (CheckCollisionCircles(getCurrentPos(), getRadius(), clickPosition, 0.1f)) {
        //    setIsMoving(false);
        //}    
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