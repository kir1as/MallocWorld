//
// all display fonction
//
// Created by William Lin on 18/10/2021.
//

#include <stdio.h>
#include "prototypes.h"

void displayMap(Map* map){
    int i = 0 ;
    int j = 0 ;
    for( i = 0 ; i < map->row ; i++ ){
        for( j = 0 ; j < map->column ; j++ ){
            printf("%3d",map->map[i][j]);
        }
        printf("\n");
    }
}

void displayActualMap(Map* map1,Map* map2,Map* map3, int actualZone){
    if(actualZone == 1){
        displayMap(map1);
    }else if(actualZone == 2){
        displayMap(map2);
    }else{
        displayMap(map2);
    }
}

void displayPlayer(Player *player){
    int i = 0;
    printf("--- PLAYER STATS ---\nlevel : %d\nexp :%d/\nhp : %d/%d\n"
           "--------------------\n",player->level,player->exps,player->hpNow,player->hpMax);
    printf("--- INVENTORY ---\n");
    for( i = 0 ; i < 10 ; i++ ){
        printf("id : %2d, quantity : x%02d, durability : %3d\n",player->inventory[i].id,
               player->inventory[i].quantity,player->inventory[i].durability);
    }
}
