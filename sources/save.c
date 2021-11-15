//
// Created by William Lin on 13/11/2021.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "prototypes.h"
#include "respawn.h"
#include "game.h"
#include "define.h"

void errorLog(const char* txt){
    FILE *fp = fopen(ERROR_FILE_PATHNAME,"a");
    if (fp != NULL) {
        fprintf(fp, "%s",txt);
    }
    fclose(fp);
}

int storageCount(void){
    int counter = 0;
    char line[255];

    FILE *fp = fopen(SAVE_FILE_PATHNAME,"r");
    if(fp != NULL){
        fgets(line,255,fp);
        while(strcmp(line, "-- STORAGE --\n") != 0 && strcmp(line, "-- STORAGE --") != 0){
            fgets(line,255,fp);
        }
        while(feof(fp) == 0){
            fgetc(fp);
            counter++;
        }
    }else{
        errorLog("Erreur d'ouverture du fichier save.txt - storageCount()!\n");
        printf("ERREUR\n");
    }
    return counter;
}

void getStorage(char* buffer){
    int counter = 0;
    char line[255];

    FILE *fp = fopen(SAVE_FILE_PATHNAME,"r");
    if(fp != NULL){
        fgets(line,255,fp);
        while(strcmp(line, "-- STORAGE --\n") != 0 && strcmp(line, "-- STORAGE --") != 0){
            fgets(line,255,fp);
        }
        while(feof(fp) == 0){
            buffer[counter] = (char)fgetc(fp);
            counter++;
        }
        buffer[counter-1]='\0';
    }else{
        printf("ERREUR\n");
    }
}

void renameNewFile(void){
    if(remove(SAVE_FILE_PATHNAME) == 0){
        errorLog("remove ok!\n");
        if(rename("save2.txt",SAVE_FILE_PATHNAME) == 0){
            errorLog("rename ok!\n");
        }else{
            errorLog("Erreur du renommage du fichier save2.txt en save.txt!\n");
        }
    }else{
        errorLog("Erreur sur la suppression du fichier save.txt!\n");
    }
}

void saveGame(Map* map1,Map* map2,Map* map3, Player* player, ListRespawnCase* list, int actualZone){
    int countMax = verifyPlayerBeforeRespawn(list->first->next, getActualMap(map1, map2, map3, actualZone)->map );
    if( countMax == -1){
        printf("Vous ne pouvez pas sauvegarder dans cette case!\n");
        return;
    }
    respawnAllObject(list->first,getActualMap(map1, map2, map3, actualZone)->map,countMax);

    char* buffer = malloc((sizeof(char)*storageCount()) + 1);
    int i = 0;
    int j = 0;
    FILE *fp = fopen("save2.txt","w+");
    if(buffer == NULL){
        errorLog("Erreur d'allocation mémoire ! - saveGame()\n");
        printf("Erreur d'allocation mémoire!\n");
        return;
    }
    getStorage(buffer);

    if(fp != NULL){
        fputs("=== MAP ===\n-- ZONE 1 --\n",fp);
        for( i = 0 ; i < map1->row ; i++){
            fprintf(fp,"%d",map1->map[i][0]);
            for( j = 1 ; j < map1->column ; j++){
                fprintf(fp," %d",map1->map[i][j]);
            }
            fputc('\n',fp);
        }
        fputs("-- ZONE 2 --\n",fp);
        for( i = 0 ; i < map2->row ; i++){
            fprintf(fp,"%d",map2->map[i][0]);
            for( j = 1 ; j < map2->column ; j++){
                fprintf(fp," %d",map2->map[i][j]);
            }
            fputc('\n',fp);
        }
        fputs("-- ZONE 3 --\n",fp);
        for( i = 0 ; i < map3->row ; i++){
            fprintf(fp,"%d",map3->map[i][0]);
            for( j = 1 ; j < map3->column ; j++){
                fprintf(fp," %d",map3->map[i][j]);
            }
            fputc('\n',fp);
        }
        fprintf(fp,"=== PLAYER ===\n{%d}\n{%d}/{%d}\n{%d}/{%d}\n",
               player->level,player->exps, getExpMax(player),player->hpNow,player->hpMax);
        fputs("-- INVENTORY --\n",fp);
        for( i = 0 ; i < 10 ; i++ ){
            fprintf(fp,"{%d}@{%d}@{%d}\n",player->inventory[i].quantity,
                   player->inventory[i].id,player->inventory[i].durability);
        }
        fputs("-- STORAGE --\n",fp);
        fprintf(fp,"%s",buffer);
    }

    free(buffer);
    fclose(fp);
    renameNewFile();
}
