//
// Created by William Lin on 02/11/2021.
//

#ifndef MALLOC_WORLD_HARVEST_H
#define MALLOC_WORLD_HARVEST_H

#endif //MALLOC_WORLD_HARVEST_H

int valueToHarvestItemId(int value);

int verifyInventorySpace(Player* player, int value, int harvestQuantity);

int verifyHarvestItem(Player* player, int value, int minDurability);

void harvestedCase( ListRespawnCase* list, Map* map, int upDown, int leftRight, int value);

void stockHarvestedItem(Player* player, int harvestQuantity, int value);

void harvest(Map* map, Player* player, ListRespawnCase* list, int value, int upDown,int leftRight);