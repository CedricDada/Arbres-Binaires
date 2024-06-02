#include "fonctions arbres.h"

    void empilage(Pile *maPile,arbre *arbreEmpiler)
    {
        ElementP *nouveau = malloc(sizeof(ElementP));
        if(nouveau==NULL)
        {
            exit(EXIT_FAILURE);
            //EXIT_FAILURE pouvait etre remplacer par une autre valeur elle indique une au systeme une sortie anormale du programme
        }
        /*on stocke dans l'espace memoire demandée le nombre nombreEmpiler et l'adresse de l'element suivant(en descendant)
        l'adresse de l'element le plus haut de la Pile qui est maPile->premier(ou encore (*maPile).premier*/
        nouveau->arbreElt=arbreEmpiler;
        nouveau->Elt_suivant=maPile->premier;
        /*l'adressen de l'element le plus haut de la pile devient nouveau*/
        maPile->premier=nouveau;

    }
    arbre *depilage(Pile *maPile)
    {
        if(maPile==NULL||maPile->premier==NULL)
        {
            exit(EXIT_FAILURE);
        }
        arbre *arbreRetirer;
        //on stocke l'adresse de l'element le plus haut qui est à retirer
        ElementP *EltRetirer=maPile->premier;
        //j'affecte à nombreRetirer le nombre correspondant a l'adresse le plus haut de la pile
        arbreRetirer=EltRetirer->arbreElt;
        //l'adresse du nouveau element plus haut est EltRetirer->Elt_suivant
        maPile->premier=EltRetirer->Elt_suivant;
        //je libere l'espace memoire qui stocke le premier element de la pile
        free(EltRetirer);
        return arbreRetirer;
    }

arbre *newArbre()
{
    arbre *nouveau=malloc(sizeof(arbre));
    arbre *gauche=malloc(sizeof(arbre));
    arbre *droit=malloc(sizeof(arbre));
    int valArbre;
    int choix;
    //allocation reussie
    printf("Entrez nouvelle racine:");
    scanf("%d",&valArbre);
    nouveau->valeur=valArbre;
    nouveau->arbreGauche=NULL;
    nouveau->arbreDroit=NULL;
    printf("un element gauche?(1 pour oui)");
    scanf("%d",&choix);
    if(choix==1){
        printf("Entrez nouvelle racine");
        scanf("%d",&valArbre);
        gauche->valeur=valArbre;
        gauche->arbreDroit=NULL;
        gauche->arbreGauche=NULL;
        nouveau->arbreGauche=gauche;
        newArbre(nouveau->arbreGauche);
    }
    printf("un element droit?(1 pour oui)");
    scanf("%d",&choix);
    if(choix==1){
        droit->valeur=valArbre;
        droit->arbreDroit=NULL;
        droit->arbreGauche=NULL;
        nouveau->arbreDroit=droit;
        printf("Entrez nouvelle racine");
        scanf("%d",&valArbre);
        newArbre(nouveau->arbreDroit);
    }
return nouveau;
}
arbre *suppressionArbre(arbre *monArbre)
{
    if(monArbre==NULL)
        return;

    if(monArbre!=NULL)
    {
        printf("suppression de %d\n",monArbre->valeur);
    }
    suppressionArbre(monArbre->arbreDroit);
    suppressionArbre(monArbre->arbreGauche);
    free(monArbre);
    /*
    la recursivité se fait comme un empilage(on applique la fonction sur les deux parties de l'arbre dans la fonction meme
    et vu que suppressionArbre(monArbre->arbreGaucbe) et suppresionAbre(monArbre->arbreDroit) generent encore d'autres operations
    execution de la fonction sur monArbre est interompue
    on execute suppression(monArbre->arbreGauche) d'abord puis suppressionArbre(monArbre->arbreDroit)

    en fait a chaque fois on rappelle la fonction suppresionArbre sur les deux parties de l'arbre
    et il arrivera à la fin que monArbre->abreGauche et monArbre->arbreDroit soient NULL et
    a ce moment on return;(on bloque cette etape de la recursivité)
    et maintenant vu que l'execution de suppressionArbre(monArbre->arbreDroit) et suppressionArbre(monArbre->arbreDroit)
    sont terminés,
    on commencera à free(monArbre->arbreGauche) et puis free(monAbre->arbreDroit)
    puis remonter de pas à pas à monArbre
    jusqu'en haut
    */
}
void affArbrePrefixeIt(arbre *monArbre){
    Pile *maPile=malloc(sizeof(Pile));
    /*on met d'abord la racine dans la pile*/
    ElementP *racine=malloc(sizeof(ElementP));
    racine->arbreElt=monArbre;
    racine->Elt_suivant=NULL;
    maPile->premier=racine;
    /*la racine est dans la pile*/
    while(maPile->premier!=NULL){
    arbre *arbreS=depilage(maPile);
    printf("%d\n",arbreS->valeur);
    if(arbreS->arbreDroit!=NULL){
    empilage(maPile,arbreS->arbreDroit);
    }
    if(arbreS->arbreDroit!=NULL){
    empilage(maPile,arbreS->arbreGauche);
    }
    }
}
void affArbrePrefixe(arbre *monArbre)
{
    if(monArbre==NULL)
    {
        printf("\n");
        return;
    }
    //arbre non vide
    //affichage de l'étiquette de monArbre
    printf("%d\n",monArbre->valeur);
    affArbrePrefixe(monArbre->arbreGauche);
    affArbrePrefixe(monArbre->arbreDroit);

}
void affArbrePostfixe(arbre *monArbre)
{
    if(monArbre==NULL)
    {
        printf("\n");
        return;
    }
    //arbre non vide
    //affichage de l'étiquette de monArbre
    affArbrePrefixe(monArbre->arbreGauche);
    affArbrePrefixe(monArbre->arbreDroit);
    printf("%d\n",monArbre->valeur);

}
void affArbreInfixe(arbre *monArbre)
{
    if(monArbre==NULL)
    {
        printf("\n");
        return;
    }
    //arbre non vide
    //affichage de l'étiquette de monArbre
    affArbrePrefixe(monArbre->arbreGauche);
    printf("%d\n",monArbre->valeur);
    affArbrePrefixe(monArbre->arbreDroit);

}
int nbreEltsArbre(arbre *monArbre)
{
    int nbreElts,nbreG,nbreD;
    nbreElts=0,nbreD=0,nbreG=0;
    if(monArbre==NULL)
        return 0;
    nbreElts++;
    //j'incremente parceque je suis sur un element non nul

    nbreD=nbreEltsArbre(monArbre->arbreDroit);
    nbreG=nbreEltsArbre(monArbre->arbreGauche);
    nbreElts+=nbreD+nbreG;
    //on somme avec le nombre d'elements des deux autres parties
    return nbreElts;
}
void accederElt_ajoutD(arbre *monArbre,char adresse[],arbre *ajoutD)
{
    int taille=strlen(adresse);
    arbre *actuel = malloc(sizeof(arbre));
    actuel=monArbre;
    for(int i=0;i<taille;i++)
    {
        if(adresse[i]=='0'){
            if(actuel->arbreGauche==NULL)
            {
                printf("Adresse incorrecte \n");
                return;
            }
            actuel=actuel->arbreGauche;
        }
        else if(adresse[i]=='1')
        {
            if(actuel->arbreDroit==NULL)
            {
                printf("Adresse incorrecte \n");
                return;
            }
            actuel=actuel->arbreDroit;
        }
    }
    //on accede bien à notre element dont l'adresse est donnée en parametre
    printf("element de L'adresse [%s] : %d\n",adresse,actuel->valeur);
    actuel->arbreDroit=ajoutD;
    //ajoutD->parent=actuel;
}
