#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "mpi.h"
#define SCALAR double
//#define SCALAR float

#ifndef M_PI // standardy C99 i C11 nie wymagają definiowania stałej M_PI
#define M_PI (3.14159265358979323846)
#endif

int main( int argc, char** argv  ){ // program obliczania przybliżenia PI za pomocą wzoru Leibniza
                  // PI = 4 * ( 1 - 1/3 + 1/5 - 1/7 + 1/9 - 1/11 + itd. )
  
  int max_liczba_wyrazow=0;
  
  int rank, ranksent, size, source, dest, tag; 
  MPI_Status status;
  char h_name[1024] = "fail";
  int h_size = 1024;
  
  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &rank ); 
  MPI_Comm_size( MPI_COMM_WORLD, &size );

  //sleep(1);
  if(rank==0)
  {
  printf("Podaj maksymalną liczbę grup wyrazów do obliczenia przybliżenia PI\n");
  scanf("%d", &max_liczba_wyrazow);
  }
  //  double t = MPI_Wtime();
 //MPI_Barrier( MPI_COMM_WORLD );
 MPI_Bcast( &max_liczba_wyrazow, 1, MPI_INT, 0, MPI_COMM_WORLD );
 // wzór: PI/4 = 1 - 1/3 + 1/5 - 1/7 + 1/9 itd. itp.  
  SCALAR suma_plus=0.0;
  SCALAR suma_minus=0.0;
  /*
  int i=0;
  for(i=0; i<max_liczba_wyrazow; i++){  
    int j = 1 + 4*i; 
    suma_plus += 1.0/j;
    suma_minus += 1.0/(j+2.0);
    //printf("PI obliczone: %20.15lf, aktualna poprawka: %20.15lf\n",
    //  	 4*(suma_plus-suma_minus), 4.0/j-4.0/(j+2.0));
  }
*/
double sumap_glob=0;
double sumam_glob=0;
double allsumap_glob=0;
double allsumam_glob=0;
  int i = max_liczba_wyrazow*rank;
  for(i=max_liczba_wyrazow*rank; i<max_liczba_wyrazow*rank +max_liczba_wyrazow; i++){  
    int j = 1 + 4*i; 
    suma_plus += 1.0/j;
    suma_minus -= 1.0/(j+2.0);
    //printf("PI obliczone: %20.15lf, aktualna poprawka: %20.15lf\n",
    //  	 4*(suma_plus-suma_minus), 4.0/j-4.0/(j+2.0));
  }
  MPI_Reduce( &suma_plus, &sumap_glob, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  MPI_Reduce( &suma_minus, &sumam_glob, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
  MPI_Allreduce( &suma_plus, &allsumap_glob, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  MPI_Allreduce( &suma_minus, &allsumam_glob, 1, MPI_DOUBLE, MPI_SUM, MPI_COMM_WORLD);
  //  t = MPI_Wtime() - t;
  if(rank==0)
  {
  double pi_approx = 4*(sumap_glob+sumam_glob);
  printf("PI obliczone: \t\t\t%20.15lf\n", pi_approx);
  printf("PI z biblioteki matematycznej: \t%20.15lf\n", M_PI);
  }
 // if(TRUE)
  //{
  double pi_approx = 4*(allsumap_glob+allsumam_glob);
  printf("PI obliczone all: \t\t\t%20.15lf\n", pi_approx);
  printf("PI z biblioteki matematycznej: \t%20.15lf\n", M_PI);
  //}
  //  printf("Czas obliczeń: %lf\n", t);
  
  MPI_Finalize(); 
}


