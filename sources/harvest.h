//
// Created by William Lin on 02/11/2021.
//

#ifndef MALLOC_WORLD_HARVEST_H
#define MALLOC_WORLD_HARVEST_H

#endif //MALLOC_WORLD_HARVEST_H

//Permet de retourner l'id de l'outil a utiliser par rapport a ce qu'on veut recolter
int valueToHarvestItemId(int value);
//Permet de retourner l'id de la ressource a recuperer par rapport a ce qu'on veut recolter
int itemHarvested(int value);
//Permet de verifier s'il y a de la place dans l'inventaire et si l'objet peut etre stack
int verifyInventorySpace(Player* player, int value, int harvestQuantity);
//Permet de verifier si il y a une case vide dans l'inventaire
int verifyUniqueInventorySpace(Player* player);
//Permet de verifier si l'outil se trouve dans l'inventaire par rapport a ce qu'on veut recolter
//ainsi que sa durabilité
int verifyHarvestItem(Player* player, int value, int minDurability);
//Permet d'ajouter l'objet recolter dans la liste a respawn ainsi que changer la valeur de la case recolter
void harvestedCase( ListRespawnCase* list, Map* map, int upDown, int leftRight, int value);
//Permet de stocker dans l'inventaire l'objet recolter, l'empilage des recoltes est prioritaire
void stockHarvestedItem(Player* player, int harvestQuantity, int value);
//Fonction general de la recolte
//elle permet de recuperer la durabilite min de l'outil a utiliser ainsi que la quantite de la ressource recolte
void harvest(Map* map, Player* player, ListRespawnCase* list, int value, int upDown,int leftRight);