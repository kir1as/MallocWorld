//
// Created by William Lin on 02/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "respawn.h"
#include "define.h"

void freeLinkedList(RespawnCase* head){
    if(head != NULL){
        freeLinkedList(head->next);
        free(head);
    }
}

ListRespawnCase* initListRespawnCase(char *menu){
    ListRespawnCase* list = malloc(sizeof(ListRespawnCase));
    RespawnCase* element = malloc(sizeof(RespawnCase));

    if (list == NULL || element == NULL){
        printf("Erreur création de la liste chainee des RespawnCase\n");
        *menu = 'm';
        return NULL;
    }

    element->counter = -1;
    element->rowIndex = -1;
    element->columnIndex = -1;
    element->value = NULL_CASE;
    element->next = NULL;
    list->first = element;

    return list;
}

void appendRespawnCase(RespawnCase* head, RespawnCase* last){
    while(head->next != NULL){
        head = head->next;
    }
    head->next = last;
}

RespawnCase* newRespawnCase(int nbRespawnTime, int rowIndex, int columnIndex, int value){
    RespawnCase* e = malloc(sizeof(RespawnCase));
    e->counter = nbRespawnTime;
    e->rowIndex = rowIndex;
    e->columnIndex = columnIndex;
    e->value = value;
    e->next = NULL;
    return e;
}

//faire une fonction prennant un chiffre qui va permettre de retrouver la structure a enlever.
void deleteElement(RespawnCase* head,int index){
    RespawnCase* tmp;
    if(head != NULL){
        if(index == 1){
            tmp = head->next;
            head->next = head->next->next;
            free(tmp);
        }else{
            deleteElement(head->next,index-1);
        }
    }
}

void respawnObject(RespawnCase* head, char** map, int counter, RespawnCase* first){
    if(head != NULL){
        respawnObject(head->next, map, counter+1, first);
        if( (head->counter) - 1 == 0){
            if(map[(head->rowIndex)][(head->columnIndex)] != 1){
                map[(head->rowIndex)][(head->columnIndex)] = head->value;
                //code de suppression de liste
                deleteElement(first, counter);
            }
        }else if(head->value != NULL_CASE && head->counter != 1){
            head->counter -= 1;
        }
    }
}
