#include "raylib.h"

int main() {
    // Dimensions de la fenêtre
    int screenWidth = 800;
    int screenHeight = 600;

    // On ouvre la fenêtre
    InitWindow(screenWidth, screenHeight, "Mon Metroidvania");

    // Limite à 60 images par seconde
    SetTargetFPS(60);

    // Position du joueur (rectangle)
    float playerX = 400;
    float playerY = 300;

    // === LA BOUCLE DE JEU ===
    // Tourne tant que le joueur ne ferme pas la fenêtre
    while (!WindowShouldClose()) {

        // === INPUT : on lit les touches (WASD) ===
        if (IsKeyDown(KEY_D)) playerX = playerX + 10;
        if (IsKeyDown(KEY_A)) playerX = playerX - 10;
        if (IsKeyDown(KEY_S)) playerY = playerY + 10;
        if (IsKeyDown(KEY_W)) playerY = playerY - 10;

        // === DESSIN ===
        BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangle(playerX, playerY, 40, 60, BLUE);
        EndDrawing();
    }

    // On ferme proprement la fenêtre à la fin
    CloseWindow();

    return 0;
}