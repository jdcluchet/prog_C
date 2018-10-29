#include <string.h>
#include <stdio.h>
#include <stdlib.h>
int main()
{

    FILE *P_FICHIER; /* pointeur sur FILE */
    char nom_fichier[30], mot[30], nombre[30],
    ligne[40]="xxx",preced[40],chaine[40];
    int  C,nb_enreg,x,j;
    const char s=' ';
    const char t[2] = "*";
    char *ret;
    char *rit;
    char *rite;
    int esp;  
    double result[1000];
    double res[1000];
    /* Première partie : 
       rappeler le fichier a ecrire*/
    printf("Entrez le nom du fichier à traiter : ");
    scanf("%s", nom_fichier);
    P_FICHIER = fopen(nom_fichier, "a");  /* write a la fin*/
    printf("Nombre d'enregistrements à créer : ");
    scanf("%d", &nb_enreg);
    C = 0;
    while (C<nb_enreg)
    { 
	printf("Le terme à entrer (suivi de *collé) et le nombre avec un espace: ");
	scanf("%s%s", mot,nombre);
	system ("clear");
	/*  printf("%s",mot);*/
	fprintf(P_FICHIER, "%s", mot);
	fprintf(P_FICHIER,"%c",32);fprintf(P_FICHIER,"%c",32);
	fprintf(P_FICHIER, "%s\n",  nombre);
	C++;
    }
    fclose(P_FICHIER);

    /* Deuxième partie : 
       Lire et afficher le contenu du fichier */
    C=0;
    P_FICHIER = fopen(nom_fichier, "r+");
    while(!feof(P_FICHIER)) {
	/* conditions du break */

	strcpy(preced , ligne)   ;
	fgets(ligne, 40, P_FICHIER);
	if( strcmp (ligne,preced) == 0) break;

	/*---------------------*/
	ret = strchr(ligne ,s);
	rite = strtok(ligne ,t);
	result[C]= atof(ret);
	x= strlen(rite);
	/*---------------------*/
	/* printf("%s",rite); printf("\t\t");printf("%.2f\n",result[C]);
	   else{
	   printf("%s",rite);printf("\t\t"); printf("%.2f\n",result[C]);}*/
	j=0;
	esp= 18-x;
	printf("%s",rite);
	for  (j=0;j<esp;j++){
	    printf("%s"," ");}  
	printf("%.2f\n",result[C]);

	C++;
    } 
  printf("%s\n","-------------------------------------------");
  printf("%s%d\n\n","nombre de lignes:   ",C) ;
} 
