#include <stdio.h>
#include <stdlib.h>
/*************************************************************************
Résolution simplifiée d'une équation du second degré 6/03/08
L'équation est imposée : Ax^2+Bx+C=0
**************************************************************************/
/* inclusion des fichiers en‐tête nécessaires */
#include <math.h> /* contient la déclaration de sqrt */
#include <stdio.h>
/* Définition des constantes symboliques */
#define EPS 1e-10 /* constante "très petite" pour la comparaison de delta avec 0. */
/* Déclaration des fonctions utilisées (« prototypes » = mode d’emploi) : */
double calculer_delta( double a, double b, double c ) ;
int calculer_nb_solutions( double delta ) ;
void calculer_afficher_solutions( double a, double b, double c, int nb_sol,
                                  double delta ) ;
void afficher_coeff( double a, double b, double c ) ;
double saisir_reel( char * message );
/*‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
Programme principal : fonction main
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐*/
void main(void)
{
    /* définition des variables locales de main */
    double a, b, c ; /* coefficients réels de l’équation */
    double delta ;
    int nb_sol_reelles ;
    /* Première partie du programme, réalisée et testée avant de poursuivre : */
    /* l’ équation est imposée par l’initialisation des données de test (sans saisie au clavier) : */
    a=-1.0 ;
    b=-0.5 ;
    c=-5.0 ; /* on modifie ensuite ces valeurs pour effectuer d’autres tests */
    afficher_coeff ( a, b, c ) ;
    delta = calculer_delta( a, b, c ) ;
    nb_sol_reelles = calculer_nb_solutions( delta ) ;
    calculer_afficher_solutions ( a, b, c, nb_sol_reelles, delta );
    /* Suite du programme (après test complet de la première partie) : */
    /* l’ équation est choisie par l’utilisateur avec une saisie au clavier : */
    a = saisir_reel("\n\t\t Nouvelle equation :\n\nTapez a :");
    b = saisir_reel("Tapez b :");
    c = saisir_reel("Tapez c :");
    delta = calculer_delta( a, b, c ) ;
    nb_sol_reelles = calculer_nb_solutions( delta ) ;
    calculer_afficher_solutions ( a,b, c, nb_sol_reelles, delta );
}
/*‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
Fonction calculer_delta
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐*/
double calculer_delta( double a, double b, double c )
{
    return b*b - 4.*a*c ;
}
/*‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
Fonction calculer_nb_solutions
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐*/
int calculer_nb_solutions( double d )
{
    int nb_sol ;
    if ( d > EPS ) nb_sol = 2 ; /* deux solutions reelles */
    else if ( d < -EPS ) nb_sol = 0 ; /* pas de solutions reelles */
    else nb_sol = 1 ; /* une solution reelle double */
    return nb_sol ;
}
/*‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
Fonction afficher_coeff
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐*/
void afficher_coeff( double a, double b, double c )
{
    printf("\t\t Resolution simplifiee d'une equation du second degre :\n");
    printf("\t\t Coefficients : a = %lf - b = %lf - c = %lf \n\n", a, b, c );
}
/*‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
Fonction calculer_afficher_solutions
‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐*/
void calculer_afficher_solutions( double a, double b, double c, int nb_sol,
                                  double delta )
{
    double rac, x1, x2 ; /* variables locales de la fonction */
    switch (nb_sol) /* instruction qui permet le choix multiple */
    {
    case 0 :
        printf(" \n Pas de solutions reelles.\n") ;
        break ;
    case 1 :
        printf("\n Une solution double: %lf\n", -b/(2.*a) ) ;
        break ;
    case 2 :
        rac = sqrt(delta) ;
        x1 = (-b-rac)/(2.*a);
        x2 = (-b+rac)/(2.*a);
        printf("\n Solution 1 : %lf", x1 ) ;
        printf("\n Solution 2 : %lf\n", x2 ) ;
        break ;
    }
}
/*‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐‐
Fonction saisir_reel
---------------------------------------------------------------------------*/
double saisir_reel( char * message )
{
    double reel = 1.0 ;
    printf( "%s ", message );
    scanf("%lf", &reel );
    return reel;
}
