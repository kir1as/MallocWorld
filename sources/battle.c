//
// Created by William Lin on 04/11/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "prototypes.h"
#include "battle.h"
#include "define.h"
#include "respawn.h"

void updateHpMax(Player* player){
    int hpMaxArray[] = {100,100,110,130,160,210,260,310,360,435,510};
    int i = 0;
    for( i = 1 ; i <= 10 ; i++ ){
        if(player->level == i){
            player->hpMax = hpMaxArray[i];
        }
    }
    player->hpNow = player->hpMax;
    printf("Vos point de vie ont ete regenerer au maximum!\n");
}

void getLevel(Player* player){
    int i = 0;
    int j = 0;
    for( i = 1 ; i <= 10 ; i++){
        if(player->level == i && player->exps >= 100+j){
            printf("Vous montez d'un niveau!\n");
            player->level += 1;
            player->exps -= (100+j);
            updateHpMax(player);
        }
        if( i <= 3 ){
            j += 50;
        }else if( i<=7 ){
            j += 150;
        }else{
            j += 2000;
        }
    }
}

int getWeaponDamage(int id){
    switch(id){
        case 1: return 1;
        case 8: return 2;
        case 9: return 3;
        case 10: return 4;
        case 19: return 5;
        case 20: return 7;
        case 21: return 10;
        case 30: return 10;
        case 31: return 15;
        case 32: return 20;
    }
}

int playerAttack(Player* player, Monster* monster, int weaponIndex){
    if(player->inventory[weaponIndex].durability == 0){
        printf("%s n'est plus utilisable!\n",player->inventory[weaponIndex].name);
        return -1;
    }
    monster->hp -= getWeaponDamage(player->inventory[weaponIndex].id);
    player->inventory[weaponIndex].durability -= 1;
    printf("%s a subi %d dégats!\n",monster->name, getWeaponDamage(player->inventory[weaponIndex].id) );
    if(monster->hp <= 0){
        printf("Vous gagnez %dexp pour avoir battu %s!\n",monster->exps,monster->name);
        player->exps += monster->exps;
        getLevel(player);
        return 1;
    }
    return 0;
}

int verifyArmor(Player* player){
    int i = 0;
    int max = 0;
    for( i = 0 ; i < 10 ; i++ ){
        if(player->inventory[i].id == 11 && 10 > max){
            max = 10;
        }else if(player->inventory[i].id == 22 && 20 > max){
            max = 20;
        }else if(player->inventory[i].id == 33 && 40 > max){
            max = 40;
        }
    }
    return max;
}

int monsterAttack(Player* player, Monster* monster){
    int mitigation = verifyArmor(player);
    int damageReceive = monster->damage - ((monster->damage * mitigation) / 100);
    player->hpNow -= damageReceive;
    printf("Vous avez subi %d dégats!\n", damageReceive);
    if(player->hpNow <= 0){
        printf("%s vous a tue!\nGAME OVER\n",monster->name);
        return -1;
    }
    return 0;
}

int escape(void){
    srand( time( NULL ) + rand()%100 );
    if(rand()%100 <= 29){
        printf("Fuite réussi !\n");
        return 1;
    }
    printf("Fuite impossible !\n");
    return 0;
}

void healPlayer(Player* player, int value){
    if(value == 15){
        player->hpNow += 30;
        printf("Potion de vie | utilisée\n");
    }else if(value == 26){
        player->hpNow += 80;
        printf("Potion de vie || utilisée\n");
    }else if(value == 34){
        player->hpNow += 200;
        printf("Potion de vie ||| utilisée\n");
    }
    if(player->hpNow > player->hpMax){
        player->hpNow = player->hpMax;
        printf("PV guéri au maximum\n");
    }
}

int heal(Player* player){
    int i = 0;
    int indexInventory = -1;
    int max = 0;
    for( i = 0 ; i < 10 ; i++ ) {
        if(player->inventory[i].id == 15 && player->inventory[i].id > max){
            max = 15;
            indexInventory = i;
        }else if(player->inventory[i].id == 26 && player->inventory[i].id > max){
            max = 26;
            indexInventory = i;
        }else if(player->inventory[i].id == 34 && player->inventory[i].id > max){
            max = 34;
            indexInventory = i;
        }
    }
    if(indexInventory != -1){
        healPlayer(player, max);
        player->inventory[indexInventory].id = 0;
        strcpy(player->inventory[indexInventory].name,"");
        player->inventory[indexInventory].quantity = 0;
        return 1;
    }
    printf("Aucune potion disponible dans l'inventaire!\n");
    return 0;
}

void displayWeapon(Player* player, int* hashmapInv){
    int i = 0;
    int counter = 1;
    printf("--- SELECTIONNER UNE ARME ---\n");
    for( i = 0 ; i < 10 ; i++){
        if(hashmapInv[i] != 0){

            printf(" %d - id : %d, name : %s, durabilité : %d\n",
                   counter,player->inventory[i].id,player->inventory[i].name,player->inventory[i].durability);
            counter++;
        }
    }
    printf("-----------------------------\n");
}

int verifyWeaponChoose(Player* player,int *hashmapInv, int value){
    int i = 0;
    int counter = 1;
    for( i = 0 ; i < 10 ; i++){
        if(hashmapInv[i] != 0){
            if(counter == value){
                printf("Vous avez choisie '%s', durabilité : %d pour le combat!\n",
                       player->inventory[i].name,player->inventory[i].durability);
                return i;
            }
            counter++;
        }
    }
    return -1;
}

int chooseWeapon(Player* player){
    int i = 0;
    int counter = 0;
    int weapon = -1;
    int hashmapInv[10] = {0};
    for( i = 0 ; i < 10 ; i++){
        if(player->inventory[i].id == 1 || player->inventory[i].id == 8
           || player->inventory[i].id == 9 || player->inventory[i].id == 10
           || player->inventory[i].id == 19 || player->inventory[i].id == 20
           || player->inventory[i].id == 21 || player->inventory[i].id == 30
           || player->inventory[i].id == 31 || player->inventory[i].id == 32){
            if(player->inventory[i].durability != 0){
                hashmapInv[i]= player->inventory[i].id;
                counter++;
            }
        }
    }
    if(counter == 0){
        printf("Il n'y a pas  d'arme dans l'inventaire !\n");
        weapon = -2;
    }else{
        displayWeapon(player,hashmapInv);
    }
    while(weapon == -1){
        printf("Entrer : ");
        scanf("%d",&weapon);
        cleanStdin();
        weapon = verifyWeaponChoose(player, hashmapInv, weapon);
        if(weapon == -1){
            printf("Veuillez selectionner une arme dans la liste !\n");
        }
    }
    return weapon;
}

void monsterCase( ListRespawnCase* list, Map* map, int upDown, int leftRight, int value){
    int i = 0;
    int j = 0;
    for( i = 0 ; i< map->row ; i++){
        for( j = 0 ; j < map->column ; j++){
            if(map->map[i][j] == 1){
                map->map[i+upDown][j+leftRight] = 0;
                appendRespawnCase(list->first, newRespawnCase(16, i+upDown, j+leftRight, value));
                return;
            }
        }
    }
}

int battle(Player* player, int monsterId){
    Monster* monster = malloc(sizeof(Monster));
    if(monster == NULL){
        printf("Erreur d'allocation memoire");
        return -2;
    }
    int menu;
    int weaponIndex = -1;
    getMonsterData(monsterId, monster);
    displayMonster(monster);
    weaponIndex = chooseWeapon(player);
    if(weaponIndex == -2){
        return -2;
    }
    printf("weaponIndex :%d\n",weaponIndex);
    int fighting = 0;
    while(fighting == 0){
        printf("--- MENU ---\n 1 - Attaquer\n 2 - Soigner\n 3 - Fuir\n------------\n");
        printf("Entrer : ");
        scanf("%d",&menu);
        cleanStdin();
        switch (menu) {
            case 1: if(playerAttack(player, monster, weaponIndex) == 1){
                        fighting = 1;
                    }else{
                        if(monsterAttack(player, monster) == -1){
                            fighting = -1;
                        }
                    }
                    break;
            case 2: if(heal(player) == 1) {
                        if(monsterAttack(player, monster) == -1){
                            fighting = -1;
                        }
                    }
                    break;
            case 3: if(escape()==1){
                        fighting = 2;
                    }else{
                        if(monsterAttack(player, monster) == -1){
                            fighting = -1;
                        }
                    }
                    break;
            default: printf("Entrer une touche valide !!!\n");
        }
    }
    getLevel(player);
    free(monster);
    return fighting;
}

void displayMonster(Monster* monster){
    printf("------ Monstre ------\n");
    printf(" id : %d\n name : %s\n hp : %d\n",monster->id,monster->name,monster->hp);
    printf("---------------------\n");
}

void getMonsterData(int monsterId, Monster* monster){
    int i = 0;
    char line[255];

    FILE * fp = fopen("monsters.txt","r+");
    if(fp == NULL){
        printf("fichier de monstre introuvable\n");
        monster->id = -1;
        return ;
    }
    for( i = 0 ; i < monsterId - 12 ; i++ ){
        fgets(line,255,fp);
    }
    fgets(line,255,fp);
    monster->id = atoi(strtok ( line ,"@"));

    strcpy(monster->name,strtok ( NULL,"@"));
    monster->hp = atoi(strtok ( NULL,"@"));
    monster->damage = atoi(strtok ( NULL,"@"));
    monster->exps = atoi(strtok ( NULL,"@"));
}
