//
// Created by William Lin on 02/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "prototypes.h"
#include "respawn.h"
#include "npc.h"

int valueToHarvestItemId(int value){
    switch(value){
        case 3: return 3;
        case 4: return 2;
        case 5: return 4;
        case 6: return 13;
        case 7: return 12;
        case 8: return 14;
        case 9: return 24;
        case 10: return 23;
        case 11: return 25;
    }
}

int itemHarvested(int value){
    switch(value){
        case 3: return 7;
        case 4: return 6;
        case 5: return 5;
        case 6: return 18;
        case 7: return 17;
        case 8: return 16;
        case 9: return 29;
        case 10: return 28;
        case 11: return 27;
    }
}

//verifier la taille max de l inventaire et si il est stackable !!!
int verifyInventorySpace(Player* player, int value, int harvestQuantity){
    int i = 0;
    int counter = 0;
    for( i = 0 ; i < 10 ; i++){
        if(player->inventory[i].id == 0 || (player->inventory[i].id == value && (player->inventory[i].quantity+harvestQuantity) <= 20)){
            counter++;
        }
    }
    if(counter != 0){
        return 1;
    }
    return 0;
}

int verifyUniqueInventorySpace(Player* player){
    int i = 0;
    int counter = 0;
    for( i = 0 ; i < 10 ; i++){
        if(player->inventory[i].id == 0){
            counter++;
        }
    }
    if(counter != 0){
        return 1;
    }
    return 0;
}

int verifyHarvestItem(Player* player, int value, int minDurability){
    int i = 0;
    for( i = 0 ; i < 10 ; i++ ) {
        if(player->inventory[i].id == value && player->inventory[i].durability >= minDurability){
            player->inventory[i].durability -= minDurability;
            return 1;
        }
    }
    return 0;
}

void harvestedCase( ListRespawnCase* list, Map* map, int upDown, int leftRight, int value){
    int i = 0;
    int j = 0;
    for( i = 0 ; i< map->row ; i++){
        for( j = 0 ; j < map->column ; j++){
            if(map->map[i][j] == 1){
                map->map[i+upDown][j+leftRight] = 0;
                appendRespawnCase(list->first, newRespawnCase(11, i+upDown, j+leftRight, value));
                return;
            }
        }
    }
}

void stockHarvestedItem(Player* player, int harvestQuantity, int value){
    int i = 0;
    for( i = 0 ; i < 10 ; i++ ){
        if(player->inventory[i].id == value && (player->inventory[i].quantity+harvestQuantity) <= 20){
            player->inventory[i].quantity += harvestQuantity;
            printf("ajout a l'inventaire reussi!\n");
            return;
        }
    }

    for( i = 0 ; i < 10 ; i++ ){
        if(player->inventory[i].id == 0){
            player->inventory[i].id = value;
            player->inventory[i].quantity = harvestQuantity;
            player->inventory[i].durability = getDurability(value);
            strcpy(player->inventory[i].name,value<=20?getNameFromObjectID1(value):getNameFromObjectID2(value));
            printf("ajout a l'inventaire reussi!\n");
            return;
        }
    }
}

void harvest(Map* map, Player* player, ListRespawnCase* list, int value, int upDown,int leftRight){
    int minDurability = 0;
    int harvestQuantity = 0;
    srand( time( NULL ) + rand()%100 );
    harvestQuantity = (rand()%4)+1;

    if(value == 3 || value == 4 || value == 5){
        minDurability = 1;
    }else if(value == 6 ||value == 7 || value == 8){
        minDurability = 2;
    }else if(value == 9 || value == 10 || value == 11){
        minDurability = 4;
    }

    if(verifyInventorySpace(player, itemHarvested(value), harvestQuantity) == 1){
        if(verifyHarvestItem(player, valueToHarvestItemId(value), minDurability) == 1){
            harvestedCase(list, map, upDown, leftRight, value);
            stockHarvestedItem(player, harvestQuantity,itemHarvested(value));
        }else{
            printf("Outil indisponible !\n");
        }
    }else{
        printf("Inventaire plein !\n");
    }

}

