#define _GNU_SOURCE
#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <sched.h>
#include <linux/sched.h>

#include"pomiar_czasu.h"
int zmienna_globalna=0;
int zmienna_globalna2=0;

#define ROZMIAR_STOSU 1024*64



int funkcja_watku( void* arg )
{
int i;
int zmienna_lokalna = 0;
  //int zmienna_lokalna = *(int*)argument;
for(i=0; i<100000;i++)
{
  zmienna_lokalna++;
  zmienna_globalna++;
}
   //zmienna_globalna = zmienna_lokalna;
   *(int*)arg += zmienna_lokalna;
printf("Clone nr: %d\n",zmienna_globalna);  
printf("zmienna ll: %d    clone %d\n", zmienna_lokalna,zmienna_globalna2);
printf("zmienna gl: %d    clone %d\n",zmienna_globalna,zmienna_globalna2);
zmienna_globalna2++;
  return 0;
}/**/
/*
wynik=execv("./program",NULL);
if(wynik==-1)
{								Marek Kubicki
printf("Proces potomny nie wykonal programu\n");
}/**/
  /* int wynik; */
  /* wynik=execv("./program",NULL); */
  /* if(wynik==-1) */
  /*   printf("Proces potomny nie wykonal programu\n"); */

/*
int funkcja_watku( )
{
zmienna_globalna++;
return 0;
}*/

int main()
{

  void *stos;
  void *tab[2];
  void *stos2;
  pid_t pid;
  pid_t pid2;
  int i; 
  int mai =0;
  stos = malloc( ROZMIAR_STOSU );
  stos2 = malloc( ROZMIAR_STOSU );
  if (stos == 0) {
    printf("Proces nadrzędny - blad alokacji stosu\n");
    exit( 1 );
  }
  if (stos2 == 0) {
    printf("Proces nadrzędny - blad alokacji stosu\n");
    exit( 1 );
  }
  pid = clone( &funkcja_watku, (void *) stos+ROZMIAR_STOSU, 
		 CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, &mai );	
	  
  pid2 = clone( &funkcja_watku, (void *) stos2+ROZMIAR_STOSU, 
		 CLONE_FS | CLONE_FILES | CLONE_SIGHAND | CLONE_VM, &mai );

  waitpid(pid, NULL, __WCLONE);
  waitpid(pid2, NULL, __WCLONE);

//drukuj_czas();
printf("zmienna ll: %d\n",mai);
printf("zmienna gl: %d\n",zmienna_globalna);
//printf("zmienna gl: %d\n",zmienna_globalna);
/*
  free( stos );
  int liczba = 1000000;
   double a, b, c, t, tc;
  int j,k,l;
  k = -50000;
  t = czas_zegara();
  tc = czas_CPU();
  for(i=0;i<liczba;i++){

    printf("%d ",k+i);

  }
  t = czas_zegara()-t;
  tc =czas_CPU()-tc;
  printf("\nww\n");

  //printf("Czas wykonania %lf operacji wejscia/wyjscia: \n",t);
  //printf("Czas wykonania %lf operacji wejscia/wyjsciaCPU: \n",tc);
  printf("%lf\n",t);
  printf("%lf\n",tc);


  liczba = 10000*10000;
  a = 1.000001;
  //czas start
  t = czas_zegara();
  tc = czas_CPU();
  for(i=0;i<liczba;i++){

    a = 1.000001*a+0.000001; 

  }
  t = czas_zegara()-t;
  tc =czas_CPU()-tc;
  printf("\nae\n");

  //czas koniec
  //printf("Wynik operacji arytmetycznych: %lf\n", a);
  //printf("Czas wykonania %lf operacji arytmetycznych: \n",t);
  //printf("Czas wykonania %lf operacji arytmetycznychCPU: \n",tc);
  printf("%lf\n",t);
  printf("%lf\n",tc);

  
 */ 
  
}
