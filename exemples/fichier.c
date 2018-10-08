#include <stdio.h>

int main()
{
    FILE *P_FICHIER; /* pointeur sur FILE */
    char NOM_FICHIER[30], NOM_PERS[30];
    int  C,NB_ENREG;

    /* Première partie : 
       Créer et remplir le fichier */
    printf("Entrez le nom du fichier à créer : ");
    scanf("%s", NOM_FICHIER);
    P_FICHIER = fopen(NOM_FICHIER, "w");  /* write */
    printf("Nombre d'enregistrements à créer : ");
    scanf("%d", &NB_ENREG);
    C = 0;
    while (C<NB_ENREG)
    { 
	printf("Entrez le nom de la personne : ");
	scanf("%s", NOM_PERS);
	fprintf(P_FICHIER, "%s\n", NOM_PERS);
	C++;
    }
    fclose(P_FICHIER);

    /* Deuxième partie : 
       Lire et afficher le contenu du fichier */
    P_FICHIER = fopen(NOM_FICHIER, "r");  /* read */
    C = 0;
    while (!feof(P_FICHIER))
    {
	fscanf(P_FICHIER, "%s\n", NOM_PERS);
	printf("NOM : %s\n", NOM_PERS);
	C++;
    }
    fclose(P_FICHIER);
    return 0;
} 
