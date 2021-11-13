//
// Created by William Lin on 18/10/2021.
//

#ifndef MALLOC_WORLD_NEWGAME_H
#define MALLOC_WORLD_NEWGAME_H

#endif //MALLOC_WORLD_NEWGAME_H

//Recupere le numero d'un monstre aleatoirement a partir de la zone
//int zone prend 1,2 ou 3
int randomMonster(int zone);
//Permet de generer une map avec des elements par en comprenant la zone
//les elements sont disposer pseudo-aleatoirement.
//int zone prend 1,2 ou 3
void generateMap(int zone,int map[][10]);
//Permet de mettre le hero,le PNG et le portail apres la generation de la map
//cela a pour but d'eviter les situations de game over en plaçant le hero a cote du PNG
//int zone prend 1,2 ou 3
void putPlayerNpcPortal(int zone,int map[][10]);
//Permet de mettre un boss sur une map
void putBoss(int map[][10]);
//Permet de creer une nouvelle partie en creant une nouvelle sauvegarde
void newGame(void);