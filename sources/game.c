//
// Created by William Lin on 18/10/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototypes.h"
#include "define.h"
#include "npc.h"
#include "game.h"

void cleanStdin(void){
    int c = 0;
    while(c != '\n' && c != EOF){
        c = getchar();
    };
}

int findPlayer(char **map, int rows, int column){
    int i = 0;
    int j = 0;
    for( i = 0 ; i < rows ; i++ ){
        for( j = 0 ; j < column ; j++ ){
            if(map[i][j] == 1){
                return 1;
            }
        }
    }
    return 0;
}

int getZone(Map* map1,Map* map2){
    if(findPlayer(map1->map, map1->row, map1->column) == 1){
        return 1;
    }else if(findPlayer(map2->map, map2->row, map2->column) == 1){
        return 2;
    }else{
        return 3;
    }
}

//faire des defines pour les valeurs;
int particularCase(int i, int j, int rows, int column){
    if( i == 0 && j == 0 ){
        return 1;
    }else if( i == 0 && j == column){
        return 2;
    }else if( i == rows && j == 0 ){
        return 3;
    }else if( i == rows && j == column ){
        return 4;
    }else if(i == 0){
        return 5;
    }else if(i == rows){
        return 6;
    }else if(j == 0){
        return 7;
    }else if(j == column){
        return 8;
    }
    return 0;
}

char *getTextFromMap(int value, int actualZone) {
    if (value == -3) {
        return "Entrer dans le portail -3";
    } else if (value == -2) {
        return "Entrer dans le portail -2";
    } else if (value == -1) {
        return "Déplacement impossible";
    } else if (value == 0) {
        return "Déplacement";
    } else if (value == 2) {
        return "Parlez au PNG";
    } else if (value == 3 + (actualZone - 1) * 3) {
        return "Couper la plante";
    } else if (value == 4 + (actualZone - 1) * 3) {
        return "Miner la roche";
    } else if (value == 5 + (actualZone - 1) * 3) {
        return "Abattre l'arbre";
    } else if (value >= 12 && value <= 98) {
        return "Combattre le monstre";
    } else if (value == 99) {
        return "Affronter le Boss Final";
    }
}



void printPlayerMenuCorner(int pCase,int value1, int value2, int actualZone){
    char displayMenu[200] = "--- MENU ---\n z : ";
    if(pCase == 1){
        strcat(displayMenu,getTextFromMap(value1,actualZone));
        strcat(displayMenu," en bas\n q : ");
        strcat(displayMenu,getTextFromMap(value2,actualZone));
        strcat(displayMenu," à droite\n");
    }else if(pCase == 2){
        strcat(displayMenu,getTextFromMap(value1,actualZone));
        strcat(displayMenu," en bas\n q : ");
        strcat(displayMenu,getTextFromMap(value2,actualZone));
        strcat(displayMenu," à gauche\n d : ");
    }else if(pCase == 3){
        strcat(displayMenu,getTextFromMap(value1,actualZone));
        strcat(displayMenu," en haut\n s : ");
        strcat(displayMenu,getTextFromMap(value2,actualZone));
        strcat(displayMenu," à droite\n");
    }else{
        strcat(displayMenu,getTextFromMap(value1,actualZone));
        strcat(displayMenu," en haut\n s : ");
        strcat(displayMenu,getTextFromMap(value2,actualZone));
        strcat(displayMenu," à gauche\n d : ");
    }
    printf("%s",displayMenu);
    printf(" i : Inventaire\n p : Sauvegarder\n m : Retour au menu principal\n------------\n");
}

void getStringPlayerMenu(char*  string1, char* string2, char* string3, char* string4,char* string5,char* string6){

}

void printPlayerMenuBorder(int pCase,int value1, int value2, int value3, int actualZone){
    char displayMenu[200] = "--- MENU ---\n z : ";
    if(pCase == 5){
        strcat(displayMenu,getTextFromMap(value1,actualZone));
        strcat(displayMenu," en bas\n q : ");
        strcat(displayMenu,getTextFromMap(value2,actualZone));
        strcat(displayMenu," à gauche\n d : ");
        strcat(displayMenu,getTextFromMap(value3,actualZone));
        strcat(displayMenu," à droite\n");
    }else if(pCase == 6){
        strcat(displayMenu,getTextFromMap(value1,actualZone));
        strcat(displayMenu," en haut\n s : ");
        strcat(displayMenu,getTextFromMap(value2,actualZone));
        strcat(displayMenu," à gauche\n d : ");
        strcat(displayMenu,getTextFromMap(value3,actualZone));
        strcat(displayMenu," à droite\n");
    }else if(pCase == 7){
        strcat(displayMenu,getTextFromMap(value1,actualZone));
        strcat(displayMenu," en haut\n s : ");
        strcat(displayMenu,getTextFromMap(value2,actualZone));
        strcat(displayMenu," en bas\n q : ");
        strcat(displayMenu,getTextFromMap(value3,actualZone));
        strcat(displayMenu," à droite\n");
    }else{
        strcat(displayMenu,getTextFromMap(value1,actualZone));
        strcat(displayMenu," en haut\n s : ");
        strcat(displayMenu,getTextFromMap(value2,actualZone));
        strcat(displayMenu," en bas\n q : ");
        strcat(displayMenu,getTextFromMap(value3,actualZone));
        strcat(displayMenu," à gauche\n d : ");
    }
    printf("%s",displayMenu);
    printf(" i : Inventaire\n p : Sauvegarder\n m : Retour au menu principal\n------------\n");
}

void printPlayerMenu(int up, int down, int left, int right, int actualZone){
    char displayMenu[200] = "--- MENU ---\n z : ";
    strcat(displayMenu,getTextFromMap(up,actualZone));
    strcat(displayMenu," en haut\n s : ");
    strcat(displayMenu,getTextFromMap(down,actualZone));
    strcat(displayMenu," en bas\n q : ");
    strcat(displayMenu,getTextFromMap(left,actualZone));
    strcat(displayMenu," à gauche\n d : ");
    strcat(displayMenu,getTextFromMap(right,actualZone));
    strcat(displayMenu," à droite\n");
    printf("%s",displayMenu);
    printf(" i : Inventaire\n p : Sauvegarder\n m : Retour au menu principal\n------------\n");
}

void fillMenu(int* zqsd, int up, int down, int left, int right){
    zqsd[0]=up;
    zqsd[1]=left;
    zqsd[2]=down;
    zqsd[3]=right;
}

void fillMenuAll(char **map, int i, int j, int pCase, int* zqsd){
     switch(pCase){
         case 1: fillMenu(zqsd, NULL_CASE,map[i+1][j], NULL_CASE,map[i][j+1]); //Corner haut/gauche
             break;
         case 2: fillMenu(zqsd, NULL_CASE,map[i+1][j],map[i][j-1],NULL_CASE); //Corner haut/droite
             break;
         case 3: fillMenu(zqsd,map[i-1][j], NULL_CASE, NULL_CASE,map[i][j+1]); //Corner bas/gauche
             break;
         case 4: fillMenu(zqsd,map[i-1][j],NULL_CASE,map[i][j-1],NULL_CASE); //Corner bas/droite
             break;
         case 5: fillMenu(zqsd, NULL_CASE,map[i+1][j],map[i][j-1],map[i][j+1]); //Bordure haut
             break;
         case 6: fillMenu(zqsd,map[i-1][j], NULL_CASE,map[i][j-1],map[i][j+1]); //Bordure bas
             break;
         case 7: fillMenu(zqsd,map[i-1][j],map[i+1][j], NULL_CASE,map[i][j+1]); //Bordure gauche
             break;
         case 8: fillMenu(zqsd,map[i-1][j],map[i+1][j],map[i][j-1], NULL_CASE); //Bordure droite
             break;
         default: fillMenu(zqsd,map[i-1][j],map[i+1][j],map[i][j-1],map[i][j+1]);
     }
}

void findPlayerSurrounding(char **map, int rows, int column, int actualZone, int* zqsd){
    int i = 0;
    int j = 0;
    int pCase = 0;
    for( i = 0 ; i < rows ; i++ ){
        for( j = 0 ; j < column ; j++ ){
            if(map[i][j] == 1){
                printf("player se trouve dans la case map[%d][%d]\n",i,j);
                pCase = particularCase(i,j,rows,column);
                switch(pCase){
                    case 1: printPlayerMenuCorner(pCase,map[i+1][j],map[i][j+1],actualZone); //Corner haut/gauche
                        break;
                    case 2: printPlayerMenuCorner(pCase,map[i+1][j],map[i][j-1],actualZone); //Corner haut/droite
                        break;
                    case 3: printPlayerMenuCorner(pCase,map[i-1][j],map[i][j+1],actualZone); //Corner bas/gauche
                        break;
                    case 4: printPlayerMenuCorner(pCase,map[i-1][j],map[i][j-1],actualZone); //Corner bas/droite
                        break;
                    case 5: printPlayerMenuBorder(pCase,map[i+1][j],map[i][j-1],map[i][j+1],actualZone); //Bordure haut
                        break;
                    case 6: printPlayerMenuBorder(pCase,map[i-1][j],map[i][j-1],map[i][j+1],actualZone); //Bordure bas
                        break;
                    case 7: printPlayerMenuBorder(pCase,map[i+1][j],map[i-1][j],map[i][j+1],actualZone); //Bordure gauche
                        break;
                    case 8: printPlayerMenuBorder(pCase,map[i+1][j],map[i-1][j],map[i][j-1],actualZone); //Bordure droite
                        break;
                    default: printPlayerMenu(map[i-1][j],map[i+1][j],map[i][j-1],map[i][j+1],actualZone);
                }
                fillMenuAll(map, i, j, pCase, zqsd);
                return;
            }
        }
    }
}

void getGameMenu(int *zqsd,int actualZone,Map* map1,Map* map2,Map* map3){
    // recuperer l'emplacement du personnage sur la map
    // verifier qu il n'est pas sur l'un des bords
    // verifier les outils et leur durabilite
    // afficher les deplacement possible avec zqsd
    // afficher retour au menu principal avec m

    if(actualZone == 1){
        findPlayerSurrounding(map1->map, map1->row, map1->column, actualZone, zqsd);
    }else if(actualZone == 2){
        findPlayerSurrounding(map2->map, map2->row, map2->column, actualZone, zqsd);
    }else if(actualZone == 3){
        findPlayerSurrounding(map3->map, map3->row, map3->column, actualZone, zqsd);
    }
}

void shiftCase(Map* map, int upDown, int leftRight, int value){
    int i = 0;
    int j = 0;
    for( i = 0 ; i< map->row ; i++){
        for( j = 0 ; j < map->column ; j++){
            if(map->map[i][j] == 1){
                map->map[i][j] = 0;
                map->map[i+upDown][j+leftRight] = value;
                return;
            }
        }
    }
}

void exitPortal(Map* map,int portal,ListRespawnCase* list){
    int i = 0;
    int j = 0;
    for( i = 0 ; i< map->row ; i++){
        for( j = 0 ; j < map->column ; j++){
            if(map->map[i][j] == portal){
                map->map[i][j] = 1;
                appendRespawnCase(list->first, newRespawnCase(1, i, j, portal));
                return;
            }
        }
    }
}

void shiftZone(int* actualZone, int* swapZone, Map* map1, Map* map2, Map* map3, int upDown,int leftRight, ListRespawnCase* list){
    if(*swapZone == 1){
        if(*actualZone == 1){
            shiftCase(map1, upDown, leftRight, -2);
            *actualZone = 2;
            exitPortal(map2, -2, list);
        }else{
            shiftCase(map2, upDown, leftRight, -2);
            *actualZone = 1;
            exitPortal(map1, -2, list);
        }
    }else if(*swapZone == 2){
        if(*actualZone == 2){
            shiftCase(map2, upDown, leftRight, -3);
            *actualZone = 3;
            exitPortal(map2, -3, list);
        }else{
            shiftCase(map3, upDown, leftRight, -3);
            *actualZone = 2;
            exitPortal(map3, -3, list);
        }
    }
    *swapZone = 0;
}

void getAction(Map* map, int value, int upDown,int leftRight, Player* player, int* swapZone){
    if(value == -99){
        printf("Tu ne peux pas marcher hors de la zone!\n");
    }else if(value == -3){
        *swapZone = 2;
    }else if(value == -2){
        *swapZone = 1;
    }else if(value == -1){
        printf("Tu ne peux pas marcher sur cette case!\n");
    }else if(value == 0){
        shiftCase(map,upDown,leftRight,1); //Code du deplacement
    }else if(value == 2){
        npcMenu(player); //Code du menu du PNG
    }else if(value == 3 || value == 6 || value == 9){
        //Code du recoltage de plante
    }else if(value == 4 || value == 7 || value == 10){
        //Code du Minage de pierre
    }else if(value == 5 || value == 8 || value == 11){
        //Code du recolte de bois
    }else if(value >= 12 && value <= 98){
        //Code de combat
    }else if(value == 99){
        //Code du combat contre le boss
    }
}

Map* getActualMap(Map* map1, Map* map2, Map* map3, int actualZone){
    if(actualZone == 1){
        return map1;
    }else if(actualZone == 2){
        return map2;
    }else{
        return map3;
    }
}

void freeLinkedList(RespawnCase* head){
    if(head != NULL){
        freeLinkedList(head->next);
        free(head);
    }
}

ListRespawnCase* initListRespawnCase(char *menu){
    ListRespawnCase* list = malloc(sizeof(ListRespawnCase));
    RespawnCase* element = malloc(sizeof(RespawnCase));

    if (list == NULL || element == NULL){
        printf("Erreur création de la liste chainee des RespawnCase\n");
        *menu = 'm';
        return NULL;
    }

    element->counter = -1;
    element->rowIndex = -1;
    element->columnIndex = -1;
    element->value = NULL_CASE;
    element->next = NULL;
    list->first = element;

    return list;
}

void appendRespawnCase(RespawnCase* head, RespawnCase* last){
    while(head->next != NULL){
        head = head->next;
    }
    head->next = last;
}

RespawnCase* newRespawnCase(int nbRespawnTime, int rowIndex, int columnIndex, int value){
    RespawnCase* e = malloc(sizeof(RespawnCase));
    e->counter = nbRespawnTime;
    e->rowIndex = rowIndex;
    e->columnIndex = columnIndex;
    e->value = value;
    e->next = NULL;
    return e;
}
//faire une fonction prennant un chiffre qui va permettre de retrouver la structure a enlever.


void respawnObject(RespawnCase* head, char** map){
    if(head != NULL){
        respawnObject(head->next, map);
        if( (head->counter) - 1 == 0){
            if(map[(head->rowIndex)][(head->columnIndex)] != 1){
                map[(head->rowIndex)][(head->columnIndex)] = head->value;
                if(head->next == NULL){

                }
            }
        }
    }
}

void game(Map* map1,Map* map2,Map* map3, Player* player){
    int actualZone = getZone(map1,map2);
    int zqsd[4]={0};
    char menu = -1;
    int swapZone = 0;
    ListRespawnCase * list = initListRespawnCase(&menu);
    int upDown = 0;
    int leftRight = 0;

    while(menu != 'm'){
        displayActualMap(map1,map2,map3,actualZone);
        printf("actualZone : %d\n",actualZone);
        getGameMenu(zqsd, actualZone, map1, map2, map3);
        printf("z = %d, q = %d, s = %d, d = %d\n",zqsd[0],zqsd[1],zqsd[2],zqsd[3]);
        printf("Entrer : ");
        cleanStdin();
        scanf("%c",&menu);

        switch(menu){
            case 122: getAction(getActualMap(map1, map2, map3, actualZone), zqsd[0], -1, 0, player, &swapZone);// 122 == 'z'
                upDown = -1;
                leftRight = 0;
                break;
            case 113: getAction(getActualMap(map1, map2, map3, actualZone), zqsd[1], 0, -1, player, &swapZone);// 113 == 'q'
                upDown = 0;
                leftRight = -1;
                break;
            case 115: getAction(getActualMap(map1, map2, map3, actualZone), zqsd[2], 1, 0, player, &swapZone);// 115 == 's'
                upDown = 1;
                leftRight = 0;
                break;
            case 100: getAction(getActualMap(map1, map2, map3, actualZone), zqsd[3], 0, 1, player, &swapZone);// 100 == 'd'
                upDown = 0;
                leftRight = 1;
                break;
            case 105: ;// 105 == 'i'
                break;
            case 112: ;// 112 == 'p'
                break;
            case 109: break;// 109 == 'm'
            default: printf("Touche non attribué !\n");
        }
        if(swapZone != 0){
            shiftZone(&actualZone, &swapZone, map1, map2, map3, upDown, leftRight ,list);
        }
        printLinkedList(list->first);
        respawnObject(list->first,getActualMap(map1, map2, map3, actualZone)->map);
    }
    freeLinkedList(list->first);
    free(list);
}
