//
// Created by William Lin on 18/10/2021.
//

#ifndef MALLOC_WORLD_PROTOTYPE_H
#define MALLOC_WORLD_PROTOTYPE_H

#endif //MALLOC_WORLD_PROTOTYPE_H

#include "structures.h"

//Permet d'afficher le menu principal
void getMenu(void);
//Permet d'afficher une map passer en parametre
void displayMap(Map* map);
//permet d'afficher donnee d'une structure Player en parametre
void displayPlayer(Player *player);
//Permet d'afficher la map ou se trouve actuellement le heros
void displayActualMap(Map* map1,Map* map2,Map* map3, int actualZone);
//Permet de "nettoyer" l'entrer standard
void cleanStdin(void);
//Permet d'afficher une liste chainee
void printLinkedList(RespawnCase* head);
//Permet de recuperer le nombre d'exp qu'il faut pour chaque niveau
int getExpMax(Player *player);
//Permet d'eregistrer dans un fichier les erreurs passer en parametre
void errorLog(const char* txt);
//Permet de clear l'ecran du terminal
void clear_screen(void);
//Permet d'afficher l'inventaire du joueur
void displayInventory(Player *player);
//Permet de recuperer les noms des items a partir d'un id
char* getNameFromObjectID1(int id);
char* getNameFromObjectID2(int id);
//Permet d'afficher le coffre
int displayStorage(void);
//Permet de savoir si oui ou non l'item est stackable a partir d un id
int getStackableResources(int id);
