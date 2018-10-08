#include <stdlib.h>
#include <stdio.h>
#include "produit.h"

int main()
{
    int c,d;
    printf ("\n inserer c,d");
    printf("\nc = "); scanf("%i", &c);
    printf("\nd = "); scanf("%i", &d);
    printf("\nResultat:  ");
    printf("\n%i",(produit(c,d)));
} 

