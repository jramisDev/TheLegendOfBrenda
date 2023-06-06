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

Player player;
//CharacterBase enemy = CharacterBase();
Item aidKit;

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
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);

    levelUI = LoadTexture("resources/UI/level.png");
    heartUI = LoadTexture("resources/UI/heartUI.png");

    playerImg = LoadTexture("resources/Player/player_right.png");
    enemyImg = LoadTexture("resources/Player/player_left.png");

    aidKitImg = LoadTexture("resources/Item/aidKit.png");
    keyImg = LoadTexture("resources/Item/key.png");

    game = LevelData();
    player = Player(playerImg);
    //enemy = CharacterBase(enemyImg);
    aidKit = Item(aidKitImg);

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

    Vector2 movement;
    movement.x = 0;
    movement.y = 0;

    if (IsKeyDown(KEY_A)) {
        if (player.getCurrentPos().x >= 2)  movement.x = -1;
    }
    if (IsKeyDown(KEY_D)) {
        if (player.getCurrentPos().x <= 698) movement.x = 1;
    }
    if (IsKeyDown(KEY_W)) {
        if (player.getCurrentPos().y >= 2) movement.y = -1;
    }
    if (IsKeyDown(KEY_S)) {
        if (player.getCurrentPos().y <= 385) movement.y = 1;
    }
    player.movePalyer(movement);



    player.drawUI();
    aidKit.drawItem();
    player.drawPlayer();

    if (CheckCollisionCircleRec(player.getCurrentPos(), player.getRadius(), aidKit.getRectangle())) {
        player.addHealth();
        player.addExp(aidKit.getExp());
        aidKit.removeItem();    
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