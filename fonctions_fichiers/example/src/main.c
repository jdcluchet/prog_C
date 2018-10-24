#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#define NOM_FICHIER argv[1]
#define NOMBRE_DE_CHAMPS 3

int main(int argc, char **argv)
{
	FILE *P_FICHIER; /* pointeur sur FILE */
	char  NOM_PERS[30], NOMBRE[5], ligne[80]="xx", preced[80];
	int  C,NB_ENREG;
	double  x[100];
	int i;

	char *token;
	const char s[2] = ",";
	char **ptr;
	char **fullfile[100];

	C=0;
	P_FICHIER = fopen(NOM_FICHIER, "r+");
	while(!feof(P_FICHIER))
	{
		ptr = malloc(sizeof(char *) * NOMBRE_DE_CHAMPS);
		strcpy(preced , ligne)   ;
		fgets(ligne, 40, P_FICHIER);
		if( strcmp (ligne,preced) == 0) break;

		printf("%s", ligne);

		/* get the first token */
		token = strtok(ligne, s);
		//printf( " %s\n", token );

		/* walk through other tokens */
		int j = 0;
		while( token != NULL ) {
			
			//printf( " %s\n", token );
			ptr[j] = malloc(sizeof(char) * strlen(token));
			strcpy(ptr[j], token);
			token = strtok(NULL, s);
			j++;
		}
		fullfile[C] = ptr;
		x[C]=(atof(ptr[1]));
		C++;
	}


	affichage(fullfile,x,C);
	/*
	i=0;
	while (i < C) {
		printf("\nFullfile case [%d]:\n",i);
		printf("Case [0]: %s\n",fullfile[i][0]);
		printf("Case [1]: %s\n",fullfile[i][1]);
		printf("Case [2]: %s\n",fullfile[i][2]);
		printf ("Chiffre: %.2f  \n",x[i]);
		i++; }
		*/
	printf("\n");
	printf("%s%d\n","nombre de lignes:   ",C) ;
	fclose(P_FICHIER);
	return 0;
}
