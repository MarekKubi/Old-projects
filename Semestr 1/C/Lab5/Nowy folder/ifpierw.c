#include <stdio.h>
#include <stdlib.h>
int main(void)
{
  
  char c;
  for(;;) // wykonywanie nieskończenie wiele razy
	{
    printf("\nWprowadź cyfrę od 0 do 5: \n");  
    scanf(" %d",&c); // wielokrotne wczytywanie pojedynczego znaku (jak pozbyć się \n ?)
    if(c==0)
	{
    	printf("Wprowadzono: 0\n");
	}
    else if(c==1 || c==2)
	{
   	 printf("Wprowadzono: 1 lub 2\n");
	}
    else if(c==3)
	{
    	printf("Wprowadzono: 3\n");
	}
    else if(c==4 || c==5)
	{
   	 printf("Wprowadzono: 4 lub 5\n");
	}
	else
	{
      printf("Wprowadzono: znak spoza zakresu 0-5\n");
	}
    }
	}

