#include <stdio.h>

// deklaracja funkcji
void prosta_funkcja( int test_main );

int main (void)
{

  // 1. definicja zmiennej test np. typu int z inicjowaniem
  int test_main = 5;
  // 2. drukowanie wartości zmiennej test
  printf("przed wywołaniem prostej funkcji: %d\n", test_main);

  // wywołanie funkcji
  // prosta_funkcja();

  // 6. (po wykomentowaniu wywołania powyżej) wywołanie funkcji z argumentem
	prosta_funkcja(test_main);
  // 7, 8, 9 - co trzeba zmienić po wykonaniu kroków 5 i 6, żeby program zadziałał?

  // 2. drukowanie wartości zmiennej test
  printf("po powrocie z prostej funkcji: %d\n", test_main);

}

// 5. zmiana definicji - przyjmowanie argumentu
void prosta_funkcja( int test_main )
{

  // 3. definicja zmiennej test np. typu int z inicjowaniem
	int test_fun = 10;
  // 4. drukowanie wartości zmiennej test
  printf("wewnątrz prostej funkcji: zmienna lokalna %d\n", test_fun);

  //11. drukowanie wartości argumentu
  printf("wewnątrz prostej funkcji: argument przed modyfikacją %d\n", test_main);
  
  // 10. zmiana wartości przesłanego argumentu
	test_main += test_fun;  
  // 11. drukowanie wartości argumentu
  printf("wewnątrz prostej funkcji: argument po modyfikacji %d\n", test_main);

  return;
}

