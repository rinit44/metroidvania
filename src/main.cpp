#include "raylib.h"
#include <vector>

class Platform {
public:
    float x;
    float y;
    float width;
    float height;
};

int main() {
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Elemics");
    SetTargetFPS(60);

    // variable joueur
    float playerX = 400;
    float playerY = 300;
    float velocityY = 0;
    float gravity = 0.5;
    bool isOnGround = false;

    // variable plateforme
    std::vector<Platform> platforms;

    // Plateforme 1
    Platform p1;
    p1.x = 400;
    p1.y = 465;
    p1.width = 100;
    p1.height = 40;
    platforms.push_back(p1);

    // Plateforme 2
    Platform p2;
    p2.x = 150;
    p2.y = 350;
    p2.width = 120;
    p2.height = 20;
    platforms.push_back(p2);

    // Plateforme 3

    Platform p3;
    p3.x = 400;
    p3.y = 300;
    p3.width = 120;
    p3.height = 30;
    platforms.push_back(p3);

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

        // === COLLISION AVEC TOUTES LES PLATEFORMES ===
        for (int i = 0; i < platforms.size(); i++) {
            if (playerRight > platforms[i].x &&
                playerX < platforms[i].x + platforms[i].width &&
                playerBottom > platforms[i].y &&
                playerBottom < platforms[i].y + 20 &&
                velocityY > 0) {
                playerY = platforms[i].y - 60;
                velocityY = 0;
                isOnGround = true;
            }
        }
        

        // === DESSIN ===
        BeginDrawing();
            ClearBackground(BLACK);
            DrawRectangle(playerX, playerY, 40, 60, BLUE); // joueur
            DrawRectangle(0, 560, 800, 40, GRAY); // sol
            for (int i = 0; i < platforms.size(); i++) {
                DrawRectangle(platforms[i].x, platforms[i].y, platforms[i].width, platforms[i].height, GREEN);
            }
        EndDrawing();

    }

    CloseWindow();
    return 0;
}