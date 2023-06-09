#pragma once
#include "raylib.h"
#include <iostream>
#include <map>

class Player :public CharacterBase {

    unsigned char exp;
    unsigned char expMax = 100;
    unsigned char level;
    unsigned char attributePoints;

    bool isGameOver = false;

    Vector2 posHealthWidget;

    std::map<Items, int> backpack;

public:
    Player() {
        exp = 0;
        level = 1;
        attributePoints = 2;

        //UI
        posHealthWidget = { WIDGET_POS_X , WIDGET_POS_Y };
    }
    Player(Texture2D pImg, char pDamage, Vector2 pPosition) {
        exp = 0;
        level = 1;
        attributePoints = 2;
        setImg(pImg);
        setDamage(pDamage);
        setCurrentPos(pPosition);

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

    bool getIsGameOver() { return isGameOver; }
    void setGameOver(bool pIsGameOver) { isGameOver = pIsGameOver; }
    
    std::map<Items, int> getBackpack() { return backpack; }

    void movePalyer() {

        Vector2 movement;
        movement.x = 0;
        movement.y = 0;

        if (IsKeyDown(KEY_A)) {
            setImg(playerImpLeft);
            if (getCurrentPos().x >= 2)  movement.x = -1;
        }
        if (IsKeyDown(KEY_D)) {
            setImg(playerImpRight);
            if (getCurrentPos().x <= 698) movement.x = 1;
        }
        if (IsKeyDown(KEY_W)) {
            setImg(playerImpUp);
            if (getCurrentPos().y >= 2) movement.y = -1;
        }
        if (IsKeyDown(KEY_S)) {
            setImg(playerImpDown);
            if (getCurrentPos().y <= 385) movement.y = 1;
        }

        Vector2 actualPosition = { getCurrentPos().x + (movement.x * getSpeed()) , getCurrentPos().y + (movement.y * getSpeed()) };

        setCurrentPos({actualPosition.x, actualPosition.y});
        setRectangle({ getCurrentPos().x, getCurrentPos().y, 70, 70 });

    }

    void drawPlayer() {
        //DrawRectangleRec(getRectangle(), RED); //SoloDebugColisiones
        DrawTexture(getImg(), getCurrentPos().x, getCurrentPos().y, WHITE);
    
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

    void addItemToBackpack(Items pItem, int pQuantity) {
        
        backpack.insert(std::make_pair(pItem, pQuantity));      

        //debugMap();
    }

    void dropItemToBackpack(Items pItem){

        backpack.erase(pItem);

        //debugMap();
    }

    //Solo para pintar logs
    void debugMap() {

        std::cout << "KEY\tELEMENT\n";
        for (auto itr = backpack.begin(); itr != backpack.end(); ++itr) {
            std::cout << itr->first << '\t' << itr->second << '\n';
        }
    
    }
};