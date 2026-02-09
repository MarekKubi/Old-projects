#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <omp.h>

#define WYMIAR 18

int main ()
{
  double a[WYMIAR];
//omp_set_num_threads(4);


#pragma omp  parallel for default(none) shared(a) 
  for(int i=0;i<WYMIAR;i++) a[i]=1.02*i;

  // pętla sekwencyjna
  double suma=0.0;
  for(int i=0;i<WYMIAR;i++) {
      suma += a[i];
  }

  printf("Suma wyrazów tablicy: %lf\n", suma);

//omp_set_num_threads(4);
  // pętla do modyfikacji - docelowo równoległa w OpenMP
  omp_set_dynamic(0);
  //omp_set_num_threads(4);
  double suma_par = 0.0;
  double suma_parallel=0.0;
//#pragma omp for parallel default(none) shared(suma_par) shared(a) num_threads(4) scheadule(static, 3) private(suma_parallel)
//{
  // ...
 // #pragma omp for reduction(suma_parallel)   num_threads(4)
 #pragma omp parallel for default(none) shared(suma_par, a) private(suma_parallel) num_threads(4) ordered
  for(int i=0;i<WYMIAR;i++) {
    //int id_w = omp_get_thread_num();
    // ...
      suma_parallel += a[i];
      // ...
#pragma omp ordered
      printf("a[%2d]->W_%1d  \n",i,omp_get_thread_num()); 
//#pragma omp ordered
      //printf("aaaaaaaaaaaaaa_%1d  \n",omp_get_num_threads());
  //}
  #pragma omp critical
  {
  suma_par = suma_par + a[i];
  }
}
  printf("\nSuma wyrazów tablicy równolegle bez schedule: %lf\n",
	 suma_par);
 
 #pragma omp parallel for schedule(static,3) default(none) shared(suma_par, a) private(suma_parallel) num_threads(4) ordered
  for(int i=0;i<WYMIAR;i++) {
    //int id_w = omp_get_thread_num();
    // ...
      suma_parallel += a[i];
      // ...
#pragma omp ordered
      printf("a[%2d]->W_%1d  \n",i,omp_get_thread_num()); 
//#pragma omp ordered
      //printf("aaaaaaaaaaaaaa_%1d  \n",omp_get_num_threads());
  //}
  #pragma omp critical
  {
  suma_par = suma_par + a[i];
  }
}
  printf("\nSuma wyrazów tablicy równolegle (z klauzulą - static, 3: %lf\n",
	 suma_par);
	 

  suma_par = 0.0;
  suma_parallel=0.0;
	 #pragma omp parallel for schedule(static) default(none) shared(suma_par, a) private(suma_parallel) num_threads(4) ordered
  for(int i=0;i<WYMIAR;i++) {
    //int id_w = omp_get_thread_num();
    // ...
      suma_parallel += a[i];
      // ...
#pragma omp ordered
      printf("a[%2d]->W_%1d  \n",i,omp_get_thread_num()); 
//#pragma omp ordered
      //printf("aaaaaaaaaaaaaa_%1d  \n",omp_get_num_threads());
  //}
  #pragma omp critical
  {
  suma_par = suma_par + a[i];
  }
}
  printf("\nSuma wyrazów tablicy równolegle (z klauzulą - static: %lf\n",
	 suma_par);




  suma_par = 0.0;
  suma_parallel=0.0;

 #pragma omp parallel for schedule(dynamic,3) default(none) shared(suma_par, a) private(suma_parallel) num_threads(4) ordered
  for(int i=0;i<WYMIAR;i++) {
    //int id_w = omp_get_thread_num();
    // ...
      suma_parallel += a[i];
      // ...
#pragma omp ordered
      printf("a[%2d]->W_%1d  \n",i,omp_get_thread_num()); 
//#pragma omp ordered
      //printf("aaaaaaaaaaaaaa_%1d  \n",omp_get_num_threads());
  //}
  #pragma omp critical
  {
  suma_par = suma_par + a[i];
  }
}
  printf("\nSuma wyrazów tablicy równolegle (z klauzulą - dynamic, 3: %lf\n",
	 suma_par);
	 
  suma_par = 0.0;
  suma_parallel=0.0;

 #pragma omp parallel for schedule(dynamic) default(none) shared(suma_par, a) private(suma_parallel) num_threads(4) ordered
  for(int i=0;i<WYMIAR;i++) {
    //int id_w = omp_get_thread_num();
    // ...
      suma_parallel += a[i];
      // ...
#pragma omp ordered
      printf("a[%2d]->W_%1d  \n",i,omp_get_thread_num()); 
//#pragma omp ordered
      //printf("aaaaaaaaaaaaaa_%1d  \n",omp_get_num_threads());
  //}
  #pragma omp critical
  {
  suma_par = suma_par + a[i];
  }
}
  printf("\nSuma wyrazów tablicy równolegle (z klauzulą - dynamic: %lf\n",
	 suma_par);

}
