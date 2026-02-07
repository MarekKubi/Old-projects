#pragma once
#include <stdlib.h>
#include <stdio.h>

typedef struct element_listy* wsk_el_list;

typedef struct element_listy{
  char* nazwa_wezla;
  int klucz;
  wsk_el_list nastepny_wezel; // wskaźnik do kolejnego elementu
} el_list;

int wstaw_na_poczatek( /* funkcja zwraca kod sukcesu lub bledu */
  el_list** Glowa_wsk, /* lista - identyfikowana przez wskaznik */ 
  el_list* Element_wsk     /* wskaznik do elementu wstawianego na liste */
		       );

void drukuj_lista( /* funkcja zwraca kod sukcesu lub bledu */
  el_list* Glowa   /* lista - identyfikowana przez wskaznik */ 
		   );
int usun_lista(     /* procedura zwraca kod sukcesu lub bledu */
  el_list** Glowa_wsk,   /* lista - identyfikowana przez wskaznik */ 
  el_list*  Element_wsk  /* wskaznik do elementu usuwanego z listy */
		    );

 

