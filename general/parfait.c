#include <stdio.h>
#include <math.h>

#define nmax 300000

int main()
{int n, somme_diviseur, diviseur;
for(n=1; n<=nmax; n++)
	{
	somme_diviseur=0;
	for(diviseur=1; diviseur<=n/2; diviseur++)
		if(n%diviseur==0)
			somme_diviseur+=diviseur;
	if(somme_diviseur==n)
		printf("%d est un nombre parfait\n", n);
	}
}

