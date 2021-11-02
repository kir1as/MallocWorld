//
// Created by William Lin on 18/10/2021.
//

#include <stdio.h>
#include <string.h>
#include "newGame.h"
#include "initialization.h"

void getMenu(void){
    int menu = -1;
    int firstMessage = 0;
    char menuMessage[] = "Bienvenue C  Malloc World !\n 1 - Nouvelle partie\n 2 - Continuer\n 3 - Quitter\nEntrer : ";

    while (menu != 3){
        if(fopen("save.txt","r")==NULL){
            strcpy(menuMessage,"Bienvenue C  Malloc World !\n 1 - Nouvelle partie\n 2 - Quitter\nEntrer : ");
            firstMessage = 1;
        }else{
            strcpy(menuMessage,"Bienvenue C  Malloc World !\n 1 - Nouvelle partie\n 2 - Continuer\n 3 - Quitter\nEntrer : ");
            firstMessage = 0;
        }
        printf("%s",menuMessage);
        scanf ("%d", &menu);

        switch(menu){
            case 1: newGame();
                // newPlayer(player);
                // printf("\nplayer hp on main %d\n",player->hpNow);
                // retrieveMap(map1,map2,map3);
                //
                // loadGame();
                break;
            case 2: if(firstMessage==1){
                    menu = 3;
                }else{
                    continueGame();
                }
                break;
        }
    }
}
