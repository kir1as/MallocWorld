cmake_minimum_required(VERSION 3.20)
project(malloc_world C)

set(CMAKE_C_STANDARD 99)

add_executable(malloc_world main.c sources/game.c sources/initialization.c sources/prototypes.h sources/define.h sources/menu.c sources/new_game.c sources/display.c sources/structures.h sources/new_game.h sources/initialization.h sources/game.h sources/npc.c sources/npc.h sources/respawn.c sources/respawn.h sources/harvest.c sources/harvest.h sources/battle.c sources/battle.h sources/save.c sources/save.h)
