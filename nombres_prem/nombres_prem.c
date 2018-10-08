#include <stdio.h>
                #include <stdlib.h>

               long  main()
                {
                    
		long i,j,n_diviseurs;
                     
                    for(i=0;i<=3000000;i++)
 
                    {   n_diviseurs=0;
 
                        for(j=1;j<=i;j++)
                        {
                          if(i%j==0)
 
                          n_diviseurs=n_diviseurs+1;
 
                         }
                          
                         if(n_diviseurs<=2)
 
                         printf("%ld est premier\n ", i);
                     }
                     return 0;
 
                  }
