//
// Created by William Lin on 18/10/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "initialization.h"
#include "game.h"

void getMapDelimitation(int zone,char *startZone,char *endZone){
    if(zone == 2){
        strcpy(startZone ,"-- ZONE 2 --\n");
        strcpy(endZone ,"-- ZONE 3 --\n");
    }else if(zone == 3){
        strcpy(startZone ,"-- ZONE 3 --\n");
        strcpy(endZone ,"=== PLAYER ===\n");
    }
}

void retrieveMap(Map* map,int nbMap){
    int tmpIndex = 0;
    int i = 0;
    map->column = 1;
    map->row = 1;

    retrieveMapSize(nbMap,map,&tmpIndex);
    if(tmpIndex == 0){
        printf("Sauvegarde corrompue\n");
        map->row = -1;
    }else{
        //printf("column : %d\n",map->column);
        //printf("rows : %d\n",map->row);
        map->map = malloc(sizeof(char*)* (map->row));
        if(map->map != NULL){
            for( i = 0; i < (map->row) ; i++ ){
                map->map[i] = malloc(sizeof(char)* (map->column));
            }
            retrieveMapData(nbMap,tmpIndex,map);
        }
    }
}

void retrieveMapSize(int zone,Map* map,int* tmpIndex){
    char startZone[20] = "-- ZONE 1 --\n";
    char endZone[20] ="-- ZONE 2 --\n";
    char line[255];
    char c = 'a';

    getMapDelimitation(zone,startZone,endZone);

    FILE * fp = fopen("save.txt","r+");
    if(fp == NULL){
        printf("fichier de sauvegarde introuvable\n");
        return;
    }
    while(fgets(line,255,fp)!=NULL){
        if(strcmp(line,startZone)==0){
            *tmpIndex = ftell(fp);
            while(c!='\n'){
                c = fgetc(fp);
                if(c == ' '){
                    (map->column)+=1;
                }
            }
            while(fgets(line,255,fp)!=NULL && strcmp(line,endZone)!=0){
                (map->row)+=1;
            }
        }
    }
    fclose(fp);
}

void retrieveMapData(int zone,int tmpIndex,Map* map){
    char line[255];
    int i = 0;
    int j = 0;
    char *res;

    FILE * fp = fopen("save.txt","r+");
    if(fp == NULL){
        printf("fichier de sauvegarde introuvable\n");
        return;
    }
    fseek(fp,tmpIndex,SEEK_SET);
    for(i = 0; i< map->row ;i++ ){
        j=0;
        fgets(line,255,fp);
        res = strtok ( line ," ");
        while ( res != NULL ) {
            map->map[i][j]=atoi(res);
            j++;
            // On demande le token suivant.
            res = strtok ( NULL," ");
        }

    }
    fclose(fp);
}

void retrievePlayer(Player *player){
    char line[255];
    char c = 'a';
    int i = 0;
    FILE *fp = fopen("save.txt","r+");
    if(fp == NULL){
        printf("fichier de sauvegarde introuvable\n");
        return;
    }

    while(fgets(line,255,fp) != NULL && strcmp(line, "-- STORAGE --\n") != 0 && strcmp(line, "-- STORAGE --") != 0){
        if(strcmp(line,"=== PLAYER ===\n")==0){
            fgets(line,255,fp);
            player->level = atoi(line+1);
            fgets(line,255,fp);
            player->exps = atoi(line+1);
            fgets(line,255,fp);
            player->hpNow = atoi(strtok(line,"/")+1);
            player->hpMax = atoi(strtok(NULL,"/")+1);
            fgets(line,255,fp);
            for( i = 0 ; i < 10 ; i++ ){
                if(fgets(line,255,fp) == NULL){
                    printf("fichier de sauvegarde corrompue\n");
                    return;
                }
                player->inventory[i].quantity = atoi(strtok(line,"@")+1);
                player->inventory[i].id = atoi(strtok(NULL,"@")+1);
                player->inventory[i].durability = atoi(strtok(NULL,"@")+1);
            }

        }
    }
    fclose(fp);
}

void freeTwoDimensionArray(char **array,int rows){
    int i = 0;
    for( i = 0 ; i < rows ; i++ ){
        free(array[i]);
    }
    free(array);
}

void continueGame(void){
    Player* player = malloc(sizeof(Player));
    Map* map1 = malloc(sizeof(Map));
    Map* map2 = malloc(sizeof(Map));
    Map* map3 = malloc(sizeof(Map));
    int gameValue = 0;
    retrieveMap(map1,1);
    // printf("column continueGame: %d\n",map1->column);
    // printf("rows continueGame: %d\n",map1->row);
    //Si la sauvegarde n'est pas est corrompue
    if(map1->row != -1){
        //displayMap(map1);
        retrieveMap(map2,2);
        if(map2->row != -1){
            //displayMap(map2);
            retrieveMap(map3,3);
            if(map3->row != -1){
                //displayMap(map3);
                retrievePlayer(player);
                //displayPlayer(player);
                gameValue = game(map1, map2, map3, player);
                if(gameValue == -1){
                    if(remove("save.txt") != 0){
                        printf("Erreur sur la suppresion du fichier save.txt!\n");
                    }
                }else{

                }
                freeTwoDimensionArray(map3->map,map3->row);
            }
            freeTwoDimensionArray(map2->map,map2->row);
        }
        freeTwoDimensionArray(map1->map,map1->row);
    }
    free(map3);
    free(map2);
    free(map1);
    free(player);
}

