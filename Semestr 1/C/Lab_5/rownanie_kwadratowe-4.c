#include <stdlib.h> // USES
#include <stdio.h> // USES
#include <math.h> // USES

// sposób na łatwą zmianę typu dla wszystkich zmiennych w programie
#define SCALAR double
//#define SCALAR float

#define SMALL_NUMBER 1.e-20 // czy wystarczy jedna wartość dla float i dla double?
#define TOLERANCJA 1.e-19

// Testowanie: konstrukcji sterujących (a także nazw zmiennych,
// zakresów widoczności i czasu życia)
int main(void)
{
  // rozwiązanie równania kwadratowego ax^2 + bx + c = 0

  printf("\nProgram rozwiązywania równania kwadratowego ax^2 + bx + c = 0\n");

  // typ a, b, c ustalany poprzez symbol SCALAR
  SCALAR a, b, c;
  // rozważania o kontrakcie... (czy uwzględnia skończoną precyzję?)
  // input - uodpornianie na błędy wczytywania danych 
  printf("\nPodaj parametr a: "); scanf("%lf",&a); // adres! (miejsce na wpisanie wartości)
  printf("Podaj parametr b: "); scanf("%lf", &b); // uwaga: inny format dla float!
  printf("Podaj parametr c: "); scanf("%lf", &c);

  // if(a==0 && b==0){ // alternatywa: if( a==0 || b==0 ) - zależnie od kontraktu
  if( fabs(a)<SMALL_NUMBER && fabs(b)<SMALL_NUMBER ){ // poprawnie

    printf("Błędne dane: a i b równe 0 (zbyt bliskie 0). Przerwanie programu.\n");
    exit(-1);

  }
  else{

    if(a==0) { // równanie liniowe

      //co mówi kontrakt? - czy należy rozważyć liczby a bliskie 0 ?
      printf("Miejsce zerowe: x0 = %.12le\n", -c/b );
      

    }
    else{

      SCALAR delta;  // zakres widoczności nazwy - powiązanie z czasem życia  
      delta = b*b - 4*a*c; // problem jeśli delta bliskie b*b (w skończonej precyzji)
                           // wtedy odejmowanie b i sqrt(delta) traci cyfry znaczące

      if(delta<0){
     	delta=fabs(delta);
        printf("delta = %.12le\n", delta );
	SCALAR temp = sqrt(delta);
	printf("Dwa pierwiastki zespolone: \nx1= rzeczywista = %.12le, urojona = %.12le i\n",
	       (-b)/(2*a), (temp)/(2*a) );

      } else if (delta == 0){

	printf("Jeden pierwiastek rzeczywisty: x = %.12le\n", -b/(2*a) );

      } else {

	SCALAR temp = sqrt(delta);
	printf("Dwa pierwiastki rzeczywiste: x1 = %.12le, x2 = %.12le\n",
	       (-b-temp)/(2*a), (-b+temp)/(2*a) );
	printf("Sprawdzenie poprawnosci przy pomocy wzorow Viete'a: x1*x2=c/a\n");
	       if((-b-temp)/(2*a)*(-b+temp)/(2*a)==c/a){
	       printf("Pierwiastki sa poprawne\n");}
	       else{
	       printf("Pierwiastki sa poprawne\n");}
	  if(fabs((-b-temp)/(2*a))<TOLERANCJA || fabs((-b+temp)/(2*a))<TOLERANCJA){
	  printf("ODPOWIEDNI NAPIS\n");}
	  else {printf("\n");}
	       

      }  
    } // znaczenie wcięć i nawiasów klamrowych dla zwiekszenia czytelności kodu !
  }

  return(0);
}

