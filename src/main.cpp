#include "raylib.h"

int main() {
    // Dimensions de la fenêtre
    int screenWidth = 800;
    int screenHeight = 600;

    // On ouvre la fenêtre
    InitWindow(screenWidth, screenHeight, "Mon Metroidvania");

    // Limite à 60 images par seconde
    SetTargetFPS(60);

    // === LA BOUCLE DE JEU ===
    // Tourne tant que le joueur ne ferme pas la fenêtre
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK); // fond noir
        EndDrawing();
    }

    // On ferme proprement la fenêtre à la fin
    CloseWindow();

    return 0;
}