#include "raylib.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 400
#define GAME_TITLE "The Legend Of Brenda"

//Widget Health
#define WIDGET_POS_X 10
#define WIDGET_POS_Y 10
#define WIDGET_HEIGHT 20
#define WIDGET_WIDTH 100

enum Screens { MENU, PLAYER_STATUS, GAME, WIN, GAMEOVER };
//enum Objects { AIDKIT  };

//Background
Texture2D heartUI;

class CharacterBase {

    unsigned char speed;
    unsigned char health;
    unsigned char damage;
    unsigned char armor;

public:
    CharacterBase() {
        speed = 2;
        health = 5;
        armor = 0;
        damage = 1;
    }

    char getSpeed() { return speed; }
    void setSpeed(char pSpeed) { speed = pSpeed; }

    char getHealth() { return health; }
    void setHealth(char pHealth) { health = pHealth; }

    char getArmor() { return armor; }
    void setArmor(char pArmor) { armor = pArmor; }

    char getDamage() { return damage; }
    void setDamage(char pDamage) { damage = pDamage; }


};

class Player:public CharacterBase{

    unsigned short experience;
    unsigned char level;

    Vector2 posHealthWidget;
    Vector2 sizeHealthWidget;

public:
    Player() {
        experience = 1;
        level = 1;
        posHealthWidget = { WIDGET_POS_X , WIDGET_HEIGHT };
        
    }

    void setExperience(short pExp) { experience += pExp; }
    char getLevel() { char level; }

    void drawUI() {

        heartUI = LoadTexture("resources/UI/heartUI.png");

        DrawTexture(heartUI, WIDGET_POS_X, WIDGET_POS_Y, WHITE);
    
    }



};

class Objects {

public:
    Objects ();

private:

};

Player player;

int main() {

    player = Player();

    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "The Legend Of Brenda");

    const float circleRadius = 25.0f;
    Vector2 circlePosition = { (float)SCREEN_WIDTH / 2, (float)SCREEN_HEIGHT / 2 };
    

    bool isMoving = false;
    Vector2 clickPosition = { 0.0f, 0.0f };

    while (!WindowShouldClose()) {
        // Detectar si se ha hecho clic en el botón izquierdo del ratón
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            // Obtener la posición del clic
            clickPosition = GetMousePosition();

            // Establecer la variable de movimiento en verdadero
            isMoving = true;
        }

        if (isMoving) {
            // Actualizar la posición del círculo gradualmente hacia la posición del clic
            if (circlePosition.x < clickPosition.x) circlePosition.x += player.getSpeed();
            else if (circlePosition.x > clickPosition.x) circlePosition.x -= player.getSpeed();

            if (circlePosition.y < clickPosition.y) circlePosition.y += player.getSpeed();
            else if (circlePosition.y > clickPosition.y) circlePosition.y -= player.getSpeed();

            // Si el círculo está cerca de la posición del clic, detener el movimiento y restablecer la variable de movimiento
            if (CheckCollisionCircles(circlePosition, circleRadius, clickPosition, 0.1f)) {
                isMoving = false;
            }
        }

        // Dibujar el círculo en su posición actual
        BeginDrawing();

        ClearBackground(RAYWHITE);

        DrawCircleV(circlePosition, circleRadius, MAROON);


        player.drawUI();


        EndDrawing();
    }

    CloseWindow();

    return 0;
}
