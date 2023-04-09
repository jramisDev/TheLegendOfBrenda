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
#include "CharacterBase.h"
#include "Player.h"
#include "Item.h"

Player player = Player();
Item aidKit1 = Item(1);

int main() {

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, GAME_TITLE);
       

    while (!WindowShouldClose()) {


        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            clickPosition = GetMousePosition();
            player.setIsMoving(true);
        }

        if (player.getIsMoving()) player.movePalyer(clickPosition);
        

        // Dibujar el círculo en su posición actual
        BeginDrawing();

        ClearBackground(RAYWHITE);

        //DrawCircleV(circlePosition, circleRadius, MAROON);

        player.drawUI();
        aidKit1.drawItem();


        player.drawPlayer();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
