# 🎮 CPP - Arcadia

A small collection of classic games and visualizations built with **[raylib](https://github.com/raysan5/raylib)**:

| Folder | Game / Demo |
| ------ | ----------- | 
| `pong/` | Pong | 
| `snake/` | Snake | 
| `tetris/` | Tetris | 
| `conways‑game‑of‑life/` | Conway’s Game of Life | 

All four projects share the same toolchain and build together with **CMake** into a single `build/bin/` directory.


## ✨ Features

- **Cross‑platform** (Linux, macOS, Windows) – anything raylib supports
- **One‑command build** via CMake ≥ 3.15  
- Organized source / header layout per game
- TrueType fonts included in `fonts/`
- Simple to extend – drop another game folder, add one line to the top‑level `CMakeLists.txt`


## 📦 Dependencies

| Dependency | Minimum Version | Install Guide |
|------------|-----------------|---------------|
| **raylib** | 4.0 (tested with 4.5) | <https://github.com/raysan5/raylib/> |
| **CMake**  | 3.15            | <https://cmake.org/download/> |
| **C++ 17 compiler** | g++ 10 / clang++ 12 / MSVC 19.3 | via your OS package manager or IDE |


## 🚀 Quick‑start (build everything)

- Clone this Github repository 

``` bash
git clone https://github.com/ethereumvd/cpp-arcadia.git
cd cpp-arcadia
```

- Create a fresh build directory
```bash
rm -rf build
mkdir build
cd build
```

- Compile using CMake
```bash
cmake ..
cmake --build . 
```

- Run a game
```bash
./bin/pong          # or game / snake / tetris
```
