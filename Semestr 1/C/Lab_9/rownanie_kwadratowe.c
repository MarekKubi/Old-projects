#include <stdlib.h> // USES
#include <stdio.h> // USES
#include <math.h> // USES

// sposób na łatwą zmianę typu dla wszystkich zmiennych w programie
#define SCALAR double
//#define SCALAR float

#define SMALL_NUMBER 1.e-20 // czy wystarczy jedna wartość dla float i dla double?
#define TOLERANCJA 1.e-14
// Testowanie: konstrukcji sterujących (a także nazw zmiennych,
// zakresów widoczności i czasu życia)

int funkcja(double a, double b, double c, double * wsk_x1, double * wsk_x2, double * wsk_z1, double * wsk_z2, int * wsk_nie_pop, int * wsk_czy_dok);



int main(void)
{
  // rozwiązanie równania kwadratowego ax^2 + bx + c = 0

  printf("\nProgram rozwiązywania równania kwadratowego ax^2 + bx + c = 0\n");

  double x1, x2, z1, z2, czy_d, czy_dok;
  double * wsk_x1 = &x1;
  double * wsk_x2 = &x2;
  double * wsk_z1 = &z1;
  double * wsk_z2 = &z2;
  czy_d=0;
  int * wsk_czy_dok = &czy_dok;

int nie_pop =0;
int * wsk_nie_pop = &nie_pop;



  // typ a, b, c ustalany poprzez symbol SCALAR
  SCALAR a, b, c;
  // rozważania o kontrakcie... (czy uwzględnia skończoną precyzję?)
  // input - uodpornianie na błędy wczytywania danych 
  printf("\nPodaj parametr a: "); scanf("%lf",&a); // adres! (miejsce na wpisanie wartości)
  printf("Podaj parametr b: "); scanf("%lf", &b); // uwaga: inny format dla float!
  printf("Podaj parametr c: "); scanf("%lf", &c);
  czy_d = funkcja(a, b, c, wsk_x1, wsk_x2, wsk_z1, wsk_z2, wsk_nie_pop, wsk_czy_dok);

  // if(a==0 && b==0){ // alternatywa: if( a==0 || b==0 ) - zależnie od kontraktu
  if( nie_pop ==1 ){ // poprawnie

    printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
    exit(-1);

  }
/*
  else{

    if(fabs(a)<TOLERANCJA) { // równanie liniowe

      //co mówi kontrakt? - czy należy rozważyć liczby a bliskie 0 ?

    }
    else{

      SCALAR delta;  // zakres widoczności nazwy - powiązanie z czasem życia  
      delta = b*b - 4*a*c; // problem jeśli delta bliskie b*b (w skończonej precyzji)
                           // wtedy odejmowanie b i sqrt(delta) traci cyfry znaczące

       if (fabs(delta) < TOLERANCJA){

	printf("Jeden pierwiastek rzeczywisty: x = %.12le\n", -b/(2*a) );
}

	else if(delta<0)
{
	SCALAR temp = sqrt(-delta);
	printf("Dwa pierwiastki zespolone: x1 = %.12le + i%.12le, x2 = %.12le - i%.12le \n",(-b)/(2*a), (temp/(2*a)), (-b)/(2*a), (temp/(2*a)));
}
/*

	else if(delta<0)
{
	printf("Dwa pierwiastki zespolone -\n");
}

       else {

	SCALAR temp = sqrt(delta);
	printf("Dwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n",
	       (-b-temp)/(2*a), (-b+temp)/(2*a) );
    printf("Sprawdzenie poprawnosci Viete: x1*x2=c/a\n");
           

      if(fabs((-b-temp)/(2*a)*(-b+temp)/(2*a) - (c/a))<TOLERANCJA)
{
      printf("Pierwiastki sa dokladne\n");
}
      else 
{
printf("Pierwiastki nie sa dokladne\n");
}




      }  
    } // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu !
  }
*/
printf("%d\n",czy_d);
if(czy_d == -1)
{
	printf("Dwa pierwiastki zespolone: x1 = %.12le + i%.12le, x2 = %.12le - i%.12le \n",x1, z1, x2, z2);
}
else if(czy_d == 0)
{
	printf("Jeden pierwiastek rzeczywisty: x = %.12le\n", x1 );
}
else
{
	printf("Dwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n",
	       x1, x2 );
	if(czy_dok)
	{
	printf("Pierwiastki sa dokladne\n");
	}
}
  return(0);
}







void funkcja(double a, double b, double c, double * wsk_x1, double * wsk_x2, double * wsk_z1, double * wsk_z2, int * wsk_nie_pop, int * wsk_czy_dok)
{

// printf("%lf %lf %lf",a,b,c);
if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER ){ // poprawnie
int czy_d;
    printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
    *wsk_nie_pop =1;
    exit(-1);;

  }


  else{
    if(fabs(a)<TOLERANCJA) { // równanie liniowe

      //co mówi kontrakt? - czy należy rozważyć liczby a bliskie 0 ?

    }
    else{

      SCALAR delta;  // zakres widoczności nazwy - powiązanie z czasem życia  
      delta = b*b - 4*a*c; // problem jeśli delta bliskie b*b (w skończonej precyzji)
                           // wtedy odejmowanie b i sqrt(delta) traci cyfry znaczące

       if (fabs(delta) < TOLERANCJA){

	printf("Jeden pierwiastek rzeczywisty: x = %.12le\n", -b/(2*a) );
	*wsk_x1 = (-b/(2*a));
	czy_d = 0;
}

	else if(delta<0)
{
	SCALAR temp = sqrt(-delta);
//	printf("Dwa pierwiastki zespolone: x1 = %.12le + i%.12le, x2 = %.12le - i%.12le \n",(-b)/(2*a), (temp/(2*a)), (-b)/(2*a), (temp/(2*a)));
*wsk_x1 = (-b)/(2*a);
*wsk_z1 = (temp/(2*a));
*wsk_x2 = (-b)/(2*a);
*wsk_z1 = (temp/(2*a));
czy_d = -1;

}
/*

	else if(delta<0)
{
	printf("Dwa pierwiastki zespolone -\n");
}
*/
       else {

	SCALAR temp = sqrt(delta);
//	printf("Dwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n",(-b-temp)/(2*a), (-b+temp)/(2*a) );
//    printf("Sprawdzenie poprawnosci Viete: x1*x2=c/a\n");
*wsk_x1 = (-b-temp)/(2*a);
*wsk_x2 = (-b+temp)/(2*a);
czy_d = 1;

      if(fabs((-b-temp)/(2*a)*(-b+temp)/(2*a) - (c/a))<TOLERANCJA)
{
 //     printf("Pierwiastki sa dokladne\n");
*wsk_czy_dok =1;
}
      else 
{
//printf("Pierwiastki nie sa dokladne\n");
*wsk_czy_dok =0;
}


      }  
    } // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu !
  }

}

