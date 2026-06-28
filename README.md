# Elemics

A 2D metroidvania built from scratch in C++ with raylib.

## Concept

You wake up as a faceless, empty shell guided by a mysterious spirit. Before you
can move forward, you must choose the **material** your body is made of. Each
material defines a fighting style and which weapon you can actually wield.

Four legendary warriors died in this place and left their weapons behind. You can
try to pick up any of them, but only the weapon that matches your material can be
used — try the wrong one and your body won't be able to handle it.

| Material | Weapon | Style |
|----------|--------|-------|
| Steel    | Katana (Kagemitsu)        | Precision, timing, counter-attacks |
| Mist     | Twin daggers (Vespera)    | Speed, agility, fast combos |
| Rock     | War hammer (Thorin)       | Brute force, crowd control, tankiness |
| Ether    | Spirit bow (Alistair)     | Ranged combat, mobility, zone control |

There is also a **base form** (the empty grey shell) before any material is chosen.

**Powers** (double jump, dash, etc.) are unlocked by defeating bosses — for example,
beating the first boss grants the double jump.

Design direction: **no music**. Sound design carries the atmosphere instead.

## Tech stack

- **Language:** C++
- **Library:** [raylib](https://www.raylib.com/) 5.5
- **Toolchain:** MSYS2 (UCRT64) + g++
- **Editor:** VS Code

---

## Setting up on a new PC (full install)

Follow these steps to rebuild the whole environment from scratch on Windows.

### 1. Install MSYS2

1. Download the installer from <https://www.msys2.org> (the `x86_64` version for
   Intel/AMD PCs; the `arm64` version only for ARM machines).
2. Run it and keep the default install folder (`C:\msys64`).
3. At the end, let it open the **MSYS2 UCRT64** terminal (the one labelled UCRT64 —
   not MSYS or MINGW64).

### 2. Update MSYS2

In the **UCRT64** terminal:

```
pacman -Syu
```

If it closes the terminal at the end (normal), reopen **MSYS2 UCRT64** and run it
once more:

```
pacman -Syu
```

### 3. Install the compiler, CMake and raylib

```
pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-cmake mingw-w64-ucrt-x86_64-raylib
```

Confirm with `Y` when asked.

### 4. Add MSYS2 to the Windows PATH

So `g++` works from VS Code and any terminal:

1. Windows menu → search "environment variables" → **Edit the system environment
   variables**.
2. Click **Environment Variables…**
3. Under **User variables**, select `Path` → **Edit** → **New**, and add:
   ```
   C:\msys64\ucrt64\bin
   ```
4. **OK** on all windows. Restart VS Code so it picks up the new PATH.

### 5. Check it works

In a new terminal:

```
g++ --version
```

A version number means the toolchain is ready.

### 6. VS Code

- Install the **C/C++** extension by Microsoft.
- Open the project folder (`File → Open Folder`).

### 7. Get the project

```
git clone https://github.com/rinit44/metroidvania.git
cd metroidvania
```

---

## Build & run

From the project root:

```
mkdir build
g++ src/main.cpp -o build/jeu.exe -lraylib
./build/jeu.exe
```

> The `build/` folder is ignored by Git, so it won't exist after a fresh clone —
> create it once with `mkdir build`.
>
> If linking ever fails with "undefined reference" errors, use the full link line:
> ```
> g++ src/main.cpp -o build/jeu.exe -lraylib -lopengl32 -lgdi32 -lwinmm
> ```

## Controls

| Key   | Action     |
|-------|------------|
| A / D | Move left / right |
| Space | Jump (only when grounded) |

## Progress

Done:
- raylib window and game loop (60 FPS)
- Player movement (WASD)
- Gravity and jumping
- Screen boundary clamping
- Platform collision (land from above)

Next:
- Platform class + vector (multiple platforms)
- Camera following the player
- Bringing the weapon system into the graphical world
- Enemies and the first boss (double jump unlock)

## Project structure

- `src/` — source code
  - `main.cpp` — game entry point and main loop
  - `core/`, `entities/`, `world/`, `systems/` — reserved for future modules
- `assets/` — sprites, sounds, fonts, maps
- `build/` — compiled output (ignored by Git)