/*cryptage et décryptage de fichiers texte
*/

#include <stdio.h>
#include <stdlib.h>
/*#include "conio.h"
#include <ncurses.h>*/
#define maxi 10
#define maxicle 15

void technique_de_Cesar();
char crypt_Cesar(char t[maxi]);
char decrypt_Cesar(char t[maxi]);
void cle_cryptage();
char crypt_cle(char t[maxi], char c2[maxi]);
char decrypt_cle(char t[maxi], char c2[maxi]);

void main()
{
int m;
char choix='o';

while (choix=='o') // choix de la méthode
{
printf("\nCryptage et décryptage de fichiers texte\n");
printf("\nChoisir méthode de codage:\n");
printf("\n0: Technique de César\n");
printf("\n1: Clé de cryptage\n");
scanf("%d",&m);
getchar();

if(m==0)
{
technique_de_Cesar();
}
else
{
if(m==1)
{
cle_cryptage();
}
else
{
printf("\nERREUR!!!\n");
}
}
printf("Voulez-vous recommencer?(o/n)");
scanf("%c",&choix);
}
fflush(stdin);
getchar();
}

void technique_de_Cesar()
{
char fichier1[]="C:\Texte.c";
char fichier2[]="C:\Permut.txt";
char fichier3[]="C:\Permut2.txt";
int p1, p2;
int i;
FILE *file1, *file2, *file3;
char c;
char t[maxi];

printf("\nVoulez-vous:\n"); // choix méthode cryptage
printf("\n2: Ecrire la chaîne de caractères?\n");
printf("\n3: La lire à partir d'un fichier?\n");
scanf("%d",&p1);

if(p1==2)
{
printf("\nEntrer chaîne de caractères:\n");
scanf("%s", &t);
}
else
{
if(p1==3)
{
file1=fopen(fichier1, "r");
fscanf(file1,"%s\n" ,&t);

if(!file1)
{
printf("\nErreur à l'ouverture du fichier!\n");
exit(-1);
}
}
else
{
printf("\nERREUR!!!!\n");
}
}
for(i=0; i<maxi; i++)
{
printf("\nSouhaitez-vous:\n");
printf("\n4: Crypter la chaîne de caractères?\n");
printf("\n5: Décrypter la chaîne de caractères?\n");
scanf("%d",&p2);


if(p2==4)
{
crypt_Cesar(t);
}
else
{
if(p2==5)
{
decrypt_Cesar(t);
}
else
{
printf("\nERREUR!!!\n");
}
}
}
fflush(stdin);
getchar();
}

char crypt_Cesar(char t[maxi])
{

char fichier2[]="C:\Permut.txt";

FILE *file2;
int i=0;

/* Ouverture en lecture */
file2=fopen(fichier2, "r");

if(!file2)
{
printf("\nErreur à l'ouverture du fichier!\n");
exit(-1);
}

while(!feof(file2))
{
for(i=0; i<30; i++)
{
printf("\nVoici le texte crypté:\n");
fscanf(file2, "%s");
i++;
}
}
fclose(file2);
fflush(stdin);
getchar();
}

char decrypt_Cesar(char t[maxi])
{
char fichier3[]="C:\Permut2.txt";
int i=0;
char c;
FILE *file3;
file3=fopen(fichier3, "r");

if(!file3)
{
printf("\nErreur à l'ouverture du fichier!\n");
exit(-1);
}

while(!feof)
{
for(i=0; i<30; i++)
{
printf("\nVoici le texte décrypté: %s\n");
fscanf(file3, "%s\n", t);
i++;
}
}
fclose(file3);
fflush(stdin);
getchar();
}

void cle_cryptage()
{
int p3, p4;
int i;
FILE *file1;
char fichier1[]="C:\Texte.c";
char c2[maxicle], t[maxi];

printf("\nVoulez-vous:\n");
printf("\n6: Ecrire la chaîne de caractères?\n");
printf("\n7: La lire à partir d'un fichier?\n");
scanf("%d",&p3);

if(p3==6)
{
printf("\nEntrer chaîne de caractères:\n");
scanf("%s", t[i]);
}
else
{
if(p3==7)
{
file1=fopen(fichier1, "r");
fscanf(file1, "%s", &t);
}
else
{
printf("\nERREUR!!!!\n");
}
}

if(!file1)
{
printf("\nErreur à l'ouverture du fichier!\n");
exit(-1);
}

for(i=0;i<maxi;i++)
{
printf("\nVoulez-vous:\n");
printf("\n8: Crypter la chaine de caractères?\n");
printf("\n9: Décrypter la chaîne de caractères?\n");
scanf("%d",&p4);

if(p4==8)
{
crypt_cle(t, c2);
}
else
{
if(p4==9)
{
decrypt_cle(t, c2);
}
else
{
printf("\nERREUR!!!\n");
}
}
}
fflush(stdin);
getchar();
}

char crypt_cle(char t[maxi], char c2[maxi])
{
int i=0,j=0;
char c[maxicle]; // clé de cryptage

printf("\nEntrer clé de cryptage:\n");
scanf("%s",&c);

for(i=0; i<maxi; i=i+1)
{

c2[i] = t[i] + c[j]; // texte crypté
j++;
}
if (j>=maxicle)
{
j=0;
}
printf("\nVoici le texte crypté: %s\n", c2);
fflush(stdin);
getchar();
}

char decrypt_cle(char t[maxi], char c2[maxi])
{
int i=0, j=maxicle;
char c[maxicle];

for(i=0; i<maxi; i--)
{
t[i] = c2[i] - c[j]; // texte décrypté
j--;
}
printf("\nVoici le texte décrypté:%s\n", t);
fflush(stdin);
getchar();
} 
