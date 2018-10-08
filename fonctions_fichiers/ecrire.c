#include <string.h>
#include <stdio.h>

int main()
{
    FILE *P_FICHIER; /* pointeur sur FILE */
    char NOM_FICHIER[30],  NOM_PERS[30], NOMBRE[5], ligne[40]="xxx",preced[40];
    int  C,NB_ENREG;

    /* Première partie : 
      rappeler le fichier a ecrire*/
    printf("Entrez le nom du fichier à modifier : ");
    scanf("%s", NOM_FICHIER);
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
        C++;
}   
    printf("%s%d\n","nombre de lignes:   ",C-1) ;
    fclose(P_FICHIER);
    return 0;
} 
 
