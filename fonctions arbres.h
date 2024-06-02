#ifndef FONCTIONS_ARBRES
#define FONCTIONS_ARBRES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
    //--------------------ARBRE BINAIRE-----------------------------------------
    typedef struct arbre arbre;
    struct arbre{
        int valeur;
        arbre *arbreGauche;
        arbre *arbreDroit;
    };
    typedef enum boole{
        false,true
    }boole;

   /*chaque element de la pile est caracterisé par une valeur(entiere) et un pointeur vers l'element suivant*/
    typedef struct ElementP ElementP;
    struct ElementP
    {
        arbre *arbreElt;
        ElementP *Elt_suivant;
    };
    /*Une pile est caracterisé par un pointeur vers l'element le plus haut*/
    typedef struct Pile Pile;
    struct Pile
    {
        ElementP *premier;
    };

#endif // FONCTIONS_ARBRES
