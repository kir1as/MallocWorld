//
// Created by William Lin on 28/10/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototypes.h"
#include "define.h"
#include "harvest.h"
#include "save.h"


int getDurability(int id){
    if(id == 1 || id == 2 || id == 3 || id == 4 || id == 8 || id == 12 || id == 13
       || id == 14 || id == 19 || id == 23 || id == 24 || id == 25 || id == 30){
        return 10;
    }else if(id == 9 || id == 20 || id == 31){
        return 8;
    }else if(id == 10 || id == 21 || id == 32){
        return 5;
    }
    return 0;
}

void repairEquipment(Player* player){
    int i = 0;
    for( i = 0 ; i < 10 ; i++ ){
        player->inventory[i].durability = getDurability(player->inventory[i].id);
    }
}

char* getNameFromObjectID2(int id){
    switch(id){
        case 21: return "Marteau en fer";
        case 22: return "Plastron en fer";
        case 23: return "Pioche en fer";
        case 24: return "Serpe en fer";
        case 25: return "Hache en fer";
        case 26: return "Potion de vie II";
        case 27: return "Chene";
        case 28: return "Diamant";
        case 29: return "Chanvre";
        case 30: return "Epee en diamant";
        case 31: return "Lance en diamant";
        case 32: return "Marteau en diamant";
        case 33: return "Plastron en diamant";
        case 34: return "Potion de vie III";
    }
}

char* getNameFromObjectID1(int id){
    switch(id){
        case 0: return "";
        case 1: return "Epee en bois";
        case 2: return "Pioche en bois";
        case 3: return "Serpe en bois";
        case 4: return "Hache en bois";
        case 5: return "Sapin";
        case 6: return "Pierre";
        case 7: return "Herbe";
        case 8: return "Epee en pierre";
        case 9: return "Lance en pierre";
        case 10: return "Marteau en pierre";
        case 11: return "Plastron en pierre";
        case 12: return "Pioche en pierre";
        case 13: return "Serpe en pierre";
        case 14: return "Hache en pierre";
        case 15: return "Potion de vie I";
        case 16: return "Hetre";
        case 17: return "Fer";
        case 18: return "Lavande";
        case 19: return "Epee en fer";
        case 20: return "Lance en fer";
    }
}

int displayStorage(void){
    char line[255];
    int counter = 1;
    int tmp = 0;
    FILE *fp = fopen(SAVE_FILE_PATHNAME,"r");

    if(fp == NULL){
        printf("fichier de sauvegarde introuvable\n");
        return -1;
    }
    fgets(line,255,fp);
    while(strcmp(line, "-- STORAGE --\n") != 0 && strcmp(line, "-- STORAGE --") != 0 && feof(fp) == 0){
        fgets(line,255,fp);
    }
    printf("---- COFFRE ----\n");
    while(feof(fp) == 0){
        if(fgets(line,255,fp) != NULL){
            if(line[0] == '{'){
                printf(" %d - %dx ",counter,atoi(strtok(line,"@")+1));
                tmp = atoi(strtok(NULL,"@")+1);
                printf("%s \n", tmp<=20?getNameFromObjectID1(tmp):getNameFromObjectID2(tmp));
                counter += 1;
            }
        }
    }
    printf("----------------\n");
    fclose(fp);
    return counter;
}

int getStackableResources(int id){
    if(id == 5 || id == 6 || id == 7 || id == 16 || id == 17 || id == 18
       || id == 27 || id == 28 || id == 29){
        return 1;
    }
    return -1;
}

void appendItemInventory(Player* player, int harvestQuantity, int value){
    int i = 0;
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

void withdrawItemFromStorage(Player* player, int idWithdraw){
    char line[255];
    int counter = 1;
    int i = 0;
    int withdrawQnt = 0;
    int withdrawedItemId = 0;
    FILE *fp = fopen(SAVE_FILE_PATHNAME,"r");
    FILE *fpTmp = fopen("save2.txt","w+");
    if(fp == NULL){
        printf("fichier de sauvegarde introuvable\n");
        return;
    }else if(fpTmp == NULL){
        printf("impossible de creer un fichier de sauvegarde temporaire\n");
        return;
    }
    fgets(line,255,fp);
    fputs(line,fpTmp);
    while(strcmp(line, "-- STORAGE --\n") != 0 && strcmp(line, "-- STORAGE --") != 0 && feof(fp) == 0){
        fgets(line,255,fp);
        fputs(line,fpTmp);
    }
    while(feof(fp) == 0 && strcmp(line,"")!=0){
        if(fgets(line,255,fp) != NULL){
            if(line[0] == '{'){
                if(counter == idWithdraw){
                    withdrawQnt = atoi(strtok(line,"@")+1);
                    withdrawedItemId = atoi(strtok(NULL,"@")+1);
                    if(verifyInventorySpace(player, withdrawedItemId, withdrawQnt) == 1 && getStackableResources(withdrawedItemId) == 1){
                        stockHarvestedItem(player,withdrawQnt, withdrawedItemId);
                    }else if(verifyUniqueInventorySpace(player) == 1){
                        appendItemInventory(player,withdrawQnt, withdrawedItemId);
                    }else{
                        printf("Inventaire plein !\n");
                        fprintf(fpTmp,"{%d}@{%d}\n",withdrawQnt,withdrawedItemId);
                    }
                }else{
                    fputs(line,fpTmp);
                }
                counter += 1;
            }
        }
    }
    fclose(fp);
    fclose(fpTmp);
    renameNewFile();
}

void withdrawItem(Player* player){
    int storageSize = 0;
    int res = 0;
    printf("Saississer le numero de l'item que vous souhaitez retirer\n");
    storageSize = displayStorage();
    printf("Entrer :");
    scanf("%d",&res);
    cleanStdin();
    clear_screen();
    if(res >= 1 || res <= storageSize){
        withdrawItemFromStorage(player, res);
    }else{
        printf("Aucun item est relie a ce numero!\n");
    }
}

void appendItemInStorage(Player* player,int i){
    FILE *fp = fopen(SAVE_FILE_PATHNAME,"a");
    if(fp == NULL){
        printf("fichier de sauvegarde introuvable\n");
        return;
    }
    fprintf(fp,"{%d}@{%d}\n",player->inventory[i].quantity,player->inventory[i].id);
    fclose(fp);
    player->inventory[i].quantity = 0;
    player->inventory[i].id = 0;
    strcpy(player->inventory[i].name,"");
    player->inventory[i].durability = 0;
    printf("Depot reussi\n");
}

void appendResourceInStorage(Player* player,int i){
    int res = 0;
    FILE *fp = fopen(SAVE_FILE_PATHNAME,"a");
    if(fp == NULL){
        printf("fichier de sauvegarde introuvable\n");
        return;
    }
    printf("Saississer la quantiter de ressources a deposer \n");
    printf("Entrer :");
    scanf("%d",&res);
    cleanStdin();
    clear_screen();
    if(player->inventory[i].quantity < res || res < 1){
        printf("Deposer une valeur correct !\n");
    }else{
        fprintf(fp,"{%d}@{%d}\n",res ,player->inventory[i].id);
        fclose(fp);
        player->inventory[i].quantity -= res;
        printf("Depot reussi\n");
    }
}

void depositItem(Player* player){
    int res = 0;
    int i = 0;
    printf("Saississer le numero de l'item que vous souhaitez deposer\n\n");
    displayInventory(player);
    printf("Entrer :");
    scanf("%d",&res);
    cleanStdin();
    clear_screen();
    if(res >= 1 && res <= 10){
        if(player->inventory[res-1].id == 0){
            printf("Il n'y a rien a cet emplacement!\n");
            return;
        }else{
            if(getStackableResources(player->inventory[res-1].id) == 1){
                appendResourceInStorage(player,res-1);
            }else{
                appendItemInStorage(player, res-1);
            }
        }
    }else{
        printf("Aucun item est relie a ce numero!\n");
    }
}

void storage(Player* player){
    int menu = -1;
    while(menu != 3){
        printf(" 1 - Déposer un objet dans le coffre\n 2 - Retirer un objet du coffre\n 3 - Retour\n");
        printf("Entrer :");

        scanf("%d",&menu);
        cleanStdin();
        clear_screen();
        if(menu == 1){
            depositItem(player);
        }else if(menu == 2){
            withdrawItem(player);
        }else if(menu != 3){
            printf("Entrer une valeur correct !\n");
        }
    }
}

void npcMenu(Player* player){
    int menu = -1;
    printf("Bienvenue, Je suis le marchand qui ne prend pas d'argent, que puis-je faire pour vous ?\n");
    while(menu < 4 && menu >= -1){
        printf(" 1 - Réparer les équipements\n 2 - Stockage\n 3 - Crafter un objet\n 4 - Retour\n");
        printf("Entrer :");

        scanf("%d",&menu);
        cleanStdin();
        clear_screen();
        switch(menu){
            case 1: repairEquipment(player);
                break;
            case 2: storage(player);
                break;
            case 3: ;
                break;
        }
    }
}