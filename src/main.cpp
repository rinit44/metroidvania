#include "raylib.h"
#include <vector>
#include <string>

// ===================================================================
//  TYPES
// ===================================================================

enum GameState{
    INTRO,
    WEAPON_ROOM,
    GAME
};

class Platform {
public:
    float x;
    float y;
    float width;
    float height;
};

// ===================================================================
//  PROGRAMME PRINCIPAL
// ===================================================================
int main() {

    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Elemics");
    SetTargetFPS(60);

    GameState gameState = INTRO;

    // --- Joueur ---
    float playerX = 400;
    float playerY = 300;
    float velocityY = 0;
    float gravity = 0.5;
    bool isOnGround = false;

    // --- Plateformes ---
    std::vector<Platform> platforms;

    Platform p1;
    p1.x = 400;
    p1.y = 465;
    p1.width = 100;
    p1.height = 40;
    platforms.push_back(p1);

    Platform p2;
    p2.x = 150;
    p2.y = 350;
    p2.width = 120;
    p2.height = 20;
    platforms.push_back(p2);

    Platform p3;
    p3.x = 400;
    p3.y = 300;
    p3.width = 120;
    p3.height = 30;
    platforms.push_back(p3);

    // --- Caméra ---
    Camera2D camera = { 0 };
    camera.target = (Vector2){ playerX, playerY };
    camera.offset = (Vector2){ 400, 300 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    // --- Dialogue du Gardien ---
    std::vector<std::string> guardianLines;
    guardianLines.push_back("Ainsi, une autre coquille vide s'eveille...");
    guardianLines.push_back("Tu ne sais ni qui tu es, ni ou tu vas.");
    guardianLines.push_back("Avance. Marche. Et ecoute ma voix.");
    guardianLines.push_back("Tu vas devoir faire un choix crucial pour le reste de ta vie.");

    int currentLine = 0;
    // --- Porte de l'intro ---
    float doorX = 1200;

    bool introDialogueDone = false;

    // ===============================================================
    //  BOUCLE DE JEU
    // ===============================================================
    while (!WindowShouldClose()) {

        // ===========================================================
        //  LOGIQUE
        // ===========================================================

        // ----- INTRO -----
        if (gameState == INTRO) {
            if (introDialogueDone) {
                if (IsKeyDown(KEY_D)) playerX = playerX + 2;
                if (IsKeyDown(KEY_A)) playerX = playerX - 2;
            }
            if (playerX > doorX - 40) {
                playerX = doorX - 40;
            }

            velocityY = velocityY + gravity;
            playerY = playerY + velocityY;

            if (playerY > 500) {
                playerY = 500;
                velocityY = 0;
            }

            if (IsKeyPressed(KEY_ENTER)) {
                if (currentLine < (int)guardianLines.size() - 1) {
                    currentLine = currentLine + 1;
                } else {
                    introDialogueDone = true;
                }
            }

            camera.offset = (Vector2){ 250, 400 };
            camera.target = (Vector2){ playerX, playerY };
        }

        // ----- JEU PRINCIPAL -----
        if (gameState == GAME) {


            if (IsKeyDown(KEY_D)) playerX = playerX + 5;
            if (IsKeyDown(KEY_A)) playerX = playerX - 5;

            if (IsKeyPressed(KEY_SPACE) && isOnGround) {
                velocityY = -12;
            }

            velocityY = velocityY + gravity;
            playerY = playerY + velocityY;

            float playerBottom = playerY + 60;
            float playerRight = playerX + 40;

            if (playerY > 500) {
                playerY = 500;
                velocityY = 0;
                isOnGround = true;
            } else {
                isOnGround = false;
            }

            for (int i = 0; i < (int)platforms.size(); i++) {
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

            camera.offset = (Vector2){ 400, 300 };
            camera.target = (Vector2){ playerX, playerY };
        }

        // ===========================================================
        //  DESSIN
        // ===========================================================
        BeginDrawing();
            ClearBackground(BLACK);

            // ----- INTRO -----
            if (gameState == INTRO) {
                BeginMode2D(camera);
                    DrawRectangle(-5000, 560, 10000, 400, (Color){ 20, 20, 20, 255 });
                    DrawRectangle(playerX, playerY, 40, 60, BLUE);
                    DrawRectangle(doorX + 60, -2000, 5000, 5000, (Color){ 10, 10, 12, 255 });
                    DrawRectangle(doorX, 440, 60, 120, (Color){ 80, 70, 90, 255 });
                EndMode2D();
                if (!introDialogueDone) {
                    DrawText("Le Gardien :", 50, 40, 20, GRAY);
                    DrawText(guardianLines[currentLine].c_str(), 50, 70, 20, WHITE);
                    DrawText("[Entree] pour continuer", 50, 550, 16, DARKGRAY);
                }
            }

            // ----- JEU PRINCIPAL -----
            if (gameState == GAME) {
                BeginMode2D(camera);
                    DrawRectangle(playerX, playerY, 40, 60, BLUE);
                    DrawRectangle(0, 560, 2000, 40, GRAY);
                    for (int i = 0; i < (int)platforms.size(); i++) {
                        DrawRectangle(platforms[i].x, platforms[i].y, platforms[i].width, platforms[i].height, GREEN);
                    }
                EndMode2D();
            }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}