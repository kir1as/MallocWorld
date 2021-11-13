//
// Created by William Lin on 04/11/2021.
//

#ifndef MALLOC_WORLD_BATTLE_H
#define MALLOC_WORLD_BATTLE_H

#endif //MALLOC_WORLD_BATTLE_H

//Permet de mettre a jour le HPMAX du joueur
void updateHpMax(Player* player);
//Permet de verifier si le joueur peut monter d'un niveau
void getLevel(Player* player);
//Permet de recuperer les degats d'une arme
int getWeaponDamage(int id);
//Fonction du tour d'attaque du heros
int playerAttack(Player* player, Monster* monster, int weaponIndex);
//Permet de verifier si le heros possede une armure
int verifyArmor(Player* player);
//Fonction du tour du monstre, si le monstre met a 0 les pv du heros, game over
int monsterAttack(Player* player, Monster* monster);
//Permet de fuir le combat, 30% de chances
int escape(void);
//Utilisation de la potion passer en parametre
void healPlayer(Player* player, int value);
//Permet de recuperer la potion la plus puissante
int heal(Player* player);
//Permet d'afficher les armes presente dans l'inventaire
void displayWeapon(Player* player, int* hashmapInv);
//Permet de verifier l'arme choisi est bien une arme
int verifyWeaponChoose(Player* player,int *hashmapInv, int value);
//Permet de choisir son arme avant le combat
int chooseWeapon(Player* player);
//Permet de stocker dans la liste chainee la case du monstre battue
void monsterCase( ListRespawnCase* list, Map* map, int upDown, int leftRight, int value);
//Fonction general du combat, fait office de menu du joueur
int battle(Player* player, int monsterId);
//Permet d'afficher le monstre a combattre
void displayMonster(Monster* monster);
//Permet de recuperer les informations du monstre a combattre a partir d'un fichier monstres.txt
void getMonsterData(int monsterId, Monster* monster);