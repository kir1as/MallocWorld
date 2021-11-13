//
// Created by William Lin on 13/11/2021.
//

#ifndef MALLOC_WORLD_SAVE_H
#define MALLOC_WORLD_SAVE_H

#endif //MALLOC_WORLD_SAVE_H

//Permet de recuperer le nombre de caracteres dans le storage
int storageCount(void);
//Permet de recuperer tout les caracteres du storage dans un buffer
void getStorage(char* buffer);
//Permet de transformer le fichier de sauvegarde temporaire en fichier de sauvegarde
void renameNewFile(void);
//Permet de savegarder l'etat actuelle du jeu si le joueur ne se trouve pas sur une case d'un objet
//qui doit respawn.
//la sauvegarde est un fichier de sauvegarde temporaire
void saveGame(Map* map1,Map* map2,Map* map3, Player* player, ListRespawnCase* list, int actualZone);

