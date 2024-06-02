#include <stdio.h>
#include <stdlib.h>
#include "fonctions arbres.h"
int main()
{
    /*
    arbre *monArbre=newArbre(0);
    //EXIT_SUCCESS vaut 0 apparemment
    printf("%d\n",EXIT_SUCCESS);
    //EXIT_FAILURE vaut 1 apparemment
    printf("%d\n",EXIT_FAILURE);
    */
    arbre *monArbre=newArbre();
    affArbrePrefixeIt(monArbre);
    /*affArbrePrefixe(monArbre);
    affArbrePostfixe(monArbre);
    affArbreInfixe(monArbre);*/
    return 0;
}
