//#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//using namespace std;

int codec2n(char c){
  int i=c;
  switch (c){
  case  '\'e':
    i=100; 
    break;
  case '\`e':
    i=99;
    break;
  case '\`a':
    i=98;
    break;
  case '\c{c}':
    i=97;
    break;
  case '\`u':
    i=96;
    break;
  case '\^e':
    i=95;
    break;
  default:
    i -= 32;
  }
  return i;
}

char coden2c(int i){
  if (i<95)
    return i+32;
  switch (i){
  case 95:
    return '\^e';
  case 96:
    return '\`u';
  case 97:
    return '\c{c}';
  case 98:
    return '\`a';
  case 99:
    return '\`e';
  case 100:
    return '\'e';
  }
}

int main(int argc,char ** argv){
  char * s=0,ch;
  size_t n=0;
  int i,d,fois;
  if (!strcmp(argv[0],"./table")){
    for (i=0;i<101;++i){
      ch=coden2c(i);
      printf("%d:%c &",i,ch);
      if (i%10==0)
 printf("\n");
    }
    return 0;
  }
  if (!strcmp(argv[0],"./coden2c")){
    for (i=1;i<argc;++i){
      d=atoi(argv[i]);
      ch=coden2c(d);
      printf("%c",ch);
    }
    printf("\n");
    return 0;
  }
  if (argc==3)
    fois=atoi(argv[2]);
  else
    fois=0;
  if (argc>=2){
    s=argv[1];
    n=strlen(s);
  }
  else {
    printf("Entrez un message \`a num\'eriser\n");
    getline(&s,&n,stdin);
    n=strlen(s)-1;
  }
  for (i=0;i<n;++i){
    d=codec2n(s[i]);
    if (fois)
      printf("%c",coden2c(d*fois % 101));
    else
      printf("%d ",d);
  }
  printf("\n");
  return 0;
}

