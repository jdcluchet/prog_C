#include <stdio.h>
#include <math.h>
 
int main()
{
  long n, t, r = 0, c, d;
 
  printf("Enter an integer\n");
  scanf("%ld", &n);
 
  while (1)
  {
    n++;
    t = n;
 
    // Calculating reverse of the number
 
    while(t)
    {
      r = r*10; 
      r = r + t%10;
      t = t/10;
    }
 
    // If reverse equals original then it is a palindrome
 
    if (r == n)
    {
      d = (int)sqrt(n);
 
      /* Checking prime */
 
      for (c = 2; c <= d; c++)
      {
        if (n%c == 0)
          break;
      }
      if (c == d+1)
        break;
    }
    r = 0;
  }
 
  printf("%ld\n",n);
 
  return 0;
}
