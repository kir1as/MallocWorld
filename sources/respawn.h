//
// Created by William Lin on 02/11/2021.
//

#ifndef MALLOC_WORLD_RESPAWN_H
#define MALLOC_WORLD_RESPAWN_H

#endif //MALLOC_WORLD_RESPAWN_H

//Permet de free une liste chainee
void freeLinkedList(RespawnCase* head);
//Permet d'initialiser la liste contenant les elements respawnables
//le premier element est un element temporaire
ListRespawnCase* initListRespawnCase(char *menu);
//Permet d'ajouter un element a la fin d'une liste chainee
void appendRespawnCase(RespawnCase* head, RespawnCase* last);
//Permet de creer et initialiser un element contenant les informations d'une case a respawn
RespawnCase* newRespawnCase(int nbRespawnTime, int rowIndex, int columnIndex, int value);
//Permet de supprimer un element de la liste en precisant l'emplacement de l'element dans la liste
void deleteElement(RespawnCase* head,int index);
//Permet de parcourir la liste chainee et de voir si un element va respawn, si oui, on respawn
//et on detruit l'element a respawn grace a l'indice counter
void respawnObject(RespawnCase* head, char** map, int counter, RespawnCase* first);
//Permet de savoir si le heros se trouve actuellement sur une case a respawn et retourne -1
//sinon de recuperer le nombre de tour maximum d'un element a respawn dans la liste
int verifyPlayerBeforeRespawn(RespawnCase* head, char** map);
//Permet de boucler turn fois pour respawn tout les objets
void respawnAllObject(RespawnCase* head, char** map, int turn);