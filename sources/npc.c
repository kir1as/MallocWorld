//
// Created by William Lin on 28/10/2021.
//

#include <stdio.h>
#include "prototypes.h"


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

void npcMenu(Player* player){
    int menu = -1;
    printf("Bienvenue, Je suis le marchand qui ne prend pas d'argent, que puis-je faire pour vous ?\n");
    while(menu < 5 && menu >= -1){
        printf(" 1 - Réparer les équipements\n 2 - Retirer un objet du coffre\n 3 - Déposer un objet dans le coffre\n"
               " 4 - Crafter un objet\n 5 - Annuler\n");
        printf("Entrer :");

        scanf("%d",&menu);
        cleanStdin();
        clear_screen();
        switch(menu){
            case 1: repairEquipment(player);
                break;
            case 2: ;
                break;
            case 3: ;
                break;
            case 4: ;
                break;
        }
    }
}