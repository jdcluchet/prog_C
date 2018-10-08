#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{

    int nombreJoueur1 = 0, nombreMystere = 0, replay = 0, menu1 = 0, difficult = 0, coups = 0;
    const int Min = 1;
    srand(time(NULL));

    do
    {

	menu1 = 0, difficult = 0, replay = 0, coups = 0;

	while (menu1 < 1 || menu1 > 2)
	{
	    printf("********Bonjour, Bienvenue dans Plus ou Moins !********\n\n");
	    printf("Vous Allez devoir Trouver un Nombre suivant les paramètres que vous aurez choisi.\n");
	    printf("Par la suite, je vous indiquerai si votre numéro est Supérieur ou Inférieur au numéro à trouver\n\n");
	    printf("Avant tout, souhaitez-vous faire une partie:\n\n");
	    printf("En solitaire, Tapez 1\n");
	    printf("A deux Joueurs, Tapez 2\n\n");
	    scanf("%d", &menu1);
	}

	while (difficult < 1 || difficult > 3)
	{
	    printf("Choississez Maintenant un niveau de difficulté parmis les suivant:\n\n");
	    printf("Chercher un nombre entre 1 et 100, Tapez 1\n");
	    printf("Chercher un nombre entre 1 et 1000, Tapez 2\n");
	    printf("Cherchez un nombre entre 1 et 10000, Tapez 3\n\n");
	    scanf("%d", &difficult);
	}

	if (menu1 == 1 && difficult == 1)
	{
	    printf("Ok, Nous allons jouer enssemble.\n\n");
	    printf("Je vais choisir un nombre entre 1 et 100\n\n");
	    nombreMystere = (rand() % (100 - Min + 1)) + 1;
	    printf("Tapez un nombre entre 1 et 100\n\n");
	}

	else if (menu1 == 1 && difficult == 2)
	{
	    printf("Ok, Nous allons jouer enssemble.\n\n");
	    printf("Je vais choisir un nombre entre 1 et 1000\n\n");
	    nombreMystere = (rand() % (1000 - Min + 1)) + 1;
	    printf("Tapez un nombre entre 1 et 1000\n\n");
	}

	else if (menu1 == 1 && difficult == 3)
	{
	    printf("Ok, Nous allons jouer enssemble.\n\n");
	    printf("Je vais choisir un nombre entre 1 et 10000\n\n");
	    nombreMystere = (rand() % (10000 - Min + 1)) + 1;
	    printf("Tapez un nombre entre 1 et 10000\n\n");
	}

	else if (menu1 == 2 && difficult == 1)
	{
	    printf("Ok, Le Joueur 2 devra entrer un nombre et le Joueur 1 devra devinez celui-ci.\n\n");
	    printf("Joueur 2, Tapez un nombre entre 1 et 100\n\n");
	    scanf("%d", &nombreMystere);
	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    printf("Joueur 1 à vous de jouer, Trouvez le nombre du Joueur 2 entre 1 et 100\n\n");
	}

	else if (menu1 == 2 && difficult == 2)
	{
	    printf("Ok, Le Joueur 2 devra entrer un nombre et le Joueur 1 devra devinez celui-ci.\n\n");
	    printf("Joueur 2, Tapez un nombre entre 1 et 1000\n\n");
	    scanf("%d", &nombreMystere);
	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    printf("Joueur 1 à vous de jouer, Trouvez le nombre du Joueur 2 entre 1 et 1000\n\n");
	}

	else
	{
	    printf("Ok, Le Joueur 2 devra entrer un nombre et le Joueur 1 devra devinez celui-ci.\n");
	    printf("Joueur 2, Tapez un nombre entre 1 et 10000\n\n");
	    scanf("%d", &nombreMystere);
	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	    printf("Joueur 1 à vous de jouer, Trouvez le nombre du Joueur 2 entre 1 et 10000\n\n");
	}

	do
	{
	    scanf("%d", &nombreJoueur1);
	    coups++;

	    if (nombreJoueur1 < nombreMystere)
	    {
		printf("\n\nVotre numéro %d est Inférieur au nombre Mystère\n\n", nombreJoueur1);
		printf("Tapez un nombre Supérieur\n\n");
	    }

	    else if (nombreJoueur1 > nombreMystere)
	    {
		printf("\nVotre numéro %d est Supérieur au nombre Mystère\n\n", nombreJoueur1);
		printf("Tapez un nombre Inférieur\n\n");
	    }
	    else
		printf("\nBravo!!! Vous avez trouvé le bon numéro en %d coup(s). Le nombre Mystère était bien le %d.\n\n", coups, nombreMystere);

	}while (nombreJoueur1 != nombreMystere);

	while (replay < 1 || replay > 2)
	{
	    printf("Voulez-vous rejouer?\n\n");
	    printf("Oui, Tapez 1\n");
	    printf("Non,Tapez 2\n\n");
	    scanf("%d", &replay);
	}
    }while (replay == 1);

    printf("\n********Au revoir et à bientôt !!********\n\n");


    return 0;
}
