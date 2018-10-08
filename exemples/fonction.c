#include <stdio.h> 
int polynome(int x) ;  /* 
on déclare la fonction avant le 
main()
*/ 
  int x;
  int y; 
int main(){
  for(x=-5 ; x<=5 ; x++)  { y = polynome(x) ;   printf("x=%d    y=%d \n",x,y);} 
  return 0 ; 
} 
int polynome(int x) 
  { int valeur ; 
     valeur = (x*x*x -2*x*x +4*x-3) ; 
     return valeur ; 
  } 

