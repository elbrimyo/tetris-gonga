# Tetris Clone Game

This repository contains the source code for a Tetris clone game developed in C++ using the **Raylib** library. The game features fully functional Tetris gameplay, including block movement, rotation, scoring, and game-over detection.

---

## Features
- **Tetris Gameplay**: Blocks of various shapes fall, can be rotated, and align to clear rows.
- **Multiple Block Types**: Includes all classic Tetris block shapes (L, J, I, O, S, T, Z).
- **Dynamic Grid**: Blocks lock into place and cleared rows shift down.
- **Sound Effects**: Integrated sound effects for rotation and row clearing.
- **Score System**: Scoring based on rows cleared and block movement.

---

## File Structure
- **Block Management**:
  - `block.cpp` / `block.h`: Defines the `Block` class and its behavior (movement, rotation, etc.).
  - `blocks.cpp`: Specific block shapes (e.g., LBlock, JBlock, etc.).

- **Colors**:
  - `colors.cpp` / `colors.h`: Defines and assigns colors for different blocks.

- **Game Logic**:
  - `game.cpp` / `game.h`: Manages the game state, input handling, block spawning, and scoring.

- **Grid**:
  - `grid.cpp` / `grid.h`: Defines the game grid and handles row clearing and rendering.

- **Position**:
  - `position.cpp` / `position.h`: Represents individual grid positions.

- **Main**:
  - `main.cpp`: Entry point of the application. Sets up the game loop, window, and rendering.

---

## Prerequisites
- **C++ Compiler**: Make sure a modern C++ compiler is installed (e.g., g++, clang++).
- **Raylib Library**: Install the Raylib library for graphics and audio.

### Installing Raylib
For installation instructions, visit the [official Raylib installation guide](https://github.com/raysan5/raylib).

---

## How to Build and Run

1. Clone the repository:
   ```bash
   git clone https://github.com/elbrimyo/tetris-gonga.git
   cd tetris-gonga

2. Compile the code & run the game:
```bash
g++ -o tetris main.cpp game.cpp block.cpp blocks.cpp grid.cpp colors.cpp position.cpp -lraylib -std=c++17
./tetris
```

## Controls

- **Arrow Keys**:
  - **Left**: Move block left.
  - **Right**: Move block right.
  - **Down**: Move block down faster.
  - **Up**: Rotate block.
- **Restart**: Press any key to restart the game after failure.

## Scoring

Points are awarded based on the number of rows cleared simultaneously:
- **1 row**: 100 points
- **2 rows**: 300 points
- **3 rows**: 500 points

Additional points are granted for moving blocks down.

## Future Improvements

1. **Leaderboard Integration**: Implement a leaderboard to track high scores.
2. **Pause and Resume Functionality**: Allow players to pause and resume the game at any time.
3. **Save and Load Game State**: Enable saving and loading of game progress.
4. **Multiple Difficulty Levels**: Add adjustable difficulty levels to cater to various skill levels.


