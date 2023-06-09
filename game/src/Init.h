#pragma once

#define FPS 60

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400
#define GAME_TITLE "The Legend Of Brenda"

//Widget Health
#define WIDGET_POS_X 5
#define WIDGET_POS_Y 5
#define WIDGET_SIZE 40

enum Screens { MENU, PLAYER, GAME, WIN };
enum Items { AIDKIT, SNEEKERS, KEY };
enum Mapas { FUERA_MURALLAS, MURALLAS, DENTRO_CASTILLO, SALA_TRONO };

//START - Textures

//Textures - Mappas
Texture2D mapaFueraMurallas;
Texture2D mapaMurallas;
Texture2D mapaDentroCastillo;
Texture2D mapaSalaTrono;

//Textures - UI
Texture2D heartUI;
Texture2D levelUI;

//Textures - Player
Texture2D playerImg;
Texture2D playerImpUp;
Texture2D playerImpDown;
Texture2D playerImpRight;
Texture2D playerImpLeft;

//Textures - Enemy
Texture2D trapImg;

//Tuextures - Items
Texture2D aidKitImg;
Texture2D keyImg;
Texture2D sneekersImg;

//END - Textures

int framesCounter = 0;

Screens actualScreen = GAME;
Mapas actualLevel = FUERA_MURALLAS;

//Variables ventana y mousePosition
bool globalRunning = true;
Vector2 clickPosition = { 0.0f, 0.0f };


static void initApp();

static void mainScreen();

static void gameScreen();

static void playerScreen();

static void endScreen();

static void checkCollisions();

static void dropItems();

static bool checkItemInMap(Items pItem);

static Vector2 startCharacterPosition() {
    return Vector2{ (float)GetRandomValue(300, SCREEN_WIDTH - 100), (float)GetRandomValue(50, SCREEN_HEIGHT - 50) };
}