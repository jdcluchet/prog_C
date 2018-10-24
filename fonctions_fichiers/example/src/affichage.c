#include "header.h"

void	affichage(char **fullfile[100], double x[100], int C)
{
	int	i=0;
	while (i < C) 
	{
		printf("\nFullfile case [%d]:\n",i);
		printf("Case [0]: %s\n",fullfile[i][0]);
		printf("Case [1]: %s\n",fullfile[i][1]);
		printf("Case [2]: %s\n",fullfile[i][2]);
		printf ("Chiffre: %.2f  \n",x[i]);
		i++; 
	}
}
