#include <stdio.h>

int main( void ) // program kopiowania z stdin na stdout

{
  int c;
/*
  c = getchar();

  while (c != EOF) {
    putchar(c);
    c = getchar ();
  }
 */
  // 1. zamiana programu jak wyżej na program wykorzystujący formę skrótową 
  // (po sprawdzeniu działania programu oryginalnego, należy go wykomentować w całości,
  // a następnie napisać (odkomentować) wersję skróconą (poniżej)
printf("Maksymalna dlugosc tablicy to 15\n");
int tablica[15];
int a = 0;
int i;
while( (c = getchar()) != EOF) 
{
	if(c == 10)
	{
		printf("\n");
		break;
	}
	putchar(c); 
	tablica[a] = c;
	a++;
	
}



  // 7. Wpisani
//prawdzeniu poprawności działania wprowadzenie kończenia wczytywania
  //   po wpisaniu znaku końca linii
  
  
  // 2. Dodanie wczytywania do tablicy znaków
  //    - definicja tablicy przed pętlą (z zadaną maksymalna długością napisu)
  //    - po wczytaniu do zmiennej c i wypisaniu na ekranie, podstawienie do tablicy
  //    - uwaga na zakończenie tablicy:
  //       - długość nie może być zbyt duża (wprowadzenie nowych warunków)
  //       - koniec musi byc zawsze zgodny z konwencją
  
  // 3. Dodanie wypisywania wczytanych znaków jako liczb całkowitych

  // Program switch.c - w innym pliku

  // - po s
  //-------------------------------- 3.0 ------------------------------------

  // 5. Wpisanie kodu (na podstawie wykładu) zliczającego liczbę znaków w tablicy
  //    - ewentualna zamiana pętli for na while
 printf("Liczba znakow w tablicy to %d\n", a);
  // 6. Wpisanie kodu (na podstawie wykładu) przepisującego zawartość jednej tablicy
  //    znaków do drugiej (ewentualna zamiana pętli while na do)
//e kodu (na podstawie wykładu) porównującego zawartość dwóch tablic
  //    - ewentualna zamiana pętli do na while lub for
// program zliczania cyfr i innych znaków we wczytywanym napisie
int inne=0;
int liczby=0; // zmienne do zliczania
int duze_litery=0;
int male_litery=0; // w tym tablica inicjowana zerami
// c definiowane jako int bo EOF niekoniecznie jest znakiem
i=0;
  while( i<a) { // wczytywanie kolejnych znaków aż do EOF
    
/*
switch (c) {
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      ndigit[c-'0']++; 
      // printf("%c, %d,  %d\n", c, c-'0', ndigit[c-'0']); - wydruk kontrolny
      // (istnieją specjalne konstrukcje ułatwiające sprawdzanie na bieżąco
      // poprawności programu (np. assert, static_assert) )
      break;
    case ' ': case '\n': case '\t': // znaki traktowane jako "white space"
      nwhite++;
      break;
    default:
      nother++;
      break;
    }
*/

if(tablica[i] >47 && tablica[i]<58)
{
	liczby++;
}
else if(tablica[i] >64 && tablica[i]<91)
{
	duze_litery++;
}
else if(tablica[i] >96 && tablica[i]<123)
{
	male_litery++;
}
else 
{
	inne++;
}


i++;
}
  printf("Podano: \n liczby:  %d\nduze litery:  %d\n male litery:  %d\n inne:  %d\n", liczby, duze_litery, male_litery, inne);  


for(i=0; i<a; i++)
	{
		printf("   %d\n", tablica[i]);
	}

for(i=0; i<a; i++)
{
	if(tablica[i]<123 && tablica[i]>96)
	{
		tablica[i] = tablica[i] -32;
	}
	else if(tablica[i]<91 && tablica[i]>64)
	{
		tablica[i] = tablica[i] +32;
	}
}

for(i=0; i<a; i++)
{
	putchar(tablica[i]);
}
printf("\n");
  //-------------------------------- 4.0 ------------------------------------

  // 8. Napisanie kodu tworzenia tablicy o okreslonej długości i wypełniania
  //     losowymi znakami ( z tablicy ASCII - od 0 do 127, lub dla wybranego
  //     podzbioru znaków, np. małych liter lub t.p.)

  // 9. Napisanie kodu tworzenia histogramu dla otrzymanej tablicy
  //    ( for(....) histogram[ tablica[i] - pierwszy_znak ] ++; )

  // 10. graficzna prezentacja histogramu
  
  //-------------------------------- 5.0 ------------------------------------

 

}

