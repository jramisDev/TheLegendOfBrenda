/*******************************************************************************************
*
*   raylib game template
*
*   <The Legend Of Brenda>
*   <Final exercise for the C++ course at UT-HUB>
*
*   This game has been created using raylib (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2021 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#pragma warning(disable : 4244)

#include <iostream>
#include "raylib.h"
#include "Init.h"
#include "LevelData.h"
#include "CharacterBase.h"
#include "Player.h"
#include "Item.h"



Player player;
LevelData* game = new LevelData[4];
CharacterBase enemy = CharacterBase();

//Items
Item aidKit;
Item accessKey;
Item sneekers;

int main() {    

    initApp();

    while (globalRunning) {

        framesCounter++;

        if (WindowShouldClose()) globalRunning = false;

        BeginDrawing();

        ClearBackground(WHITE);

        switch (actualScreen) {
            case MENU: {

                mainScreen();

            }break;
            case PLAYER: {

                playerScreen();

            }break;
            case GAME: {

                gameScreen();

            }break;
            case END: {

                endScreen();

            }break;

        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void initApp() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);

    SetTargetFPS(FPS);

    mapaFueraMurallas = LoadTexture("resources/Mapas/FueraMurallas.png");
    mapaMurallas = LoadTexture("resources/Mapas/Murallas.png");
    mapaDentroCastillo = LoadTexture("resources/Mapas/DentroCastillo.png");
    mapaSalaTrono = LoadTexture("resources/Mapas/SalaTrono.png");

    levelUI = LoadTexture("resources/UI/level.png");
    heartUI = LoadTexture("resources/UI/heartUI.png");

    playerImg = LoadTexture("resources/Player/player_right.png");
    playerImpUp = LoadTexture("resources/Player/player_up.png");
    playerImpDown = LoadTexture("resources/Player/player_down.png");
    playerImpRight = LoadTexture("resources/Player/player_right.png");
    playerImpLeft = LoadTexture("resources/Player/player_left.png");

    trapImg = LoadTexture("resources/Enemy/trap.png");

    aidKitImg = LoadTexture("resources/Item/aidKit.png");
    keyImg = LoadTexture("resources/Item/key.png");
    sneekersImg = LoadTexture("resources/Item/zapatillas.png");

    game[0] = LevelData(mapaFueraMurallas, "Fuera Murallas");
    game[1] = LevelData(mapaMurallas, "Murallas");
    game[2] = LevelData(mapaDentroCastillo, "Castillo");
    game[3] = LevelData(mapaSalaTrono, "Sala Trono");

    player = Player(playerImg, 1);
    player.setCurrentPosX(100);
    player.setCurrentPosY(150);
    enemy = CharacterBase(trapImg,1,1);
    aidKit = Item(aidKitImg, AIDKIT);
    accessKey = Item(keyImg, KEY);
    sneekers = Item(sneekersImg, SNEEKERS);
}

void mainScreen() {

    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, RAYWHITE);

    DrawText(GAME_TITLE, SCREEN_WIDTH / 2 - MeasureText(GAME_TITLE, 40) / 2, 100, 40, RED);
    DrawText("PRESS ENTER to GAME", SCREEN_WIDTH / 2 - MeasureText("PRESS ENTER to GAME", 20) / 2, 150, 20, DARKBLUE);

    DrawText("CONTROLS", SCREEN_WIDTH / 2 - MeasureText("CONTROLS", 20) / 2, 200, 20, BLACK);
    DrawText("LEFT MOUSE button to MOVE to LOCATION", SCREEN_WIDTH / 2 - MeasureText("LEFT MOUSE button to MOVE to LOCATION", 15) / 2, 225, 15, BLACK);
    DrawText("PRESS I key to CUSTOM player", SCREEN_WIDTH / 2 - MeasureText("PRESS I or SCPAES key OP CUSTOM player", 15) / 2, 250, 15, BLACK);
  
    if (IsKeyDown(KEY_ENTER)) actualScreen = PLAYER;

}

void gameScreen() {

    if (IsKeyDown(KEY_I)) actualScreen = PLAYER;

    //Fondo
    game[actualLevel].drawLevel();

    //std::cout << "\nHoliii: " << actualLevel;

    //Movimiento del personaje
    player.movePalyer();


    //Dibujamos elemento
    player.drawUI();
    enemy.drawEnemy();
    aidKit.drawItem();
    accessKey.drawItem();
    sneekers.drawItem();
    player.drawPlayer();

    //Gestionamos las colisiones con los diferentes elementos
    checkCollisions();
}

void playerScreen() {

    DrawText("PLAYER SCREEN", SCREEN_WIDTH / 2 - MeasureText("PLAYER SCREEN", 40) / 2, SCREEN_HEIGHT / 2 - 40, 40, DARKGREEN);
    DrawText("PRESS SPACE or I to GAME", SCREEN_WIDTH / 2 - MeasureText("PRESS SPACE or I to GAME", 20) / 2, SCREEN_HEIGHT / 2, 20, DARKGREEN);

    if (IsKeyDown(KEY_I)) actualScreen = GAME;
    if (IsKeyDown(KEY_SPACE)) actualScreen = GAME;

    return;

}

void endScreen() {

    if (!player.getIsGameOver()) {
        DrawText("YOU WIN!", SCREEN_WIDTH / 2 - MeasureText("YOU WIN!", 40) / 2, SCREEN_HEIGHT / 2 - 40, 40, DARKGREEN);
    } else {
        DrawText("Game over!", SCREEN_WIDTH / 2 - MeasureText("Game over!", 40) / 2, SCREEN_HEIGHT / 2 - 40, 40, BLACK);
    }


    return;
}

void checkCollisions() {

    //Colision vida
    if (CheckCollisionRecs(player.getRectangle(), aidKit.getRectangle())) {
        player.addHealth();
        player.addExp(aidKit.getExp());
        aidKit.removeItem();
    }

    //Colision llave
    if (CheckCollisionRecs(player.getRectangle(), accessKey.getRectangle())) {
        player.addExp(accessKey.getExp());
        player.addItemToBackpack(KEY, 1);
        accessKey.removeItem();
    }

    //Colision zapatillas
    if (CheckCollisionRecs(player.getRectangle(), sneekers.getRectangle())) {
        player.setSpeed(player.getSpeed() * 2);
        player.addItemToBackpack(SNEEKERS, 1);
        player.addExp(sneekers.getExp());
        sneekers.removeItem();
    }

    if (framesCounter >= 30) {

        //Colision trampas
        if (CheckCollisionRecs(player.getRectangle(), enemy.getRectangle())) {
            player.removeHealth(1);
        }

        framesCounter = 0;
    }

    //Colision exit zone
    if (CheckCollisionRecs(player.getRectangle(), game[actualLevel].getRectangle())) {
        std::cout << "\nNivel antes: " << actualLevel;
        actualLevel >> actualLevel;
        std::cout << "\nNivel despues: " << actualLevel;
        player.setCurrentPosX(100);
    }

}