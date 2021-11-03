//
// Created by William Lin on 02/11/2021.
//

#ifndef MALLOC_WORLD_RESPAWN_H
#define MALLOC_WORLD_RESPAWN_H

#endif //MALLOC_WORLD_RESPAWN_H


void freeLinkedList(RespawnCase* head);

ListRespawnCase* initListRespawnCase(char *menu);

void appendRespawnCase(RespawnCase* head, RespawnCase* last);

RespawnCase* newRespawnCase(int nbRespawnTime, int rowIndex, int columnIndex, int value);

void respawnObject(RespawnCase* head, char** map, int counter, RespawnCase* first);
