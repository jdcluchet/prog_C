#include<stdio.h>
  2 #include<stdlib.h>
  3 #include<ncurses.h>
  4 
  5 #define ESC 27      /* Code ASCII de "echap" */
  6 
  7 int main()
  8 {
  9     int c;
 10     initscr();     /* entrer en mode CURSES */
 11     cbreak();      /* desactive le "line buffering" lire sans attendre le retour chariot */
 12     noecho();      /* desactive l'affichage des touches imprimable ,l'activation se 
 13                       se fait par l'appelle echo(); */
 14     keypad(stdscr, TRUE); /* pour "etendre" l'appui sur la touche echap */
 15 
 16     printw("Press Any Key ...\n");
 17     refresh();     /* Rafraichis la fenêtre afin d'afficher le message */ 
 18     do
 19     {
 20         c=getch();
 21     }while( c != ESC );
 22 
 23     endwin();       /* quitter le mode CURSES proprement */
 24     return EXIT_SUCCESS;
 25 }
