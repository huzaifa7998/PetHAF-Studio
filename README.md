<div align="center">
░█████████  ░██████████ ░██████████░██     ░██    ░███    ░██████████
░██     ░██ ░██             ░██    ░██     ░██   ░██░██   ░██
░██     ░██ ░██             ░██    ░██     ░██  ░██  ░██  ░██
░█████████  ░█████████      ░██    ░██████████ ░█████████ ░█████████
░██         ░██             ░██    ░██     ░██ ░██    ░██ ░██
░██         ░██             ░██    ░██     ░██ ░██    ░██ ░██
░██         ░██████████     ░██    ░██     ░██ ░██    ░██ ░██

A console-based virtual pet simulator built in C++

https://img.shields.io/badge/C++-17-00599C?style=flat-square&logo=c%2B%2B&logoColor=white
https://img.shields.io/badge/Platform-Windows-0078D6?style=flat-square&logo=windows&logoColor=white
https://img.shields.io/badge/License-Open%20Source-brightgreen?style=flat-square
https://img.shields.io/badge/Status-Active-success?style=flat-square


</div>

## Overview

PetHAF Studio is a colorful terminal-based game where you adopt and care for one of seven unique animals. Feed them, play with them, keep them healthy, earn Pet Points (PP), and watch them age — all rendered in vivid ANSI color directly in your console.

Each animal has its own stat profile, unique inventory items, and a signature special ability. One wrong move and your pet could starve, get attacked by a predator, or simply grow old. Save your progress and pick up right where you left off.

---

## Pets

| Animal | Starting PP | Max Age | Signature Ability |
|--------|-------------|---------|-------------------|
| 😺 Cat | 150 | 40 | **Catnap** — restores mood and energy without a full sleep |
| 🐶 Dog | 150 | 35 | **Teach a Trick** — train Sit, Shake, or Roll Over for PP |
| 🐴 Horse | 200 | 50 | **Race** — compete to earn bonus PP |
| 🐦 Sparrow | 100 | 8 | **Sing** — boosts mood with a cheerful melody |
| 🦜 Parrot | 130 | 60 | **Teach to Talk** — input a phrase and hear it repeated |
| 🐰 Rabbit | 120 | 15 | **Binky** — joy jumps that spike mood, costs energy |
| 🐔 Hen | 90 | 10 | **Collect Eggs** — lay 1–4 eggs and sell them for PP |

> Special abilities require mood ≥ 50 to activate. Keep your pet happy.

---

## Gameplay

On each turn you choose one action from the main menu. Every action advances time, which depletes your pet's stats passively.

```
1  Feed             Use food from your inventory
2  Play             Use a toy; costs energy, boosts mood
3  Show Affection   Cuddle if mood ≥ 50; backfires when grumpy
4  Groom            Earns 15 PP and keeps your pet clean
5  Sleep            Restores full energy; earns 10 PP
6  Pet Special Ability  Trigger your animal's unique move
7  View Pet Health  Display live stat bars
8  Store            Buy items with PP
0  Quit             Save game and exit
```

### Stats

Each stat runs from 0 to 100. Every turn that passes depletes them automatically.

| Stat | Passive Drain per Turn | Consequence at 0 |
|------|------------------------|------------------|
| Hunger | −5 | Health begins dropping; pet dies |
| Mood | −2 | Pet becomes grumpy; affection backfires |
| Energy | −3 | Pet refuses to play |
| Health | — (no drain, but affected by hunger) | Pet dies |

### Predator Events

Every 4 age increments a predator attacks. You can pay **20 PP** to defend your pet — if you succeed, you're rewarded with **50 PP** and a mood boost. Declining (or having insufficient PP) costs −20 Health and −15 Mood.

---

## Inventory & Store

All pets start with five universal items. Each pet also has five unique items available in the store.

### Universal Items

| Item | Cost | Reusable | Category |
|------|------|----------|----------|
| Basic Food | 15 PP | No | Food |
| Premium Food | 20 PP | No | Food |
| Basic Medicine | 15 PP | No | Medicine |
| Premium Medicine | 20 PP | No | Medicine |
| Brush | 15 PP | Yes | Grooming |

### Pet-Specific Items (examples)

| Pet | Toys | Special Food | Grooming |
|-----|------|--------------|----------|
| Cat | Fake Mouse, Laser Toy, Feather Stick | Cat Nip | Cat Shampoo |
| Dog | Chewing Bone, Frisbee, Throwing Ball | Beef Treats | Dog Shampoo |
| Rabbit | Chew Wood, Small Plastic Tunnel | Carrot, Fresh Lettuce | Hair Groomer |
| Hen | Nesting Material, Fake Worms | Corn, Worms | Sand |

**Reusable items** (toys, tools) can be purchased once and used indefinitely. **Consumable items** deplete with each use and must be restocked from the store.

---

## Save System

Progress persists across three plain-text files stored alongside the executable:

| File | Contents |
|------|----------|
| `Save.txt` | Pet type, name, all four stats, age, alive status, max age |
| `Inventory.txt` | Item quantities for all 10 inventory slots |
| `User.txt` | Player first and last name |

On launch, the game detects whether an account already exists. New players are prompted to create one. Returning players can load their saved pet or start fresh with a new one.

---

## Project Structure

```
PetHAF_Studio/
│
├── PetHAF_Studio.cpp     # Entry point — main game loop, menus, load/save flow
│
├── Pet.h                 # Base Pet class: stats, feed, play, sleep, groom, affection,
│                         # time_pass, predator_attack, check_health
│
├── Basic Animals.h       # Derived animal classes (Cat, Dog, Horse, Sparrow,
│                         # Parrot, Rabbit, Hen) with unique items & abilities
│
├── Inventory.h           # Item struct, Inventory base class, display_inv(),
│                         # use_inv_f_play()
│
├── Store.h               # Inventory::purchase() and disp_store_inv() definitions
│
├── FileManager.h         # save_game() / load_game() — reads and writes
│                         # Save.txt and Inventory.txt
│
├── User.h                # User class: account creation, file I/O, isNewAccount()
│
├── Colours.h             # ANSI escape code macros (GREEN, CYAN, RESET, etc.)
│
├── logo.h                # ASCII art logo printed at startup
│
├── Save.txt              # Auto-generated on first save
├── Inventory.txt         # Auto-generated on first save
└── User.txt              # Auto-generated on account creation
```

### Class Hierarchy

```
Inventory
    └── Pet
            ├── Cat
            ├── Dog
            ├── Horse
            ├── Sparrow
            ├── Parrot
            ├── Rabbit
            └── Hen
```

`Pet` inherits from `Inventory` so every animal has direct access to its item slots and PP balance. Each animal overrides `special_ability()` and `pet_special_ability()`, which are declared pure virtual in `Pet`.

---

## Building & Running

### Requirements

- **OS:** Windows (the project uses `<windows.h>` and `SetConsoleOutputCP(CP_UTF8)`)
- **Compiler:** Any C++17-compatible compiler — MSVC, MinGW g++, or Clang
- **Terminal:** Windows Terminal is strongly recommended for full UTF-8 and ANSI colour support

### Build

**g++ (MinGW)**
```bash
g++ -std=c++17 -o PetHAF_Studio PetHAF_Studio.cpp
```

**MSVC**
```bash
cl /std:c++17 /EHsc PetHAF_Studio.cpp
```

### Run

```bash
./PetHAF_Studio
```

The three save files (`Save.txt`, `Inventory.txt`, `User.txt`) must be in the **same directory as the executable**. They are created automatically on first run — no manual setup needed.

> **Note:** The game relies heavily on ANSI escape codes and Unicode emoji for its colorful UI. If characters appear garbled, ensure your terminal is set to UTF-8 encoding.

---

## Roadmap

Planned improvements and open contribution areas:

- [ ] Cross-platform support — abstract away `<windows.h>` for Linux and macOS
- [ ] Additional pet types and expanded special ability trees
- [ ] Mini-games as an alternative PP-earning mechanic
- [ ] Random event system (weather, mood swings, surprise gifts)
- [ ] High-score / lifetime stats tracker
- [ ] Binary save format for smaller, more robust persistence

---

## Contributing

Contributions are welcome. To get started:

1. Fork the repository
2. Create a feature branch (`git checkout -b feature/your-feature`)
3. Commit your changes (`git commit -m "Add your feature"`)
4. Push to your branch (`git push origin feature/your-feature`)
5. Open a pull request

Please keep new code consistent with the existing style — ANSI output through `Colours.h`, input validation with `cin.fail()` guards, and virtual method overrides for any new pet types.
Make sure all the given files are present in one path or folder so that the main file could compile.

---

## License

This project is open source. You are free to use, modify, and distribute it.
