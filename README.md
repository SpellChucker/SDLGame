[![Build Status](https://travis-ci.org/SpellChucker/SDLGame.svg?branch=master)](https://travis-ci.org/SpellChucker/SDLGame)

Attempting to create a game in SDL2.

To build, ensure you have `SDL2`, `SDL2_image`, `SDL2_ttf` installed then perform the following:

```
$ mkdir build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Debug ..
$ make
$ make install
```

The executable will now be under /bin so you can run it from the root directory like:

```
$ bin/SDLGame
```
