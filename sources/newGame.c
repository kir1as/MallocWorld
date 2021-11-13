//
// Created by William Lin on 18/10/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "newGame.h"

int randomMonster(int zone){
    srand( time( NULL ) + rand()%100 );
    if(zone == 1){
        return (rand()%28)+12; //12-39
    }else if(zone == 2){
        return (rand()%28)+40; //40-67
    }else{
        return (rand()%31)+68; //68-98
    }
}

//10-15 monstres, 3-7 arbres, 3-7 pierres, 3-7 plantes, 5-20 case impossible, 100 cases
void generateMap(int zone,int map[][10]){
    srand( time( NULL ) + rand()%100 );
    int counterMonster = (rand()%6)+10;
    int counterTree = (rand()%5)+3;
    int counterPlant = (rand()%5)+3;
    int counterStone = (rand()%5)+3;
    int counterImpossible = (rand()%16)+5;
    int randNb = rand()%6;
    int counterCase = 100 - counterMonster - counterTree - counterPlant - counterStone - counterImpossible;
    int turn = 0;
    int i = 0;
    int j = 0;
    for( i = 0 ; i < 10 ; i++){
        for( j = 0 ; j < 10 ; j++){
            turn = 0;
            while(turn == 0){
                randNb = (rand()%11);
                if(randNb == 0 && counterImpossible != 0){
                    map[i][j] = -1;
                    counterImpossible -= 1;
                    turn = 1;
                }else if(randNb > 4 && counterCase != 0){
                    map[i][j] = 0;
                    counterCase -= 1;
                    turn = 1;
                }else if(randNb == 1 && counterMonster != 0){
                    map[i][j] = randomMonster(zone);
                    counterMonster -= 1;
                    turn = 1;
                }else if(randNb == 2 && counterPlant != 0){
                    map[i][j] = 3 + zone - 1;
                    counterPlant -= 1;
                    turn = 1;
                }else if(randNb == 3 && counterStone != 0){
                    map[i][j] = 4 + zone -1;
                    counterStone -= 1;
                    turn = 1;
                }else if(randNb == 4 && counterTree != 0){
                    map[i][j] = 5 + zone - 1;
                    counterTree -= 1;
                    turn = 1;
                }
            }
        }
    }
}

void putPlayerNpcPortal(int zone,int map[][10]){
    int i = 0;
    int j = 0;
    int playerNpc = 0;
    int portal = 0;
    for( i = 0 ; i < 10-1 ; i++ ){
        for( j = 0 ; j < 10-1 ; j++ ){
            if(zone == 1 && map[i][j] == 0 && map[i][j+1] == 0 && map[i+1][j] == 0 && map[i+1][j+1] == 0 && playerNpc == 0){
                map[i][j] = 1;
                map[i][j+1] = 2;
                playerNpc = 1;
            }else if(zone == 1 && map[i][j] == 0 && map[i][j+1] == 0 && map[i+1][j] != -1 && portal == 0){
                map[i][j] = -2;
                portal = 1;
            }else if(zone == 2 && map[i][j] == 0 && map[i][j+1] == 0 && map[i+1][j] == 0 && map[i+1][j+1] == 0 && playerNpc == 0){
                map[i][j+1] = 2;
                playerNpc = 1;
            }else if(zone == 2 && map[i][j] == 0 && map[i][j+1] == 0 && map[i+1][j] != -1 && map[i+1][j+1] != -1 && portal == 0){
                map[i][j] = -2;
                map[i][j+1] = -3;
                portal = 1;
            }else if(zone == 3 && map[i][j] == 0 && map[i][j+1] == 0 && map[i+1][j] == 0 && map[i+1][j+1] == 0 && playerNpc == 0){
                map[i][j+1] = 2;
                playerNpc = 1;
            }else if(zone == 3 && map[i][j] == 0 && map[i][j+1] == 0 && map[i+1][j] != -1 && portal == 0){
                map[i][j] = -3;
                portal = 1;
            }
            if(portal == 1 && playerNpc == 1){
                return;
            }
        }
    }
    if(portal == 0 && playerNpc == 0){
        printf("Map generation error\n");
        exit(-1);
    }
}

void putBoss(int map[][10]){
    int i = 0 ;
    int j = 0 ;
    for( i = 1 ; i < 10-1 ; i++ ){
        for( j = 1 ; j < 10-1 ; j++ ){
            if(map[i][j] == 0 && map[i][j+1] != -1 && map[i+1][j] != -1 && map[i-1][j] != -1 && map[i][j-1] != -1){
                map[i][j] = 99;
                return;
            }
        }
    }
}

void newGame(void){
    int map1[10][10];
    int map2[10][10];
    int map3[10][10];
    int i = 0;
    generateMap(1,map1);
    putPlayerNpcPortal(1,map1);
    generateMap(2,map2);
    putPlayerNpcPortal(2,map2);
    generateMap(3,map3);
    putPlayerNpcPortal(3,map3);
    putBoss(map3);
    FILE *fp = fopen("save.txt","w+");
    if(fp != NULL){
        fputs("=== MAP ===\n-- ZONE 1 --\n",fp);
        for( i = 0 ; i < 10 ; i++){
            fprintf(fp,"%d %d %d %d %d %d %d %d %d %d\n",map1[i][0],map1[i][1],map1[i][2],map1[i][3],map1[i][4],
                    map1[i][5],map1[i][6],map1[i][7],map1[i][8],map1[i][9]);
        }
        fputs("-- ZONE 2 --\n",fp);
        for( i = 0 ; i < 10 ; i++){
            fprintf(fp,"%d %d %d %d %d %d %d %d %d %d\n",map2[i][0],map2[i][1],map2[i][2],map2[i][3],map2[i][4],
                    map2[i][5],map2[i][6],map2[i][7],map2[i][8],map2[i][9]);
        }
        fputs("-- ZONE 3 --\n",fp);
        for( i = 0 ; i < 10 ; i++){
            fprintf(fp,"%d %d %d %d %d %d %d %d %d %d\n",map3[i][0],map3[i][1],map3[i][2],map3[i][3],map3[i][4],
                    map3[i][5],map3[i][6],map3[i][7],map3[i][8],map3[i][9]);
        }
        fputs("=== PLAYER ===\n{1}\n{0}/{100}\n{100}/{100}\n-- INVENTORY --\n"
              "{1}@{1}@{10}\n{1}@{2}@{10}\n{1}@{3}@{10}\n{1}@{4}@{10}\n{0}@{0}@{0}\n"
              "{0}@{0}@{0}\n{0}@{0}@{0}\n{0}@{0}@{0}\n{0}@{0}@{0}\n{0}@{0}@{0}\n-- STORAGE --\n",fp);
    }
    fclose(fp);
}
