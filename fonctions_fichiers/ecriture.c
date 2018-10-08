#include <stdio.h>
#include <stdlib.h>

#define NB 50
#define F_SORTIE "sortie"

int main(void)
{
  FILE *f_in, *f_out;
  int *tab1, *tab2;
  int i;

  tab1 = (int*)malloc(NB * sizeof(int));
  tab2 = (int*)malloc(NB * sizeof(int));
  for (i = 0 ; i < NB; i++)
    tab1[i] = i;

  /* ecriture du tableau dans F_SORTIE */
  if ((f_out = fopen(F_SORTIE, "w")) == NULL)
    {
      fprintf(stderr, "\nImpossible d'ecrire dans le fichier %s\n",F_SORTIE);
      return(EXIT_FAILURE);
    }
  fwrite(tab1, NB * sizeof(int), 1, f_out);
  fclose(f_out);

  /* lecture dans F_SORTIE */
  if ((f_in = fopen(F_SORTIE, "r")) == NULL)
    {
      fprintf(stderr, "\nImpossible de lire dans le fichier %s\n",F_SORTIE);
      return(EXIT_FAILURE);
    }
  fread(tab2, NB * sizeof(int), 1, f_in);
  fclose(f_in);
  for (i = 0 ; i < NB; i++)
    printf("%d\t",tab2[i]);
  printf("\n");
  return(EXIT_SUCCESS);
}
