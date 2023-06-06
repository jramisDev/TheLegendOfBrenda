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

#include "raylib.h"
#include "Init.h"
#include "LevelData.h"
#include "CharacterBase.h"
#include "Player.h"
#include "Item.h"

LevelData game;

Player player;
//CharacterBase enemy = CharacterBase();

//Items
Item aidKit;
Item accessKey;

int main() {    

    initApp();

    while (globalRunning) {

        if (WindowShouldClose()) globalRunning = false;

        BeginDrawing();

        ClearBackground(WHITE);

        switch (game.getScreenActual()) {
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

                endScreen(game.isGameOver());

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

    levelUI = LoadTexture("resources/UI/level.png");
    heartUI = LoadTexture("resources/UI/heartUI.png");

    playerImg = LoadTexture("resources/Player/player_right.png");
    playerImpUp = LoadTexture("resources/Player/player_up.png");
    playerImpDown = LoadTexture("resources/Player/player_down.png");
    playerImpRight = LoadTexture("resources/Player/player_right.png");
    playerImpLeft = LoadTexture("resources/Player/player_left.png");

    enemyImg = LoadTexture("resources/Player/player_left.png");

    aidKitImg = LoadTexture("resources/Item/aidKit.png");
    keyImg = LoadTexture("resources/Item/key.png");

    game = LevelData();
    player = Player(playerImg);
    //enemy = CharacterBase(enemyImg);
    aidKit = Item(aidKitImg);
    accessKey = Item(keyImg);

}

void mainScreen() {

    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, RAYWHITE);

    DrawText(GAME_TITLE, SCREEN_WIDTH / 2 - MeasureText(GAME_TITLE, 40) / 2, 100, 40, RED);
    DrawText("PRESS ENTER to GAME", SCREEN_WIDTH / 2 - MeasureText("PRESS ENTER to GAME", 20) / 2, 150, 20, DARKBLUE);

    DrawText("CONTROLS", SCREEN_WIDTH / 2 - MeasureText("CONTROLS", 20) / 2, 200, 20, BLACK);
    DrawText("LEFT MOUSE button to MOVE to LOCATION", SCREEN_WIDTH / 2 - MeasureText("LEFT MOUSE button to MOVE to LOCATION", 15) / 2, 225, 15, BLACK);
    DrawText("PRESS I key to CUSTOM player", SCREEN_WIDTH / 2 - MeasureText("PRESS I or SCPAES key OP CUSTOM player", 15) / 2, 250, 15, BLACK);
  
    if (IsKeyDown(KEY_ENTER)) game.setScreenActual(PLAYER);

}

void gameScreen() {

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        clickPosition = GetMousePosition();
        player.setIsMoving(true);
    }

    if (IsKeyDown(KEY_I)) game.setScreenActual(PLAYER);

    //Movimiento del personaje
    player.movePalyer();


    //Dibujamos elemento
    player.drawUI();
    aidKit.drawItem();
    accessKey.drawItem();
    player.drawPlayer();


    if (CheckCollisionCircleRec(player.getCurrentPos(), player.getRadius(), aidKit.getRectangle())) {
        player.addHealth();
        player.addExp(aidKit.getExp());
        aidKit.removeItem();    
    }



    if (CheckCollisionCircleRec(player.getCurrentPos(), player.getRadius(), accessKey.getRectangle())) {
        //player.addHealth();
        player.addExp(accessKey.getExp());
        accessKey.removeItem();
    }

}

void playerScreen() {

    DrawText("PLAYER SCREEN", SCREEN_WIDTH / 2 - MeasureText("PLAYER SCREEN", 40) / 2, SCREEN_HEIGHT / 2 - 40, 40, DARKGREEN);
    DrawText("PRESS SPACE or I to GAME", SCREEN_WIDTH / 2 - MeasureText("PRESS SPACE or I to GAME", 20) / 2, SCREEN_HEIGHT / 2, 20, DARKGREEN);

    if (IsKeyDown(KEY_I)) game.setScreenActual(GAME);
    if (IsKeyDown(KEY_SPACE)) game.setScreenActual(GAME);

    return;

}

void endScreen(bool isGameOver) {

    if (!game.isGameOver()) {
        DrawText("YOU WIN!", SCREEN_WIDTH / 2 - MeasureText("YOU WIN!", 40) / 2, SCREEN_HEIGHT / 2 - 40, 40, DARKGREEN);
    } else {
        DrawText("Game over!", SCREEN_WIDTH / 2 - MeasureText("Game over!", 40) / 2, SCREEN_HEIGHT / 2 - 40, 40, BLACK);
    }


    return;
}