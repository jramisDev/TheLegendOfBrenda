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

#include "raylib.h"
#include "Init.h"
#include "LevelData.h"
#include "CharacterBase.h"
#include "Player.h"
#include "Item.h"

LevelData game;

Player player = Player();
Item aidKit1 = Item(1);

int main() {    

    initApp();

    while (globalRunning) {

        if (WindowShouldClose()) globalRunning = false;

        BeginDrawing();

        ClearBackground(RAYWHITE);

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

    game = LevelData();

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);

    levelUI = LoadTexture("resources/UI/level.png");
    heartUI = LoadTexture("resources/UI/heartUI.png");

    playerImg = LoadTexture("resources/Player/player_right.png");

}

void mainScreen() {

    DrawRectangle(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, RAYWHITE);
    DrawText(GAME_TITLE, 200, 100, 40, RED);
    DrawText("PRESS ENTER to GAME", 225, 140, 20, DARKBLUE);

    DrawText("CONTROLS:", 225, 180, 20, BLACK);
    DrawText("LEFT MOUSE button to MOVE to LOCATION", 225, 200, 15, BLACK);
    DrawText("PRESS I key OP CUSTOM player", 225, 225, 15, BLACK);

    if (IsKeyDown(KEY_ENTER)) game.setScreenActual(PLAYER);

}

void gameScreen() {

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        clickPosition = GetMousePosition();
        player.setIsMoving(true);
    }

    if (IsKeyDown(KEY_I)) game.setScreenActual(PLAYER);

    if (player.getIsMoving()) player.movePalyer(clickPosition);

    player.drawUI();
    aidKit1.drawItem();


    player.drawPlayer();

}

void playerScreen() {

    DrawText("PLAYER SCREEN", 150, 150, 40, GREEN);
    DrawText("PRESS SPACE to GAME", 250, 195, 20, DARKGREEN);

    if (IsKeyDown(KEY_I)) game.setScreenActual(GAME);

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