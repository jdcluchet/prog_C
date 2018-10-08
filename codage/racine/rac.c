#include <stdio.h>
#include <math.h>

int main() {

    double deltaX;
    double deltaY;
    double normal;
    

    printf( "Veuillez saisir la première composante d'un vecteur : " );
    scanf( "%lf", &deltaX );
    printf( "Veuillez saisir la seconde composante d'un vecteur : " );
    scanf( "%lf", &deltaY );

    normal = sqrt( pow( deltaX, 2 ) + pow( deltaY, 2 ) );
    deltaX /= normal;
    deltaY /= normal;
    
    printf( "Le vecteur normalisé est [%5.2lf,%5.2lf]\n", deltaX, deltaY );
    
    return 0;
}

/*
Pour compiler cet exemple avec GCC :
    gcc -o Sample Sample.c  -lm
*/
