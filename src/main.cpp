#include "raylib.h"
#include <vector>
#include <string>


// ===================================================================
//  TYPES (enum et classes)
// ===================================================================

// Les différents états (scènes) du jeu
enum GameState{
    INTRO,        // écran noir, le gardien parle, choix de l'élément
    WEAPON_ROOM,  // salle des armes, choix de l'arme
    GAME          // le jeu principal (plateformes, exploration)
};

// Une plateforme du jeu
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

    // --- Initialisation de la fenêtre ---
    int screenWidth = 800;
    int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Elemics");
    SetTargetFPS(60);

    // État de départ du jeu
    GameState gameState = INTRO;

    // --- Variables du joueur ---
    float playerX = 400;
    float playerY = 300;
    float velocityY = 0;
    float gravity = 0.5;
    bool isOnGround = false;

    // --- Création des plateformes ---
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

    // --- Caméra qui suit le joueur ---
    Camera2D camera = { 0 };
    camera.target = (Vector2){ playerX, playerY };   // point suivi (le joueur)
    camera.offset = (Vector2){ 400, 300 };           // affiché au centre de l'écran
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;

    // --- Dialogue du Gardien ---
    std::vector<std::string> guardianLines;
    guardianLines.push_back("Ainsi, une autre coquille vide s'eveille...");
    guardianLines.push_back("Tu ne sais ni qui tu es, ni ou tu vas.");
    guardianLines.push_back("Avance. Marche. Et ecoute ma voix.");
    guardianLines.push_back("Tu vas devoir faire un choix crucial pour le reste de ta vie.");

    int currentLine = 0;   // quelle phrase on affiche

    // ===============================================================
    //  BOUCLE DE JEU (tourne 60x par seconde)
    // ===============================================================
    while (!WindowShouldClose()) {

        // ===========================================================
        //  LOGIQUE (mise à jour de l'état du jeu)
        // ===========================================================

        // ----- ÉTAT : INTRO -----
        if (gameState == INTRO) {

            // Déplacement gauche / droite (marche lente)
            if (IsKeyDown(KEY_D)) playerX = playerX + 2;
            if (IsKeyDown(KEY_A)) playerX = playerX - 2;

            // Gravité (le perso marche sur le sol, il ne flotte pas)
            velocityY = velocityY + gravity;
            playerY = playerY + velocityY;

            // Sol invisible à y = 500
            if (playerY > 500) {
                playerY = 500;
                velocityY = 0;
            }
        // Passer à la phrase suivante avec Entrée
            if (IsKeyPressed(KEY_ENTER)) {
                if (currentLine < guardianLines.size() - 1) {
                    currentLine = currentLine + 1;
                }
            }

            // La caméra suit le joueur, décalé en bas à gauche
            camera.offset = (Vector2){ 250, 400 };
            camera.target = (Vector2){ playerX, playerY };
        }

        // ----- ÉTAT : JEU PRINCIPAL -----
        if (gameState == GAME) {

            // Déplacement gauche / droite
            if (IsKeyDown(KEY_D)) playerX = playerX + 5;
            if (IsKeyDown(KEY_A)) playerX = playerX - 5;

            // Saut (seulement si au sol)
            if (IsKeyPressed(KEY_SPACE) && isOnGround) {
                velocityY = -12;
            }

            // Gravité (le joueur tombe de plus en plus vite)
            velocityY = velocityY + gravity;
            playerY = playerY + velocityY;

            // Bords du joueur (calculés depuis le coin haut-gauche)
            float playerBottom = playerY + 60;   // les pieds
            float playerRight = playerX + 40;    // le bord droit

            // Collision avec le sol
            if (playerY > 500) {
                playerY = 500;
                velocityY = 0;
                isOnGround = true;
            } else {
                isOnGround = false;
            }

            // Collision avec toutes les plateformes
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

            // La caméra suit le joueur, centré
            camera.offset = (Vector2){ 400, 300 };
            camera.target = (Vector2){ playerX, playerY };
        }

        // ===========================================================
        //  DESSIN (affichage à l'écran)
        // ===========================================================
        BeginDrawing();
            ClearBackground(BLACK);

            // ----- DESSIN : INTRO -----
            if (gameState == INTRO) {
                BeginMode2D(camera);
                    // Sol très sombre, à peine visible dans le noir
                    DrawRectangle(-5000, 560, 10000, 400, (Color){ 20, 20, 20, 255 });
                    DrawRectangle(playerX, playerY, 40, 60, BLUE);   // le joueur
                EndMode2D();
                // Phrase actuelle du Gardien
                DrawText("Le Gardien :", 50, 40, 20, GRAY);
                DrawText(guardianLines[currentLine].c_str(), 50, 70, 20, WHITE);
                DrawText("[Entree] pour continuer", 50, 550, 16, DARKGRAY);
            }

            // ----- DESSIN : JEU PRINCIPAL -----
            if (gameState == GAME) {
                BeginMode2D(camera);   // tout ce qui suit défile avec la caméra
                    DrawRectangle(playerX, playerY, 40, 60, BLUE);       // joueur
                    DrawRectangle(0, 560, 2000, 40, GRAY);               // sol
                    for (int i = 0; i < platforms.size(); i++) {         // plateformes
                        DrawRectangle(platforms[i].x, platforms[i].y, platforms[i].width, platforms[i].height, GREEN);
                    }
                EndMode2D();           // fin de la zone caméra
            }

        EndDrawing();
    }

    // --- Fermeture propre ---
    CloseWindow();
    return 0;
}