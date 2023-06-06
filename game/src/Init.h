#pragma once

#define FPS 60

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400
#define GAME_TITLE "The Legend Of Brenda"

//Widget Health
#define WIDGET_POS_X 5
#define WIDGET_POS_Y 5
#define WIDGET_SIZE 40

enum Screens { MENU, PLAYER, GAME, END };
enum Items { AIDKIT, ARMOR, DAMAGE_POTION, DAMAGE_SPEED, KEY };

//START - Textures

//Textures - Background
Texture2D backgroundMain;
Texture2D backgroundGame;
Texture2D backgroundPlayer;
Texture2D backgroundWin;
Texture2D backgroundGameOver;

//Textures - UI
Texture2D heartUI;
Texture2D levelUI;

//Textures - Player
Texture2D playerImg;

//Textures - Enemy
Texture2D enemyImg;

//Tuextures - Items
Texture2D aidKitImg;
Texture2D keyImg;

//END - Textures

//Variables ventana y mousePosition
bool globalRunning = true;
Vector2 clickPosition = { 0.0f, 0.0f };


static void initApp();

static void mainScreen();

static void gameScreen();

static void playerScreen();

static void endScreen(bool isGameOver);

static Vector2 startCharacterPosition(bool isPlayer) {

    if (isPlayer) return Vector2{ 50, SCREEN_HEIGHT / 2 };
    else 
    return Vector2{ (float)GetRandomValue(50, SCREEN_WIDTH - 50), (float)GetRandomValue(50, SCREEN_HEIGHT - 50) };
}