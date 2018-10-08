#include <stdio.h>
    #include <stdlib.h>
    #include <ncurses.h>
    int main(void)
    {
            int prix,touche,intro;
            prix=4;
            intro=0;
            printf("_____________________________\n" );
            printf("[  2e   ] [  1e   ] [ 50cts ]\n" ); //touches 4 5 6 du pad
            printf("[ 20cts ] [ 10cts ] [ 5cts  ]\n" ); //touches 1 2 3 du pad
            printf("_____________________________\n" );
            do
            {
                    touche=getch();
                    switch(touche)
                    {
                            case 4: { intro=intro+2;printf("piece de 2e ok\n" );break; }
                            case 5: { intro=intro+1;printf("piece de 1e ok\n" );break; }
                    }
            } while (intro > prix);
            return 0;
    }
