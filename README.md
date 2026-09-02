# ❌⭕ Tic Tac Toe — C Console Game

A two-player Tic Tac Toe game that runs in the terminal, written in plain C.
It comes with a small menu, a clean board, and proper win/draw detection.

Built as a practice project to get comfortable with arrays, functions,
and game logic in C.

---

## Features

- Two players on the same keyboard (X and O)
- Simple 1–9 numbered board for moves
- Main menu with Start, How to Play, and Exit
- Win check for all rows, columns, and diagonals
- Draw check when the board fills up
- Handles invalid moves (taken spot or wrong number)
- Replay without restarting the program

## Requirements

- A C compiler (GCC works fine)
- Any terminal (CMD, PowerShell, or Linux/Mac terminal)

## How to Compile and Run
```bash
gcc main.c -o tic-tac-toe
```
Then run it:

```bash
./tic-tac-toe      # Linux / Mac
tic-tac-toe.exe    # Windows
