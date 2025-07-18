# Game Of Life - Raylib Implementation

A C++ implementation of **Conway’s Game of Life**, built using the [Raylib](https://www.raylib.com/) graphics library.

--- 

## Rules of the game
- Any live cell with fewer than two live neighbours dies, as if caused by underpopulation.
- Any live cell with two or three live neighbours lives on to the next generation.
- Any live cell with more than three live neighbours dies, as if by overpopulation.
- Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

Read more [here.](https://rustwasm.github.io/book/game-of-life/rules.html)

---

## Showcase

![GIF](gif/gif.gif)

---

## Requirements
- C++ Compiler (C++17 or later)
- Raylib 5.0+
- CMake 3.12+

---

## Clone & Build
```bash
git clone https://github.com/Stone-r1/game-of-life.git
cd gameOfLife
mkdir build
cd build
cmake ..
make
./gameOfLife
```
