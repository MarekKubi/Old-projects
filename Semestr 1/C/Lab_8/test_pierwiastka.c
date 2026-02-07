#include<stdio.h>
#include<math.h>

#define ACCURACY (1.e-5) // do przeprowadzania obliczeń i sprawdzenia dokładności wyniku

// 1 i 2 zaprojektowanie prototypu funkcji obliczania pierwiastka i umieszczenie go 
//       jako deklaracji funkcji

double f_pierwiastek( double liczba);


// 0. przed wykonaniem ćwiczenia cały kod w funkcji main (analiza, uruchomienie)   
int main( void ) {
  
  double liczba;
  
  for(;;){
    
    printf("\nPodaj wartość liczby dodatniej (-1 kończy program):\n");
    scanf("%lf",&liczba);

    // w wariancie pierwszym każda liczba ujemna przerywa program
    // (nie wywołujemy funkcji dla argumentów ujemnych)
    // przy modyfikacji kontraktu można to zmienić
    if(liczba<0.0) break;

    // 0. przed wykonaniem ćwiczenia cały kod w funkcji main (analiza, uruchomienie) 
    
    // 3. wywołanie zaprojektowanej funkcji obliczania pierwiastka
    double pierwiastek = f_pierwiastek( liczba);
    


    // 4. wydruk obliczonego pierwiastka

    // ewentualne dodatkowe wywołania funkcji obliczania pierwiastka, zgodnie z instrukcją

    // 5. zakończenie nieskończonej pętli for i funkcji main

    

    // 6. nagłowek - początek definicji funkcji
// definicja funkcji + komentarze (z komentarzy można tworzyć dokumentację):

// funkcja oblicz_pierwiastek oblicza pierwiastek za pomocą wzoru Herona
//               dla dowolnej liczby podwójnej precyzji większej od zera
// czy kontrakt wymaga specjalnych działań dla liczb ujemnych?
// wariant 1. funkcja zakłada, że argument jest nie mniejszy niż zero
// wariant 2. dla liczb mniejszych od zera funkcja zwraca kod błędu: -1
//   implementacja w kodzie, np.
//  if(arg<0){
//    // obsługa błędu wejścia, np.
//    return(-1.0); // wyjaśnienie w dokumentacji
//  }

    
    // 7. przekształcenie kodu poniżej, tak aby stanowił treść funkcji
    //    (z odpowiednim argumentem i własnymi zmiennymi lokalnymi)
    //    (uwaga: brak nieskończonej pętli for - co zamiast break?)
    
    // obliczenia pierwiastka za pomocą wzoru Herona
    
    
    // wydruki kontrolne - można je wyłączyć po zdebugowaniu funkcji
    printf("\nliczba do obliczenia pierwiastka: %18.15lf\n", liczba);
    printf("\tzałożona dokładność (względna) obliczania pierwiastka: %18.15lf\n", 
	   ACCURACY);
    // ten wydruk można (po odpowiedniej modyfikacji skopiować także do main)
    printf("\tpierwiastek liczby: obliczony %18.15lf, dokładny %18.15lf\n", 
	   pierwiastek, sqrt(liczba));
    printf("błąd bezwzględny: %18.15lf, błąd względny: %18.15lf\n", pierwiastek-sqrt(liczba), (pierwiastek-sqrt(liczba))/sqrt(liczba));



    printf("\n\nFunkcja wywolana jako argument printf: %18.15lf \nFynkcja wywolana jako argument funkcji: %18.15lf\n", f_pierwiastek( liczba), f_pierwiastek( f_pierwiastek( liczba)));


    // 8. zamiana zakończenia funkcji main (z pętlą for) na zakończenie funkcji
    //    obliczania pierwiastka

    // ---------------- 3.0 --------------------------------
    
  }
}
double f_pierwiastek( double liczba)
{
	int iteracje =0;
    double pierwiastek = 1.0;
	double temp;
do{
      iteracje++;
      temp = pierwiastek;
      pierwiastek = 0.5 * (temp + liczba/temp);

      // dodatkowe wydruki kontrolne
      // np. do debugowania działania funkcji

//    printf("wartość %20.15lf, \tbłąd  %20.15lf,     błąd kwadratu %20.15lf\n", 
//	   pierwiastek, fabs(pierwiastek - temp)/pierwiastek, 
//	   fabs(pierwiastek*pierwiastek - arg)/arg);
      
      
      // sprawdzenie warunku wyjścia z pętli - błąd względny obliczania pierwiastka
    } while(fabs(pierwiastek*pierwiastek - liczba)/liczba > ACCURACY); 
return pierwiastek;
}




