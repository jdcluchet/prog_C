#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main() {

char *token;
char line[] ="LINE TO BE SEPARATED ";
char *search = " ";

token = strtok (line, search);
printf("%s\n",token);
token = strtok (NULL, search);
printf("%s\n",token);
token = strtok (NULL, search);
printf("%s\n",token);
token = strtok (NULL, search);
printf("%s\n",token);
}

