#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  
  char c;
  for(;;){  // wykonywanie nieskończenie wiele razy

    printf("\nWprowadź cyfrę od 0 do 5: \n");  
    scanf(" %c",&c); // wielokrotne wczytywanie pojedynczego znaku (jak pozbyć się \n ?)
    switch (c) {
    case '0': 
      printf("Wprowadzono: 0\n");
      break;
    case '1':
      printf("Wprowadzono: 1\n");
      break;
    case '2':
      printf("Wprowadzono: 2\n");
      break;
    case '3':
      printf("Wprowadzono: 3\n");
      break;
    case '4':
    	printf("Wprowadzono: 4\n");
    	break;
    case '5':
      printf("Wprowadzono: 5\n");
      break;
    case '6':
      exit(0);
    default:
      printf("Wprowadzono: znak spoza zakresu 0-5\n");
      break;
    }
  }

}
