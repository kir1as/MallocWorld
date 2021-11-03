//
// Created by William Lin on 27/10/2021.
//

#ifndef MALLOC_WORLD_GAME_H
#define MALLOC_WORLD_GAME_H

#endif //MALLOC_WORLD_GAME_H



//Permet savoir si le heros ce trouve dans le tableau entrer en parametre
int findPlayer(char **map, int rows, int column);
//Permet de savoir dans quelle zone se trouve le heros
int getZone(Map* map1,Map* map2);
//Permet de reperer si le heros ce trouve dans une case qui est particulier (bordure et coin)
int particularCase(int i, int j, int rows, int column);
//Permet d'avoir un catalogue de dialogue, peut etre changer par un fichier si multilingue
char *getTextFromMap(int value, int actualZone);
//Permet d'afficher le menu si le heros ce trouve sur un coin
void printPlayerMenuCorner(int pCase,int value1, int value2, int actualZone);
//Permet d'afficher le menu si le heros ce trouve sur une bordure
void printPlayerMenuBorder(int pCase,int value1, int value2, int value3, int actualZone);
//Permet d'afficher le menu du heros
void printPlayerMenu(int up, int down, int left, int right, int actualZone);
//Stock les valeurs qui entoure le heros
void fillMenu(int* zqsd, int up, int down, int left, int right);
//Permet de gerer les deplacements impossibles
void fillMenuAll(char **map, int i, int j, int pCase, int* zqsd);
//Permet de trouver les
void findPlayerSurrounding(char **map, int rows, int column, int actualZone, int* zqsd);
//Permet de recuperer le menu du heros
void getGameMenu(int *zqsd,int actualZone,Map* map1,Map* map2,Map* map3);

void shiftCase(Map* map, int upDown, int leftRight, int value);

void getAction(Map* map, ListRespawnCase* list, int value, int upDown,int leftRight, Player* player, int* swapZone);

Map* getActualMap(Map* map1, Map* map2, Map* map3, int actualZone);
//Fonction qui appel le jeu
void game(Map* map1,Map* map2,Map* map3, Player* player);

void exitPortal(Map* map,int portal,ListRespawnCase* list);

void shiftZone(int* actualZone, int* swapZone, Map* map1, Map* map2, Map* map3, int upDown,int leftRight, ListRespawnCase* list);
