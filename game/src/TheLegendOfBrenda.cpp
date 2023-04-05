#include "raylib.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Mover circulo al hacer clic");

    const float circleRadius = 25.0f;
    Vector2 circlePosition = { (float)screenWidth / 2, (float)screenHeight / 2 };
    const float circleSpeed = 0.1f;

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
            if (circlePosition.x < clickPosition.x) circlePosition.x += circleSpeed;
            else if (circlePosition.x > clickPosition.x) circlePosition.x -= circleSpeed;

            if (circlePosition.y < clickPosition.y) circlePosition.y += circleSpeed;
            else if (circlePosition.y > clickPosition.y) circlePosition.y -= circleSpeed;

            // Si el círculo está cerca de la posición del clic, detener el movimiento y restablecer la variable de movimiento
            if (CheckCollisionCircles(circlePosition, circleRadius, clickPosition, 0.1f)) {
                isMoving = false;
            }
        }

        // Dibujar el círculo en su posición actual
        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawCircleV(circlePosition, circleRadius, MAROON);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
