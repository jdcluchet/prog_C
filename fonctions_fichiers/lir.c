#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOM_FICHIER "essai.txt"

int main()
{
    FILE *P_FICHIER; /* pointeur sur FILE */
    char  NOM_PERS[30], NOMBRE[5], ligne[80]="xx", preced[80];
    int  C,NB_ENREG;
   double  x[100];
    int i;

    /* Première partie : 
      rappeler le fichier a ecrire*/
/*
goto ligne;
printf("%s\n",NOM_FICHIER);
    P_FICHIER = fopen(NOM_FICHIER, "a");  // write a la fin
    printf("Nombre d'enregistrements à créer : ");
    scanf("%d", &NB_ENREG);
    C = 0;
    while (C<NB_ENREG)
    { 
	printf("Entrez le nom de la personne : ");
	scanf("%s%s", NOM_PERS, NOMBRE);
	fprintf(P_FICHIER, "%s", NOM_PERS);
        fprintf(P_FICHIER,"%c",32);fprintf(P_FICHIER,"%c",32);
        fprintf(P_FICHIER, "%s\n",  NOMBRE);
	C++;
    }
    fclose(P_FICHIER);

lire:
*/

    /* Deuxième partie : 
       Lire et afficher le contenu du fichier */
C=0;
P_FICHIER = fopen(NOM_FICHIER, "r+");
        while(!feof(P_FICHIER))
{
       strcpy(preced , ligne)   ;
            fgets(ligne, 40, P_FICHIER);
      if( strcmp (ligne,preced) == 0) break;
      
      printf("%s", ligne);
      x[C]=(atof(ligne));
     C++;
}
i=0;
while (i < C) {
       printf ("%.2f  \t",x[i]);
       i++; }
       printf("\n");
    printf("%s%d\n","nombre de lignes:   ",C) ;
    fclose(P_FICHIER);
    return 0;
}
