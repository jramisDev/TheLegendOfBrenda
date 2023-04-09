#pragma once
#include "raylib.h"

class Player :public CharacterBase {


    bool isMoving;

    Vector2 posHealthWidget;

public: 
    Player(){
        setIsPlayer(true);
        isMoving = false;

        //UI
        posHealthWidget = { WIDGET_POS_X , WIDGET_POS_Y };
    }


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




        //// Actualizar la posición del círculo gradualmente hacia la posición del clic
        //if (circlePosition.x < clickPosition.x) circlePosition.x += player.getSpeed();
        //else if (circlePosition.x > clickPosition.x) circlePosition.x -= player.getSpeed();

        //if (circlePosition.y < clickPosition.y) circlePosition.y += player.getSpeed();
        //else if (circlePosition.y > clickPosition.y) circlePosition.y -= player.getSpeed();

        //// Si el círculo está cerca de la posición del clic, detener el movimiento y restablecer la variable de movimiento
        //if (CheckCollisionCircles(circlePosition, circleRadius, clickPosition, 0.1f)) {
        //    player.setIsMoving(false);
        //}
    
    }

    void drawPlayer() {

        DrawCircleV(getCurrentPos(), getRadius(), GREEN);
    
    }


    //UI
    void drawUI() {

        heartUI = LoadTexture("resources/UI/heartUI.png");

        for (int i = 0; i < getHealthMax(); ++i) {

            if (i > getHealth()) DrawTexture(heartUI, WIDGET_POS_X + (WIDGET_SIZE * i), WIDGET_POS_Y, BLACK);
            else DrawTexture(heartUI, WIDGET_POS_X + (WIDGET_SIZE * i), WIDGET_POS_Y, WHITE);
        }

    }
};