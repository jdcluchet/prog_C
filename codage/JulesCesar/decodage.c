#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char*controle(char*message)
{
    int i=0,j,n=strlen(message);

    while(i<n)
    {    if ((message[i]<'A') || (message[i]>'Z') || (message[i]==' '))
         {   if((message[i]>='a') && (message[i]<='z'))
            { message[i]=message[i]-32;}
            else
                { for(j=i;j<n-1;j++)
                  {
                                message[j]=message[j+1];
                               
                  }n--;
                }
         }else i++;           
    }message[n]='\0';
   
    return(message);
}
 
void CESARcrypto (int cle, char *message)
{
     int i,n=strlen(message);

    for(i=0;i<n;i++)
    {
               
                message[i]='Z'+((message[i] - 'Z')-cle)%26;
   }
}
 
main()
{
      int k;
      char * message;
 
    printf("CRYPTAGE PAR SUBSTITUTION SELON JULES CESAR:\n\n");
   
    printf("Donner le message a crypter:\n");
    scanf("%s",message);
    message=controle(message);
    if(strlen(message)==0)
    {printf("ERREUR DE MESSAGE! REESSAYER!\n");}
    else
    {
    printf("Donner la clef du cryptage:\n");
    scanf("%d",&k);
                   if(k<0)
                   printf("ERREUR CLEF! VEUILLEZ RETAPEZ UNE CLEF CORRECTE (supérieure à 0)\n");
                   else
                   {
                       printf("Message a crypter: ");
                       puts(message);
                       printf("\n");
   
   
                       CESARcrypto(k,message);
                       printf("Message crypte: ");
                       puts(message);
                       printf("\n");
                    }
    }
 
/*    system("pause");*/
return (0);
}
