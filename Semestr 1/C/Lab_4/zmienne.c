// //** zmienne.c - prosty program ilustrujący wykorzystanie i drukowanie zmiennych oraz
// //**             ewentualne problemy z precyzją przechowywania

// //** słowo USES informuje, że w pliku będą używane funkcje opisane w plikach nagłówkowych
#include <stdio.h> // USES - deklaracje funkcji wejścia/wyjścia
#include <math.h> // USES - deklaracje funkcji matematycznych

// //** definicja symbolu - w kodzie używany jest symbol, preprocesor zamienia każde wystąpienie
// //** symbolu w kodzie na podany łańcuch znaków
#define TOLERANCE 1e-12 // tolerancja - wartość względnej różnicy liczb (l1-l2)/l1
                        // //** poniżej której dwie liczby zmiennoprzecinkowe są uznawane za równe
// //** UWAGA: tolerancja powinna być różna dla float i double (tutaj wartość typowa dla double)

// //** bez użycia #define i nazwanych wartości (np. TOLERANCE - można jeszcze zwiekszyć czytelność nazwy)
// //** w kodzie pojawiają się tzw. "magic numbers" - liczby w kodzie, o których po pewnym czasie
// //** nikt nie wie co oznaczają, dlaczego tyle wynoszą, skąd się wzięły


// //** zwrot kodu błędu lub sukcesu (zwyczajowo kod sukcesu -> 0)
int main(void)
{

  /* 1. STANDARDOWE DEKLARACJE-DEFINICJE I WYPISYWANIE WARTOŚCI ZMIENNYCH */

  // //** definicj  
  int n; // nazwy zmiennych - znaczące, niekoniecznie krótkie, z dużymi i małymi literami
         // nazwy krótkie, nieznaczące dla zmiennych pomocniczych stosowanych lokalnie
  char znak_do_testowania;

  // //** podstawianie wartości - inicjowanie
    n = 7; // instrukcja przypisania - stałe liczbowe i podstawowe operacje
    znak_do_testowania = 'a'; // stała znakowa

    printf("\nwartość zmiennej n = %d, wartość zmiennej znak_do_testowania = %c\n", n, znak_do_testowania );

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zdefiniowanie po jednej zmiennej każdego z omawianych na wykładzie typów - w tym typów
  // //**   z określeniami: short, long, unsigned
  // //** - podstawienie do każdej zmiennej dowolnie wybranej, poprawnej wartości
  // //** - zdefiniowanie połączone z nadaniem wartości (zainicjowniem) ponownie dla jednej zmiennej
  // //**   każdego z omawianych na wykładzie typów
  // //** - wypisanie wartości zdefiniowanych zmiennych na ekranie w oknie terminala: dobranie odpowiedniego
  // //**   symbolu formatowania dla każdego typu - sprawdzenie poprawności działania (czyli wydrukowania
  // //**   nadanej wartości)
  // //** - sprawdzenie efektu błędnego użycia symbolu formatowania: kiedy wydruk przestaje być poprawny
  // //**   (np. zmienna typu unsigned drukowana jako int, zmienna float drukowana jako int itd., itp,)

int n1 = -1;
float f1 = 0.5;
double d1 = -0.125;  //long float
long double ld1 = 0.0625;
long int ln1 = -1000;
char c1 = 'c';
char string[3] = {'s','a','m'};
unsigned int ui1 = 20000;
// string s;
printf ( "\nint = %d \nfloat = %f \ndouble = %lf \nlong double = %llf \nlong int = %ld   \nunsigned int = %u \nchar = %c \nstring(char[]) = %s", n1, f1, d1, ld1, ln1, ui1, c1, string);

printf ( "\nint = %f \nfloat = %ld \ndouble = %llf \nlong double = %c \nlong int = %d   \nunsigned int = %d \nchar = %u \nstring(char[]) = %d\n", n1, f1, d1, ld1, ln1, ui1, c1, string);
  /* 2. PROSTE OPERACJE */

  // //** operatory i ich priorytety
   int m;
   m = 2 * n + 3;
   int o = 2 * (n + 3); // definicja z inicjowaniem
   printf("\nn = %d, (2 * n + 3) = %d != (2 * (n + 3)) = %d\n", n, m, o);

int a2 = 3;
int b2 = 7;
int c2 = 4;
int wn12= a2+b2*c2;
int wn22= (a2+b2)*c2;
printf("\n3+7*4 = %d \n(3+7)*4 = %d \n", wn12, wn22);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - napisanie kilku (2-3) wyrażeń arytmetycznych, w których wynik zależał będzie od kolejności
  // //**   zapisu i priorytetów wykonywanych operacji - testowanie poprawnego użycia nawiasów

  // //** operatory jednoargumentowe i ich priorytety
   int p = n++;  
   n--; // powrót do początkowej wartości n
   int q = ++n;  
   n--; // powrót do początkowej wartości n
   printf("\nn = %d, wynik podstawienia: 'p = n++;' - %d, wynik podstawienia: 'q = ++n;' - %d\n", 
   n, p, q);

int c3 = 3;
int a3;
a3 = c3++;
c3--;
int b3;
b3 = ++c3;
c3--;
int wn13;
wn13= (++a3)+b3;
a3--;
int wn23;
wn23= a3+(b3++);
b3--;
printf("\n3++ = %d \n++3 = %d \n(++3)+4 = %d \n3+(4++) = %d \n",a3, b3 , wn13, wn23);
  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - napisanie kilku (2-3) wyrażeń arytmetycznych z operatorami jednoargumentowymi, w których wynik
  // //** zależał będzie od priorytetów wykonywanych operacji - testowanie poprawnego użycia nawiasów

  
  // //** operatory / - dzielenie całkowite i % - modulo
   n = 1574;
   m = n % 7;
   o = n / 7;
   printf("\nn = %d, n/7 = %d, reszta - n%7 = %d, n = (n/7)*7 + (n%7) = %d\n",n, o, m, o*7+m);


int a4 = 40;
int b4 = 3;
int wn14 = 40 / 3;
int wn24 = 40 % 3;
int s4 = wn14*3+wn24;

printf("\n40/3 = %d \n40%3 = %d \n(40/3)*3+(40%3) = %d\n", wn14, wn24, s4);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - napisanie kilku (2-3) wyrażeń arytmetycznych z funkcją modulo:
  // //**   - sprawdzanie podzielności jednych liczb przez inne
  // //**   - dzielenie z resztą i uzyskiwanie pierwotnej wartości (dla innych liczb niż w przykładzie
  // //**     powyżej)


  /* 3. DEFINICJE STAŁYCH SYMBOLICZNYCH */

  // //**** UWAGA: definicje symboli #define powinny być na początku pliku (po #include) !!!!!!!!!!
           // //** kompilator w pierwszej fazie działania zastąpi wszystkie wystąpienia
           // //** symboli odpowiednimi wyrażeniami z #define
  #define SIEDEM 7 // wystąpienia symbolu SIEDEM są w kodzie zamieniane na 7
   int r = SIEDEM; // w assemblerze r jest zmienną - ma adres, SIEDEM znika zamienione na 7
   printf("\nr = %d, stała SIEDEM = %d\n", r, SIEDEM); 


#define senszycia 42
int a5 = senszycia;
printf("\na5 = %d, stała senszycia = %d\n", a5, senszycia); 
  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - nadanie wartości kilku symbolom - wartości powinny być stałymi różnych typów liczbowych
  // //** - podstawienie do zmiennych wartości za pomocą symboli okreslonych w #define i wydrukowanie
  // //**   wartości zmiennych (UWAGA: po podstawieniu za symbol napisu stanowiącego zapis liczby,
  // //**   funkcjonuje on w kodzie jako liczba określonego typu - jak w przykładzie powyżej - drukując
  // //**   go należy odpowiednio dobrać formatowanie)

    
  /* 4. ZMIENNE ZMIENNOPRZECINKOWE: FLOAT I DOUBLE */

  // //**** UWAGA na dokładność:
  // //** wygodne wyrażanie w postaci liczby cyfr znaczących:
  // //** x = 123456789.123456789123456
  // //**   - dla liczb pojedynczej precyzji co najmniej 6 cyfr znaczących 
  // //**       pierwsze cyfry 123456 - na pewno sensowne, reszta cyfr może być bez znaczenia (śmieci)
  // //**         (czyli zapisana w zmiennej liczba to ok. 1234560000 +/- 10000),
  // //**   - dla liczb podwójnej precyzji co najmniej 15 cyfr znaczących
  // //**       123456789.123456 - na pewno sensowne 
  // //**         (zapisana liczba to ok. 123456789.123456 +/- 0.0000001)
 
  // //** definicja z inicjowaniem 
   float f = 1.0f/3.0f;  // zapis stałej float z literką f
   float g = 1.0f/3.0; 
   double d = 1.0/3.0; 
   double e = 1.0f/3.0; 

  
   printf("\nliczby zmiennoprzecinkowe:\n");
   printf("float  -  f = 1.0f/3.0f = %f  (dokładnie: %20.15f)\n", f, f);
   printf("float  -  g = 1.0f/3.0  = %f  (dokładnie: %20.15f)\n", g, g);
   printf("double -  d =  1.0/3.0  = %lf  (dokładnie: %20.15lf)\n", d, d);
   printf("double -  e = 1.0f/3.0  = %lf  (dokładnie: %20.15lf)\n", e, e);
   int s = 1/3;
   printf("(liczba całkowita s = 1/3 = %d - dzielenie całkowite)\n", s);
   int t = 1.0/3.0;
   printf("(liczba całkowita t = 1.0/3.0 = %d - obcięcie przy konwersji)\n", t);
   printf("\n");
   printf("float  -  f = 1.0f/3.0f = %e  (dokładnie: %20.15e)\n", f, f);
   printf("double -  d =  1.0/3.0  = %le  (dokładnie: %20.15le)\n", d, d);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zdefiniowanie kilku zmiennych typów float i double oraz nadanie im wartości
  // //**   za pomocą stałych typu float i double
  // //** - wydrukowanie wartości zdefiniowanych i zainicjowanych zmiennych z wystarczającą liczbą cyfr,
  // //**   tak aby zobaczyć jaka jest dokładność (jaki jest błąd wartości zmiennej w stosunku do podstawianej 
  // //**   matematycznej wartości (może to dotyczyć także prostych ułamków dziesiętnych, np. 0.1, 0.2, 0.3)  

float f16 = 5;
float f26 = 1;
float f36 = f26/f16;
printf("\nfloat 1/5 = %f \n %20.15f", f36,f36);  //-------------------------------------------- 3.0 --------------------------------------------


  /* 5. OPERATORY RELACJI I WARTOŚCI LOGICZNE  */

  // //** wartość logiczna wyrażeń - obliczanie i zapis w zmiennych
  //  int a =  n<m ;
  //  _Bool b = n<m || n>m ;
  //  printf("\nWartość logiczna wyrażenia: %d<%d wynosi %d (int a = n<m = %d)\n", 
  //	 n, m, n<m, a);
  //  printf("\nWartość logiczna wyrażenia: %d<%d lub %d>%d wynosi %d (_Bool b = n<m||n>m = %d)\n", 
  //	 n, m, n, m, (n<m)||(n>m), b);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - skonstruowanie kilku złożonych wyrażeń logicznych, które będą np. sprawdzać zasady rachunku zdań:
  // //**   (p lub q) i r  =? (p i r) lub (q i r) - czy jest to równoważne
  // //**   (p i q) lub r  =? (p lub r) i (q lub r) - czy jest to równoważne
  // //** - jaka jest kolejność operacji i wynik w przypadku usuwania kolejnych nawiasów


  /* 6. Operatory oraz niejawne i jawne konwersje typów  */
  
  // e = f; // e typu double, f typu float 
  // d = 1111 + 1000 * n; // d = (double) ...;
  // n = f + 2.5; // n = (int) ...;
  // printf("\nNiejawne i jawne konwersje typów:\n");
  // printf("n = %d, f = %f, d = %lf, e = %le\n", n, f, d, e);

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zapisanie kilku wyrażeń z operacjami na zmiennych różnych typów i zapisie do zmiennej
  // //** - sprawdzenie otrzymanego wyniku: jakich konwersji dokonał kompilator?
  // //** - zapisanie kilku wyrażeń z jawną konwersją typów, obserwacja otrzymanych wyników (np.
  // //**   dla kilku wariantów podstawienia do f:  n / 3 , (double) n / 3 ,  n / 3.0 , (double) (n / 3)
  
  
    /* 7. DEFINICJE STAŁYCH SYMBOLICZNYCH (CD.) */

  // //** UWAGA: definicje symboli #define powinny być na początku pliku (po #include) !!!!!!!!!!
  // //** najlepszym sposobem na "magic numbers" jest umieszczenie ich na początku pliku
  // //** zakodowanych w postaci "stałych nazwanych" (RAZEM Z ODPOWIEDNIMI KOMENTARZAMI), np.:
  // #define JednaTrzeciaFloat (1.0f/3.0f) // 1/3 z dokładnością float (czasem nazwa zastępuje komentarz)
  // #define JednaTrzecia (1.0/3.0) // uwaga na odczyt przy podstawieniu (rola nawiasów)
           // //** brak nawiasów może spowodować problemy z kolejnością wykonywania operacji
           // //** 3.0*1.0/3.0 może być różne od 3.0*(1.0/3.0)
           // //** (3*1)/3 jest na pewno różne od 3*(1/3)
           // //** 3*1/3 może być różne od 3*(1/3)


  // //** Precyzja stałych i zmiennych
  // //** (uwaga na mozliwe modyfikacje dokonywane przez kompilator (np. (1.0f/3.0f)*3.0f -> 1.0)
  //  d = JednaTrzecia * 3.0;
  //  e = JednaTrzeciaFloat * 3.0;
  //  printf("\nPrecyzja stałych i niejawne konwersje:\n");
  //  printf("(1.0/3.0)*3.0: \tJednaTrzecia -> d = %20.15lf; \n\t\tJednaTrzeciaFloat -> e = %20.15lf\n", d, e);

  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu poprawności jego działania)
  // //** - zdefiniowanie symbolu zawierającego wyrażenie arytmetyczne bez użycia nawiasu
  // //**   (np. #define JednaTrzecia (1.0/3.0) ) i znalezienie zastosowania prowadzącego do błędu
  // //**   (np. dla symbolu powyżej operacja: (1.0/3.0) / JednaTrzecia ), obserwacja wyniku
  // //** - wyjaśnienie źródła błędu
  // //** - własne przykłady dla powyższej sytuacji


  //-------------------------------------------- 4.0 --------------------------------------------
  
  // //** WŁASNE EKSPERYMENTY
  // //** ze zmiennymi całkowitymi, operatorami i ich priorytetami
  // //** np. sprawdzenie efektu operacji m+n, m++n, m+++n, m++++n, m+++++n, m+++n++++, itd.
  //printf("\nn = %d, m = %d\n", n, m);
  //o = m...n;
  //printf("\tpo operacji o = m...n = %d: n = %d, m = %d\n", o, n, m);


  /* 7. PROBLEMY Z PRECYZJĄ LICZB ZMIENNOPRZECINKOWYCH */

  //  printf("\nProblemy z precyzją zmiennych float i double:\n");

  // //** kłopoty z precyzją:
  //  float fx1 = 1.23e7;
  //  float fx2 = 1.23e-7;

  //  printf("\nfloat: fx1 = %20.15lf, fx2 = %20.15lf, \n", fx1, fx2);
  //  if( (fx1+fx2)-fx1 == fx2 ){
  //    printf("\n(fx1+fx2)-fx1 == fx2 (dla float)\n");
  //  }
  //  else {
  //    printf("\n(fx1+fx2)-fx1 != fx2 (dla float) ( (fx1+fx2)-fx1 = %.15lf )\n",
  //  	   (fx1+fx2)-fx1);
  //  }

  // //** kłopoty z precyzją:
  //  double dx1 = 1.23e7;
  //  double dx2 = 1.23e-7;


  //  printf("\ndouble: dx1 = %20.15lf, dx2 = %20.15lf, \n",
  //  	 dx1, dx2);
  //  if( (dx1+dx2)-dx1 == dx2 ){
  //    printf("\n(dx1+dx2)-dx1 == dx2 (dla double)\n");
  //  }
  //  else {
  //    printf("\n(dx1+dx2)-dx1 != dx2 (nawet dla double!) ( (dx1+dx2)-dx1 = %.15lf )\n",
  //  	   (dx1+dx2)-dx1);
  //  }
 

  // //** obsługa błędów - temat rzeka
  // //** wariant prosty:

  // //** chcemy obliczyć 1 / ( (fx1+fx2)-fx1 ) - powinno być równe 1/fx2

  // //** próba uniknięcia dzielenia przez zero:
  // //** if( fx2 != 0.0 ){ - błędy: 1. (fx1+fx2)-fx1 != fx2, 2. porównanie float

  // //** poprawna próba uniknięcia dzielenia przez zero lub utraty precyzji:
  // //** (należy wcześniej odkomentować definicje stałej nazwanej TOLERANCE na początku pliku)
  //  if( fabs ((fx1+fx2)-fx1) < TOLERANCE){
  //    printf("\nPróba dzielenia przez liczbę bliską zero! Przerwanie programu!\n");    
    //return(-1); 
    // //** lub exit(-1) - exit przerywa wykonanie całego programu, nie tylko aktualnej funkcji    
  //  }

  //  float fx3 = 1.0f / ((fx1+fx2)-fx1); // powinno byc równe 1/fx2...
  //  printf("\n1.0f / ((fx1+fx2)-fx1) = %20.15lf\n", fx3);
  
  //  double dx3 = 1.0 / ((dx1+dx2)-dx1); // powinno byc równe 1/dx2...
  //  printf("\n1.0/((dx1+dx2)-dx1) = %.12lf  != 1.0/dx2 = %.12lf\n", dx3, 1.0/dx2);
  //  printf("Zostały tylko trzy cyfry znaczące na skutek skończonej precyzji...\n");

  // //** !!!!!!!! ******* !!!!!!!!
  // //** ZADANIA WŁASNE (po odkomentowaniu powyższego kodu i sprawdzeniu jego działania)
  // //**(opis działania kodu z wyjaśnieniem przyczyn problemów z precyzją powinien znaleźć sie w sprawozdaniu)
  // //** - zadania rozszerzające z tematu laboratorium  
  
  printf("\nProgram dotarł do końca\n");
  return(0);
}

