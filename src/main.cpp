#include "raylib.h"

int main() {
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Elemics");
    SetTargetFPS(60);

    float playerX = 400;
    float playerY = 300;
    float velocityY = 0;
    float gravity = 0.5;
    bool isOnGround = false;
    float platformX = 400;
    float platformY = 450;
    float platformWidth = 100;
    float platformHeight = 40;

    // === LA BOUCLE DE JEU ===
    while (!WindowShouldClose()) {

        // === INPUT HORIZONTAL ===
        if (IsKeyDown(KEY_D)) playerX = playerX + 5;
        if (IsKeyDown(KEY_A)) playerX = playerX - 5;

        // === SAUT (seulement si au sol) ===
        if (IsKeyPressed(KEY_SPACE) && isOnGround) {
            velocityY = -12;
        }

        // === GRAVITÉ ===
        velocityY = velocityY + gravity;
        playerY = playerY + velocityY;
        float playerBottom = playerY + 60;   // les pieds
        float playerRight = playerX + 40;    // le bord droit

        // === SOL ===
        if (playerY > 500) {
            playerY = 500;
            velocityY = 0;
            isOnGround = true;
        } else {
            isOnGround = false;
        }
        
        // === Bloquer le joueur à gauche et à droite ===
        if (playerX < 0) {
            playerX = 0;
        }
        if (playerX > 760) {
            playerX = 760;
        }
          // === COLLISION PLATEFORME ===
        if (playerRight > platformX &&
            playerX < platformX + platformWidth &&
            playerBottom > platformY &&
            velocityY > 0) {
            playerY = platformY - 60;
            velocityY = 0;
            isOnGround = true;
        }

        // === DESSIN ===
        BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangle(playerX, playerY, 40, 60, BLUE); // joueur
            DrawRectangle(0, 560, 800, 40, GRAY); // sol
            DrawRectangle(platformX, platformY, platformWidth, platformHeight, GREEN); // plateforme
        EndDrawing();

    }

    CloseWindow();
    return 0;
}