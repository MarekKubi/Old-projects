#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ROZMIAR_TABLICY 10



void main(void)
{

	int i =0;
  // int tablica_int[ROZMIAR_TABLICY] = {0};

  // 1. inicjowanie tablicy w momencie definowania:

  // a. wszystkie wartości
	printf("1. a\n");
	int tablica1_int[10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
  
	//tablica1_int[10];
	for(i=0; i<10; i++){
    		printf("Iteracja %d: tablica1_int[%d] = %d\n", i, i, tablica1_int[i]);
  	}
  // b. początkowe wartości

	printf("\n1. b\n");
	int tablica2_int[10]={0, 1, 2};


	for(i=0; i<10; i++){
    		printf("Iteracja %d: tablica2_int[%d] = %d\n", i, i, tablica2_int[i]);
  	}

  // 2. nadanie wartości w pętli
  // a. zależnych od wartości zmiennej sterujacej

	printf("\n2. a\n");
	int tablica3_int[10];
	
	for(i=0; i<10; i++){
		tablica3_int[i]=i;
	}
	for(i=0; i<10; i++){
    		printf("Iteracja %d: tablica3_int[%d] = %d\n", i, i, tablica3_int[i]);
  	}



  // b. wczytywanych z klawiatury za pomocą scanf

	printf("\n2. b\n");

	int tablica4_int[10];

	int a2;

	for(i=0; i<10; i++){
		printf("Podaj liczbe\n");
		scanf("%d",&a2);
		tablica4_int[i]=a2;
	}
	for(i=0; i<10; i++){
    		printf("Iteracja %d: tablica4_int[%d] = %d\n", i, i, tablica4_int[i]);
  	}

  // 3. zamiana pętli for nadawania wartości na pętlę while

	printf("\n3\n");

	int tablica5_int[10];

	int b2;
	i=0; 
	while(i<10){
		printf("Podaj liczbe\n");
		scanf("%d",&b2);
		tablica5_int[i]=b2;
 		i++;
	}
	for(i=0; i<10; i++){
    		printf("Iteracja %d: tablica5_int[%d] = %d\n", i, i, tablica5_int[i]);
  	}

  // 4. zamiana poniższej pętli for na pętlę do
  // (jak zwykle najlepiej wykomentować starą pętlę i wpisać poniżej nową pętlę)
/*
  	for(i<10; i++;){

    	printf("Iteracja %d: tablica_int[%d] = %d\n", i, i, tablica_int[i]);

  }
*/
	printf("\n4\n");
	i=0;
	do{

    		printf("Iteracja %d: tablica5_int[%d] = %d\n", i, i, tablica5_int[i]);
		i++;
  	}while(i<10);
  // 5. wyszukiwanie wartości maksymalnej w tablicy (pętla for)
	printf("\n5\n");
	int max=tablica5_int[0];
	for(i=0; i<10; i++){
    		if(max<tablica5_int[i]){
			max=tablica5_int[i];
		}
  	}
	printf("Maksymalna wartosc z tablica5_int[%d] = %d\n", i, max);

  // 6. obliczanie sumy elementów tablicy (pętla while)
	printf("\n6\n");
	int suma1=0;
	i=0; 
	while(i<10){
	suma1 += tablica5_int[i];
 	i++;
	}
	printf("Suma wartosci elementow z tablica5_int[%d] = %d\n", i, suma1);
  //-------------------------------- 3.0 ------------------------------------
	i=0;
  // 7. tablica z wartościami losowymi i wyszukiwanie zadanych wartości
	
  // a. nowa definicja tablicy (np. tablicy znaków)

	printf("\n7. a\n");
	char string[3] = {'s','a','m'};

    	printf("String = %s\n", string);

  // b. nadawanie wartości losowych wyrazom tablicy
  //    (np. liczby z zakresu 33-126, czyli odpowiadające znakom ASCII)
  //    -> odpowiednie wydruki

	printf("\n7. b\n");
	char tablica6_char[10];
	srand(time(NULL));
	for(i=0; i<10; i++){
		tablica6_char[i]=(rand() / (RAND_MAX + 1.0) * 93.0)+33;
	}
	for(i=0; i<10; i++){
    		printf("Iteracja %d: tablica6_char[%d] = %c\n", i, i, tablica6_char[i]);
  	}

  // c. sprawdzenie losowości - obliczenie wartości średniej w tablicy
  //    (w odpowiedniej pętli) - porównanie z teoretyczną średnią
  //    -> odpowiednie wydruki

	printf("\n7. c\n");
	double suma2=0;
	for(i=0; i<10; i++){
		suma2 += tablica5_int[i];
	}
	// teoretyczna srednia
	double teo_srednia = (126 - 33) / 2;
	printf("Srednia wartosc z tablica6_int[] to = %lf\n teoretyczna srednia to = %lf\n ich ruznica to = %lf\n",(suma2/10), teo_srednia, (suma2/10) - teo_srednia);
	
  // d. wyszukiwanie zadanej wartości
  //    -> odpowiednie wydruki w momencie znalezienia wartości
  //    np. "Znaleziono wartość %.. w %d elemencie tablicy\n", ...
	
  //  d1. wyszukanie tylko jednej (pierwszej) wartości - pętla while
  //      (lub pętla for i break)
	printf("\n7. d1\n");
	int sz1;
	printf("Podaj szukana wartosc\n");
	scanf("%d",&sz1);
	int sz1nr=-1;
	for(i=0; i<10; i++){
		if(tablica5_int[i]==sz1){
			sz1nr=i;
			break;
		}
	}
	if(sz1nr==0){
	printf("nie znaleziono wartość %d w tablicy5\n", sz1);
	}
	else{
	printf("znaleziono wartość %d w %d elemencie tablicy5\n",sz1, sz1nr);
	}
  //  d2. wyszukanie (i wypisanie) wszytskich wartości - pętla for
  //      (lub pętla while)
	printf("\n7. d2\n");
	int sz2;
	printf("Podaj szukana wartosc\n");
	scanf("%d",&sz2);
	int sz2nr=-1;
	for(i=0; i<10; i++){
		if(tablica5_int[i]==sz2){
			printf("znaleziono wartość %d w %d elemencie tablicy5\n",sz2, i);
			sz2nr=1;
		}
	}
	if(sz2nr==0){
	printf("nie znaleziono wartość %d w tablicy5\n", sz2);
	}
  //-------------------------------- 4.0 ------------------------------------

  
}
