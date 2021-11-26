//
// Created by William Lin on 28/10/2021.
//

#ifndef MALLOC_WORLD_NPC_H
#define MALLOC_WORLD_NPC_H

#endif //MALLOC_WORLD_NPC_H

//Permet de recuperer la durabilite max d'un item a partir de son id
int getDurability(int id);
//Fonction qui permet de reparer les armes et outils de l'inventaire
void repairEquipment(Player* player);
//Permet l'affichage du menu du PNG
void npcMenu(Player* player);
//Permet d'ajouter un item dans l'inventaire
void appendItemInventory(Player* player, int harvestQuantity, int value);
//Permet de recuperer un item du coffre
void withdrawItemFromStorage(Player* player, int idWithdraw);
//menu de la fonctionnalite de recuperer un item du coffre
void withdrawItem(Player* player);
//Permet d'ajouter un item dans le coffre
void appendItemInStorage(Player* player,int i);
//Permet d'ajouter une ressource dans le coffre
void appendResourceInStorage(Player* player,int i);
//menu de la fonctionnalite de deposer un item du coffre
void depositItem(Player* player);
//menu de la fonctionnalite de storage du png
void storage(Player* player);