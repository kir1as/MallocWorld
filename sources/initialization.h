//
// Created by William Lin on 18/10/2021.
//

#ifndef MALLOC_WORLD_INITIALIZATION_H
#define MALLOC_WORLD_INITIALIZATION_H

#endif //MALLOC_WORLD_INITIALIZATION_H

#include "prototypes.h"

//Fonction permetant de recuperer les bornes a partir d'une zone pour une map
void getMapDelimitation(int zone,char *startZone,char *endZone);
//Renvoi un double pointeur de type int qui represente une map.
//permet aussi de recuperer son nombre de ligne et de colonne
//nbMap prend 1,2 ou 3 -> equivalant de la zone;
void retrieveMap(Map* map,int nbMap);
//Permet de recuperer le nombre de ligne et colonne d'une map avec sa zone dans le fichier de sauvegarde
//et de recuperer l'index ou commence la zone dans le fichier de sauvegarde dans tmpIndex
void retrieveMapSize(int zone,Map* map,int* tmpIndex);
//Permet de recuperer la donnee d'une zone dans un tableau a partir du fichier de sauvegarde
void retrieveMapData(int zone,int tmpIndex,Map* map);
//Permet de recuperer les informations d'un joueur a partir du fichier de sauvegarde dans une structure
void retrievePlayer(Player *player);
//permet de free un double pointeur passer en parametre avec son nombre de ligne
void freeTwoDimensionArray(char **array,int rows);
//Permet de continuer une partie a partir d'une sauvegarde
void continueGame(void);

