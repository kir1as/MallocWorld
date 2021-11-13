//
// List of Stucture
//
// Created by William Lin on 18/10/2021.
//

#ifndef MALLOC_WORLD_STRUCTURES_H
#define MALLOC_WORLD_STRUCTURES_H

#endif //MALLOC_WORLD_STRUCTURES_H

typedef struct Item{
    int id;
    int quantity;
    char name[30];
    int durability;
}Item;

typedef struct Player{
    int exps;
    int level;
    int hpNow;
    int hpMax;
    Item inventory[10];
}Player;

typedef struct Map{
    char **map;
    int row;
    int column;
}Map;

typedef struct RespawnCase{
    int counter;
    int rowIndex;
    int columnIndex;
    int value;
    struct RespawnCase* next;
}RespawnCase;

typedef struct ListRespawnCase{
    RespawnCase* first;
}ListRespawnCase;

typedef struct Monster{
    int id;
    char name[30];
    int hp;
    int damage;
    int exps;
}Monster;