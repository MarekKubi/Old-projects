#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include <unistd.h>

int zmienna_wspolna=0;

#define WYMIAR 1000
#define ROZMIAR WYMIAR*WYMIAR
double a[ROZMIAR],b[ROZMIAR],c[ROZMIAR];

struct str
{
double in;
double out;
};

void * zadanie_watku (void * arg_wsk)
{
//unsigned int b = *(int*)arg_wsk;
//sleep(5);
	pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);
//	printf("\twatek potomny: uniemozliwione zabicie\n");
//int a=pthread_self();
//printf("\twatek potomny: self \nID: %d\n self ID: %lld\n", b,pthread_self());
//sleep(5);
//	czasozajmowacz();
struct str s
s.in = (*(struct str*)arg_wsk).in
s.out = s.in *s.in;
(*(struct str*)arg_wsk).out =s.out;
//	printf("\twatek potomny: umozliwienie zabicia\n");
	pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);

	pthread_testcancel();

zmienna_wspolna++;
//	printf("\twatek potomny: zmiana wartosci zmiennej wspolnej\n");

	return(NULL);
}

int main()
{
	pthread_t tid[5];
	//int id[5] = {0,1,2,3,4};
	struct str s[5];
	int i;
	int ilosc = 5;
	for(i=0;i<ilosc; i++)
{
(s[i]).in = i;

//sleep(1);
}
	
	pthread_attr_t attr;
	void *wynik;
for(i=0;i<ilosc; i++)
{
pthread_create(&(tid[i]), NULL, zadanie_watku, &(s[i]));
//sleep(1);
}
//	sleep(2); // czas na uruchomienie watku
for(i=0;i<ilosc; i++)
{
pthread_join(tid[i], NULL);
//sleep(1);
}
for(i=0;i<ilosc; i++)
{
printf("\nIN: %lf\n OUT: %lf\n", (s[i]).in,(s[i]).out);
}
}


