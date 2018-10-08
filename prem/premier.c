
#include <stdio.h>

void main()
{ int A,I,R;
  int Premier;


printf("Saisir un nombre entier positif \n");
scanf("%d",&A);


  if (A==1)

 { printf("Votre nombre n'est pas premier \n");
 }

 else
  {
   if((A==2) && (A==3))
     printf("votre nombre est premier \n");
    }
  for(I=1;I<=A/2;I++)
   {
   R=A%I;
I=A/2;
   if ((R==0)&&(I!=2))

      Premier=0;
   else
    {Premier=1;}

   if (Premier=0)
     printf("Votre nombre n'est pas premier \n");
    else { printf("Votre nombre est premier");
   }

  }

    }

