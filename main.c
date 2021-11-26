/*
 * This is the main file
 *
 * Created by William Lin,... and .... on 18/10/2021.
 */

#include <unistd.h>
#include "sources/prototypes.h"
#include <string.h>

int main (int argc, char **argv){
    chdirForMacUser(argv[0]);
    getMenu();
    return 0;
}
