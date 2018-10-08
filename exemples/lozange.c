/*
  Name: tp6 - ex1b
  Copyright: b1-1
  Author: ARCHAMBEAU
  Date: 13/09/06 14:07
  Description: calcul géométrique (surface rectangle ; surface losange : surface ellipse)
               deuxième méthode
*/

#include <stdio.h>
#include <stdlib.h>
/*include <conio.h>*/
#define PI 3.14159

double surface (double longueur, double largeur, char nature); /*prototype*/
int main(void)
 {
     double lo,  /*longueur*/
            la,  /*largueur*/
            sr,  /*surface rectangle*/
            sl,  /*surface losange*/
            se;  /*surface ellipse*/
     
     printf("BRICOLO GEOMETRIQUE\n");
     printf("Soit un rectangle R.\nEntrez sa longueur (en m): ");
     scanf("%lf", &lo);
     printf("Entrez sa largeur (en m): ");
     scanf("%lf", &la);
     
     sr = surface (lo,la,'R'); /* appel à la fonction surface()*/
     sl = surface (lo,la,'L'); /* appel à la fonction surface()*/
     se = surface (lo,la,'E'); /* appel à la fonction surface()*/
     
     printf("\n\nLa surface du rectangle R est: %lf\n", sr);
     printf("La surface du losange dans R est: %lf\n", sl);
     printf("La surface de l'ellipse dans R est: %lf\n", se);
     

     return 0;
 }

double surface (double longueur, double largeur, char nature) /*en tête*/
{
     double temp;
     
     switch(nature)
     {
       case'R': temp = longueur*largeur;
                break;
       case'L': temp = longueur*largeur*.5;
                break;
       case'E': temp = longueur*largeur*PI*.25;
     }
     return (temp);
}
