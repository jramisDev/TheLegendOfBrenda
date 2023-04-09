#pragma once

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400
#define GAME_TITLE "The Legend Of Brenda"

//Widget Health
#define WIDGET_POS_X 10
#define WIDGET_POS_Y 10
#define WIDGET_SIZE 40

enum Screens { MENU, PLAYER_STATUS, GAME, WIN, GAMEOVER };
enum Items { AIDKIT, ARMOR, DAMAGE_POTION, DAMAGE_SPEED, KEY };

//Background
Texture2D heartUI;


Vector2 clickPosition = { 0.0f, 0.0f };

Vector2 startCharacterPosition(bool isPlayer) {

    if (isPlayer) return Vector2{ 50, SCREEN_HEIGHT / 2 };
    else 
    return Vector2{ (float)GetRandomValue(50, SCREEN_WIDTH - 50), (float)GetRandomValue(50, SCREEN_HEIGHT - 50) };
}