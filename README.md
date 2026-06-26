# Metroidvania

Mon jeu en C++ avec raylib.

## Concept

Un metroidvania où le joueur incarne un personnage sans tête, guidé par un esprit.
Au début, l'esprit demande de choisir une **âme de guerrier** (4 choix), puis une **arme**
(marteau, double dagues, katana, arc). L'âme conditionne quelles armes sont réellement
maniables. Les **pouvoirs** (double saut, dash, etc.) se débloquent en battant des boss.

Parti pris : **pas de musique**, le sound design porte l'ambiance.

## Compilation

Projet prévu pour MSYS2 (UCRT64) + raylib.

```
# (instructions à compléter une fois le CMakeLists rempli)
```

## Structure

- `src/` — code source
  - `core/` — moteur du jeu (boucle principale)
  - `entities/` — joueur, boss, ennemis
  - `world/` — salles, carte
  - `systems/` — dialogue, son, et autres mécaniques transversales
- `assets/` — sprites, sons, polices, cartes
- `build/` — fichiers compilés (ignoré par Git)
