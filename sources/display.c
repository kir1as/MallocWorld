//
// all display fonction
//
// Created by William Lin on 18/10/2021.
//

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

void chdirForMacUser(char *array){
    int i = 0;
    while(array[i] !=  '\0'){
        i++;
    }
    while(array[i] != '/'){
        array[i]=' ';
        i--;
    }
    array[i]='\0';
    chdir(array);
}

void clear_screen(void){
    system("clear||clr");
}

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
        displayMap(map3);
    }
}

int getExpMax(Player *player){
    int i = 0;
    int j = 0;
    for( i = 1 ; i <= 10 ; i++){
        if(player->level == i){
            return 100+j;
        }
        if( i <= 3 ){
            j += 50;
        }else if( i<=7 ){
            j += 150;
        }else{
            j += 2000;
        }
    }
    return 0;
}

void displayPlayer(Player *player){
    int i = 0;
    printf("--- PLAYER STATS ---\nlevel : %d\nexp :%d/%d\nhp : %d/%d\n"
           "--------------------\n",player->level,player->exps, getExpMax(player),
           player->hpNow,player->hpMax);
    printf("--------------------------------- INVENTORY --------------------------------\n");
    for( i = 0 ; i < 10 ; i++ ){
        printf("id : %2d, quantity : x%02d, name : %26s, durability : %3d\n",player->inventory[i].id,
               player->inventory[i].quantity, player->inventory[i].name, player->inventory[i].durability);
    }
    printf("----------------------------------------------------------------------------\n");
}

void displayInventory(Player *player){
    int i = 0;
    printf("--------------------------------- INVENTORY --------------------------------\n");
    for( i = 0 ; i < 10 ; i++ ){
        if(player->inventory[i].id != 0){
            printf(" %2d - quantity : x%02d, name : %26s, durability : %3d\n",i+1,
                   player->inventory[i].quantity, player->inventory[i].name, player->inventory[i].durability);
        }

    }
    printf("----------------------------------------------------------------------------\n");
}

void printLinkedList(RespawnCase* head){
    if(head != NULL){
        printf("------------\n counter : %d\n i : %d\n j : %d\n value : %d\n------------\n",head->counter,head->rowIndex,head->columnIndex,head->value);
        printLinkedList(head->next);
    }
}
