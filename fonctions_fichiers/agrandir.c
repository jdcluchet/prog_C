#include <stdio.h>
#define NOM_FICHIER "semaine.txt"

int main()
{
    FILE *P_FICHIER; /* pointeur sur FILE */
    char  NOM_PERS[30], NOMBRE[5];
    int  C,NB_ENREG;

    /* Première partie : 
      rappeler le fichier a ecrire*/
 /*   printf("Entrez le nom du fichier à modifier : ");
    scanf("%s", NOM_FICHIER);*/
goto lire;
printf("%s\n",NOM_FICHIER);
    P_FICHIER = fopen(NOM_FICHIER, "a");  /* write a la fin*/
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

    /* Deuxième partie : 
       Lire et afficher le contenu du fichier */
    P_FICHIER = fopen(NOM_FICHIER, "r");  /* read */
    C = 0;
    while (!feof(P_FICHIER))
    {
	fscanf(P_FICHIER, "%s\n", NOM_PERS);
	printf("%s\n", NOM_PERS);
	C++;
    }
    fclose(P_FICHIER);
    return 0;
} 
