# 🎮 Controls Guide
This document outlines keyboard and mouse input for every game in **CPP - Arcadia**

## 🧬 Conway's Game of Life

| Key / Mouse           | Action                       |
|-----------------------|------------------------------|
| **Left Mouse Click**  | Toggle individual cell       |
| **Enter**             | Start / resume simulation    |
| **Space**             | Pause simulation             |
| **→ Right Arrow**     | Increase simulation speed    |
| **← Left Arrow**      | Decrease simulation speed    |
| **↑ Up Arrow**        | Randomize all cells          |
| **↓ Down Arrow**      | Clear all cells              |

## 🧱 Tetris

| Key               | Action                 |
|-------------------|------------------------|
| **← Left Arrow**   | Move block left        |
| **→ Right Arrow**  | Move block right       |
| **↓ Down Arrow**   | Soft‑drop block        |
| **↑ Up Arrow**     | Rotate block           |
| **Any key after Game Over** | Restart game |

<details>
<summary>Known issue</summary>

Spamming correct combination of keys **within the same frame** can occasionally let the blocks to overlap into itself or other blocks.
</details>

## 🐍 Snake

| Key               | Action                                           |
|-------------------|--------------------------------------------------|
| **← Left Arrow**   | Turn left (ignored if moving right)              |
| **→ Right Arrow**  | Turn right (ignored if moving left)              |
| **↑ Up Arrow**     | Turn up (ignored if moving down)                 |
| **↓ Down Arrow**   | Turn down (ignored if moving up)                 |

<details>
<summary>Known issue</summary>

Spamming opposite‑direction keys **within the same frame** can occasionally let the snake reverse into itself. A simple debounce or movement‑queue would fix this.
</details>

## 🏓 Pong

| Key               | Action         |
|-------------------|----------------|
| **↑ Up Arrow**     | Move paddle up |
| **↓ Down Arrow**   | Move paddle down |


### General Notes
- All controls are mapped via Raylib key constants (`IsKeyPressed`, `GetKeyPressed`, etc.).
- Conway’s Game of Life additionally uses mouse clicks to edit cells.
