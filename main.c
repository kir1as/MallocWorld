/*
 * This is the main file
 *
 * Created by William Lin,... and .... on 18/10/2021.
 */

#include "sources/prototypes.h"
//respawn(){
//hashMAP[rows][column][2] -> {{idObjectToRespawn,0}{12,nbTourRespawn}{0,0}{0,0}{0,0}}
//le hashmap va permettre de reperer et stocker facilement les objets a respawn et le nombre de tours restant valeur par defaut
//dans le tableau sera 0,0. si la case est different de 0 regarder si nbTourRespawn-1 == 0, si oui mettre idObjectToRespawn = 0
//et faire respawn sur la map
//pour le cas ou le joueur quitte le jeu, verifier que toute les valeurs de idObjectToRespawn sont egale a 0, sinon le rajouter
//sur la map puis sauvegarder.
//pareil s'il change de zone #PotDeFleurZelda
//}

int main (int argc, char **argv){
    getMenu();
    return 0;
}
