#include <iostream>
#include <string>
#include <vector>
#include <windows.h>

class Weapon {
public:
    std::string name;
    int compatible_material;
    std::string success_text;
    std::string failure_text;

};


int main() {
    SetConsoleOutputCP(CP_UTF8);

    Weapon hammer;
    hammer.name = "Le marteau de Thorin";
    hammer.compatible_material = 1;
    hammer.success_text = "Tes bras de roche s'emboite avec le manche.";
    hammer.failure_text = "tes bras fléchissent. le marteau est trop lourd";


    Weapon double_dagger;
    double_dagger.name = "Les Doubles Dagues de Vespera";
    double_dagger.compatible_material = 2;
    double_dagger.success_text = "Les dagues se fondent dans tes mains de brume. Tu es l'ombre elle-même.";
    double_dagger.failure_text = "Les dagues glissent et s'entrechoquent maladroitement.";


    Weapon katana;
    katana.name = "Le Katana de Kagemitsu";
    katana.compatible_material = 3;
    katana.success_text = "Le katana résonne avec ton corps d'acier. Le tranchant est parfait.";
    katana.failure_text = "Ta structure ne supporte pas la rigueur du katana.";

    std::cout << "Arme créée : " << katana.name << std::endl;

    Weapon bow;
    bow.name = "L'arc d'alistair";
    bow.compatible_material = 4;
    bow.success_text = "L'arc s'illumine. Tes doigts d'éther tracent des flèches de lumière";
    bow.failure_text = "Tu n'arrives pas à bander la corde, tes mains passent à travers.";


    std::vector<Weapon> weapons;
    weapons.push_back(hammer);
    weapons.push_back(double_dagger);
    weapons.push_back(katana);
    weapons.push_back(bow);

    int player_material = 0;
    std::cout << "De quelle matière est faite ton enveloppe ?" << std::endl;
    std::cout <<"1. Roche  2. Brume  3. Acier  4. Éther" << std::endl;
    std::cout << "Ton choix (1-4) : ";
    std::cin >> player_material;
    std::cout << std::endl;

    bool weapon_equipped = false;

    while (!weapon_equipped) {
        std::cout << "--- Les Reliques au sol ---" << std::endl;
        for (int i = 0; i < weapons.size(); i++) {
            std::cout << (i + 1) << ". " << weapons[i].name << std::endl;
        }

        int weapon_choice = 0;
        std::cout << "Quelle arme essaies-tu de ramasser ? (1-4) : ";
        std::cin >> weapon_choice;
        std::cout << std::endl;

        Weapon chosen_weapon = weapons[weapon_choice - 1];

        if (chosen_weapon.compatible_material == player_material) {
            std::cout << "[Succès] " << chosen_weapon.success_text << std::endl;
            weapon_equipped = true;
        } else {
            std::cout << "[Échec] " << chosen_weapon.failure_text << std::endl;
        }

        std::cout << std::endl;
    }

    std::cout << "L'aventure commence vraiment..." << std::endl;
    return 0;
    
}