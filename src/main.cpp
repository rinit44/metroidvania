#include <iostream>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int choixMatiere = 0;
    int choixArme = 0;
    bool armeValide = false; // Permet de contrôler la boucle de choix

    // --- INTRODUCTION ---
    std::cout << "..." << std::endl;
    std::cout << "Tu te reveilles. Tu n'as pas de visage." << std::endl;
    std::cout << "Une presence flotte autour de toi, sans forme, sans corps." << std::endl;
    std::cout << std::endl;
    std::cout << "L'Esprit : \"Qu'est donc ce réceptacle ? Sans nom, sans passé... vide.\"" << std::endl;
    std::cout << "L'Esprit : \"Une coquille oubliée dans les profondeurs de ce monde.\"" << std::endl;
    
    // --- PREMIER CHOIX : LA MATIÈRE ---
    std::cout << "L'Esprit : \"Dis-moi, de quelle matière est faite ton enveloppe ?\"" << std::endl;
    std::cout << "1. Une roche lourde et brute" << std::endl;
    std::cout << "2. Une brume sombre et fugitive" << std::endl;
    std::cout << "3. Un acier rigide et tranchant" << std::endl;
    std::cout << "4. Une essence d'éther légère" << std::endl;
    std::cout << "Ton choix (1-4) : ";
    std::cin >> choixMatiere;

    std::cout << std::endl;
    std::cout << "L'Esprit : \"Quatriens guerriers légendaires ont péri ici, laissant leurs reliques.\"" << std::endl;
    std::cout << "L'Esprit : \"Approche et tente de saisir ton destin... si ton corps le peut.\"" << std::endl;
    std::cout << std::endl;

    // --- BOUCLE DE CHOIX DE L'ARME ---
    while (!armeValide) {
        std::cout << "--- Les Reliques au sol ---" << std::endl;
        std::cout << "1. Le Katana de Kagemitsu" << std::endl;
        std::cout << "2. Les Doubles Dagues de Vespera" << std::endl;
        std::cout << "3. Le Marteau de Thorin" << std::endl;
        std::cout << "4. L'Arc d'Alistair" << std::endl;
        std::cout << "Quelle arme essaies-tu de ramasser ? (1-4) : ";
        std::cin >> choixArme;

        std::cout << std::endl;

        // --- VÉRIFICATION ---
        if (choixArme == 3) { // Le Marteau
            if (choixMatiere == 1) {
                std::cout << "[Succès] Tes bras de roche s'emboîtent parfaitement avec le manche du Marteau de Thorin." << std::endl;
                std::cout << "L'Esprit : \"Une force brute pour un corps de pierre. Brise ce monde.\"" << std::endl;
                armeValide = true; // On sort de la boucle
            } else {
                std::cout << "[Échec] Tu essaies de soulever le Marteau, mais tes bras fléchissent. Il est trop lourd." << std::endl;
                std::cout << "L'Esprit : \"Ce corps est bien trop fragile ou immatériel pour une telle masse... Essaie autre chose.\"" << std::endl;
            }
        } 
        else if (choixArme == 2) { // Les Dagues
            if (choixMatiere == 2) {
                std::cout << "[Succès] Les dagues de Vespera se fondent dans tes mains de brume. Tu es l'ombre elle-même." << std::endl;
                std::cout << "L'Esprit : \"Invisible et mortel. Danse parmi les morts.\"" << std::endl;
                armeValide = true;
            } else {
                std::cout << "[Échec] Les dagues glissent ou s'entrechoquent maladroitement." << std::endl;
                std::cout << "L'Esprit : \"Une telle agilité demande un corps plus insaisissable... Choisis une autre relique.\"" << std::endl;
            }
        }
        else if (choixArme == 1) { // Le Katana
            if (choixMatiere == 3) {
                std::cout << "[Succès] Le Katana de Kagemitsu résonne avec ton corps d'acier. Le tranchant est parfait." << std::endl;
                std::cout << "L'Esprit : \"La discipline et le métal. Ne fais qu'un avec ta lame.\"" << std::endl;
                armeValide = true;
            } else {
                std::cout << "[Échec] Ta structure physique ne supporte pas la tension et la rigueur du katana." << std::endl;
                std::cout << "L'Esprit : \"L'art du sabre demande une rigidité que tu ne possèdes pas... Regarde les autres armes.\"" << std::endl;
            }
        }
        else if (choixArme == 4) { // L'Arc
            if (choixMatiere == 4) {
                std::cout << "[Succès] L'Arc d'Alistair s'illumine. Tes doigts d'éther tracent des flèches de pure lumière." << std::endl;
                std::cout << "L'Esprit : \"L'énergie pure. Frappe tes ennemis avant même qu'ils ne t'aperçoivent.\"" << std::endl;
                armeValide = true;
            } else {
                std::cout << "[Échec] Tu n'arrives pas à bander la corde spirituelle, tes mains passent à travers." << std::endl;
                std::cout << "L'Esprit : \"Cet arc ne répond qu'à une essence purement spirituelle... Cherche encore.\"" << std::endl;
            }
        }
        else {
            std::cout << "Choix invalide. Cette relique n'existe pas." << std::endl;
        }

        std::cout << std::endl; // Ligne vide pour aérer le texte si on recommence
    }

    std::cout << "L'aventure commence vraiment..." << std::endl;

    return 0;
}