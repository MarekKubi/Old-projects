#include <stdio.h>

// definicja typu strukturalnego (można podać obie postacie i korzystać później z jednej z nich)
// 3.a bez użycia typedef
struct zwierze_bez_t
{
	char* nazwa;
	int ilosc;
	double sr_waga;
};
// 3.b z użyciem typedef
typedef struct
{
	char* nazwa;
	int ilosc;
	double sr_waga;
} zwierze;
// 5.1.a deklaracja funkcji fun_strukt
void fun_strukt(zwierze obiekt_1);
// 5.3.a deklaracja funkcji fun_strukt_out
zwierze fun_strukt_out(zwierze obiekt_1);
// 5.5.a deklaracja funkcji fun_strukt_wsk
void fun_strukt_wsk(zwierze* obiekt_2_wsk);
int main (void)
{

  // 4.1 definicja zmiennej (np. obiekt_1) typu strukturalnego
	zwierze obiekt_1;
  // 4.2 nadanie wartości pól zmiennej obiekt_1 z pomocą operatora .
	obiekt_1.nazwa = "koala pospolita";
	obiekt_1.ilosc = 1234;
	obiekt_1.sr_waga = 63.48;
  // 4.3 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
  //    np. printf("Początkowe wartości pól obiekt_1: ....", ....);
	printf("Początkowe wartości pól obiekt_1: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n", obiekt_1.nazwa, obiekt_1.ilosc, obiekt_1.sr_waga);
  // 5.2.1 wywołanie funkcji fun_strukt (po deklaracji w p. 5.1.a i definicji w p. 5.1.b)
  //      z obiektem 1 jako argumentem 
	fun_strukt(obiekt_1);
  // 5.2.2 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
  //    np. printf("Po wywołaniu fun_strukt - wartości pól obiekt_1: ....", ....);
	printf("\n\nPo wywołaniu fun_strukt");
	printf(" - wartości pól obiekt_1: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n", obiekt_1.nazwa, obiekt_1.ilosc, obiekt_1.sr_waga);
  // 5.4.1 wywołanie funkcji fun_strukt_out (po deklaracji w p. 5.3.a i definicji w p. 5.3.b)
  //      z obiektem_1 jako argumentem i przepisaniem wyniku z powrotem do obiektu_1
	obiekt_1 = fun_strukt_out(obiekt_1);
  // 5.4.2 wypisanie wartości pól zmiennej obiekt_1 z pomocą operatora .
  //    np. printf("Po wywołaniu fun_strukt_out i przypisaniu wyniku do obiekt_1\n");
  //        printf("- wartości pól obiekt_1: ....", ....);
	printf("\n\nPo wywołaniu fun_strukt_out i przypisaniu wyniku do obiekt_1\n");
	printf(" - wartości pól obiekt_1: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n", obiekt_1.nazwa, obiekt_1.ilosc, obiekt_1.sr_waga);
  
  // 4.4 definicja drugiej zmiennej typu strukturalnego  (np. obiekt_2)
  //    połączona z inicjowaniem za pomocą listy wartości
	zwierze obiekt_2 = { "wonz", 3042, 12.21};
  // 4.5 definicja wskaźnika (np. obiekt_2_wsk) do struktury zainicjowanego adresem obiektu_2
	zwierze* obiekt_2_wsk = &obiekt_2;
  // 4.6 wypisanie wartości pól obiektu_2 z pomocą wskaźnika do obiektu i operatora ->
  //    np. printf("Początkowe wartości pól obiekt_2: ....", ....);
	printf("\n\nPoczątkowe wartości pól obiekt_2: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n",  obiekt_2_wsk->nazwa, obiekt_2_wsk->ilosc, obiekt_2_wsk->sr_waga);
  // 5.6.1 wywołanie funkcji fun_strukt_wsk (po deklaracji w p. 5.5.a i definicji w p. 5.5.b)
  //      ze zmienną obiekt_2_wsk jako argumentem
	fun_strukt_wsk(obiekt_2_wsk);
  // 5.6.2 wypisanie wartości pól zmiennej obiekt_2 z pomocą wskaźnika do obiektu i operatora ->
	printf("\n\nPo wywołaniu fun_strukt_wsk wartości pól obiekt_2: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n",  obiekt_2_wsk->nazwa, obiekt_2_wsk->ilosc, obiekt_2_wsk->sr_waga);
  //    np. printf("Po wywołaniu fun_strukt_wsk - wartości pól obiekt_2: ....", ....);

  // 4.7 definicja trzeciej zmiennej typu strukturalnego  (np. obiekt_3)
  //    połączona z inicjowaniem za pomocą przepisania zawartości obiektu_2 w jednej
  //    operacji przypisania
	zwierze obiekt_3 = { obiekt_2.nazwa, obiekt_2.ilosc, obiekt_2.sr_waga};
  // 4.8 wypisanie wartości pól zmiennej obiekt_3 z pomocą operatora .
  //    np. printf("Początkowe wartości pól obiekt_3: ....", ....);
	printf("\n\nPoczątkowe wartości pól obiekt_3: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n", obiekt_3.nazwa, obiekt_3.ilosc, obiekt_3.sr_waga);
  //-------------------------------- 3.0 ------------------------------------

  // 8. wywołanie funkcji fun_strukt_wsk_kopia (po odpowiedniej deklaracji i definicji)
  //    z adresem obiektu 3 jako argumentem oraz przypisanie (skopiowanie) zwracanej przez
  //    fun_strukt_wsk_kopia struktury (z całą zawartością) do nowej zmiennej obiekt_4
  //    zaprojektowanego typu w operacji inicjowania

  //    wypisanie wartości pól zmiennej obiekt_4 z pomocą operatora .
  //    np. printf("Początkowe wartości pól obiekt_4: ....", ....);

  // 10. wywołanie funkcji fun_strukt_wsk_inout (po odpowiedniej deklaracji i definicji)
  //     z adresem obiektu 4 jako argumentem

  //    wypisanie wartości pól zmiennej obiekt_4 z pomocą operatora .
  //    np. printf("Po wywołaniu fun_strukt_wsk_inout - wartości pól obiekt_4: ....", ....);

  printf("Koniec programu.\n");
}

// 5.1.b definicja funkcji fun_strukt
void fun_strukt(zwierze obiekt_1)
{

	printf("\n\nWewnątrz fun_strukt");

  // wypisanie wartości pól struktury przesłanej jako argument
  // np. printf("Wewnątrz fun_strukt - wartości pól obiektu argumentu: ...", ...);
	printf("Wewnątrz fun_strukt - wartości pól obiekt_1: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n", obiekt_1.nazwa, obiekt_1.ilosc, obiekt_1.sr_waga);
  // modyfikacja wartości pól struktury
	obiekt_1.nazwa = "nie koala";
	obiekt_1.ilosc = 4321;
	obiekt_1.sr_waga = 48.63;
  // wypisanie zmodyfikowanych wartości pól struktury 
  // np. printf("Wewnątrz fun_strukt - zmodyfikowane wartości pól obiektu argumentu: ...", ...);
	printf("Wewnątrz fun_strukt - zmodyfikowane wartości pól obiektu argumentu: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n", obiekt_1.nazwa, obiekt_1.ilosc, obiekt_1.sr_waga);

}


// 5.3.b definicja funkcji fun_strukt_out
zwierze fun_strukt_out(zwierze obiekt_1)
{
	printf("\n\nWewnątrz fun_strukt_out");
  // wypisanie wartości pól struktury przesłanej jako argument
	printf("Wewnątrz fun_strukt_out - wartości pól obiekt_1: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n", obiekt_1.nazwa, obiekt_1.ilosc, obiekt_1.sr_waga);
  // modyfikacja wartości pól struktury
	obiekt_1.nazwa = "nie koala";
	obiekt_1.ilosc = 4321;
	obiekt_1.sr_waga = 48.63;
  // wypisanie zmodyfikowanych wartości pól struktury 
	printf("Wewnątrz fun_strukt_out - zmodyfikowane wartości pól obiektu argumentu: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n", obiekt_1.nazwa, obiekt_1.ilosc, obiekt_1.sr_waga);
  // zwrócenie struktury ze zmodyfikowanymi wartościami pól do funkcji wywołującej
return obiekt_1;
}


// 5.5.b definicja funkcji fun_strukt_wsk
void fun_strukt_wsk(zwierze* obiekt_2_wsk)
{
  // wypisanie wartości pól struktury wskaźnik do której został przesłany jako argument
	printf("\n\nWewnątrz fun_strukt_out - wartości pól obiekt_2: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n",  obiekt_2_wsk->nazwa, obiekt_2_wsk->ilosc, obiekt_2_wsk->sr_waga);
  // modyfikacja wartości pól struktury
	obiekt_2_wsk->nazwa= "rzeczny";
	obiekt_2_wsk->ilosc = 101;
	obiekt_2_wsk->sr_waga = 45.45;
  // wypisanie zmodyfikowanych wartości pól struktury 
	printf("Wewnątrz fun_strukt_out - wartości pól obiekt_2 po modyfikacji: \nnazwa: %s\nilosc: %d\nsr_waga: %lfkg\n",  obiekt_2_wsk->nazwa, obiekt_2_wsk->ilosc, obiekt_2_wsk->sr_waga);
}

