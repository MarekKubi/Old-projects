#include <iostream>
#include <windows.h>

void zadanie1();
void los();
void zadanie2();
double konwertor(double liczba, int jednostka);
void zadanie3();
int czypit(int a,int b,int c);
void zadanie4();
int* ciagarrr(int a,int r);
void zadanie5();
double* ciaggeee(double a, double g);
void zadanie6();


int main()
{
    int zadanie;

    std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "Zadanie 1 - Totolotek" << std::endl << "Zadanie 2 - Konwertor" << std::endl
        << "Zadanie 3 - Pitagoras" << std::endl << "Zadanie 4 - Ciag arytmetyczny" << std::endl << "Zadanie 5 - Ciag geometryczny" << std::endl << "Zadanie 6 - Ciag Fibonacciego" << std::endl;
    std::cin >> zadanie;

    while (zadanie != 0)
    {
        switch (zadanie)
        {
        case 1:
        {
            zadanie1();
            std::cout << std::endl << std::endl;
            break;
        }
        case 2:
        {
            zadanie2();
            std::cout << std::endl << std::endl;
            break;
        }
        case 3:
        {
            zadanie3();
            std::cout << std::endl << std::endl;
            break;
        }
        case 4:
        {
            zadanie4();
            std::cout << std::endl << std::endl;
            break;
        }
        case 5:
        {
            zadanie5();
            std::cout << std::endl << std::endl;
            break;
        }
        case 6:
        {
            zadanie6();
            std::cout << std::endl << std::endl;
            break;
        }
        }
        std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "Zadanie 1 - Totolotek" << std::endl << "Zadanie 2 - Konwertor" << std::endl
            << "Zadanie 3 - Pitagoras" << std::endl << "Zadanie 4 - Ciag arytmetyczny" << std::endl << "Zadanie 5 - Ciag geometryczny" << std::endl << "Zadanie 6 - Ciag Fibonacciego" << std::endl;
        std::cin >> zadanie;
    }
    return 0;
}

void zadanie1()
{
	std::cout << "Wylosowane liczby to" << std::endl;
	los();
}


void los()
{
	int lotek;
	srand((unsigned)time(0));
	for (int i = 0; i < 6; i++)
	{
		lotek = (rand() % 49 + 1);
		std::cout << i+1 << ".  " << lotek << std::endl;
        Sleep(360);
	}
}

void zadanie2()
{
    double liczba;
    int jednostka;
    std::string tl[3];
    tl[0] = "bar";
    tl[1] = "tor";
    tl[2] = "psi";
    std::cout << "Podaj ilosc Pa (paskali)" << std::endl;
    std::cin >> liczba;
    std::cout << std::endl << "Podaj jednostke docelowa 1-bar 2-tor 3-psi" << std::endl;
    std::cin >> jednostka;
    jednostka--;
    std::cout << std::endl;
    double w = konwertor(liczba,jednostka);

    std::cout << "wynik to: " << w << " " << tl[jednostka] << std::endl;
}

double konwertor(double liczba, int jednostka)
{
    double w;
    switch (jednostka)
    {
        case 0:
        {
            w = liczba / 10000;
            break;
        }
        case 1:
        {
            w = liczba * 75 / 100000;
            break;
        }
        case 2:
        {
            w = liczba * 145038 /100000000;
            break;
        }
    }
    return w;
}

void zadanie3()
{
    int a;
    int b;
    int c;
    std::cout << "Podaj 3 liczby (a; b; c)" << std::endl;
    std::cin >> a >> b >> c;
    int czy = czypit(a, b, c);

    if (czy == 1)
    {
        std::cout << "Te liczby sa pitagorejskie" << std::endl;
    }
    else
    {
        std::cout << "Te liczby nie sa pitagorejskie" << std::endl;
    }



}

int czypit(int a, int b, int c)
{
    int czy;
    if ((a * a) + (b * b) == (c * c))
    {
        czy = 1;
    }
    else
    {
        czy = 0;
    }
    return czy;
}


void zadanie4()
{
    int a;
    int r;
    std::cout << "Podaj pierwszy wyraz ciagu" << std::endl;
    std::cin >> a;
    std::cout << std::endl << "Podaj ruznice ciagu" << std::endl;
    std::cin >> r;

    int* tab = ciagarrr(a, r);
}

int* ciagarrr(int a, int r)
{
    int tab[100];
    for (int i = 0; i < 100; i++)
    {
        tab[i] = a;
        std::cout << i+1 << ". " << a << std::endl;
        a += r;
    }
    return tab;
}



void zadanie5()
{
    double a;
    double g;
    std::cout << "Podaj pierwszy wyraz ciagu" << std::endl;
    std::cin >> a;
    std::cout << std::endl << "Podaj iloraz ciagu" << std::endl;
    std::cin >> g;

    double* tab = ciaggeee(a, g);
}

double* ciaggeee(double a, double g)
{
    double tab[100];
    for (int i = 0; i < 100; i++)
    {
        tab[i] = a;
        std::cout << i + 1 << ". " << a << std::endl;
        a = a * g;
    }
    return tab;
}

void zadanie6()
{
    int fib1 = 0;
    int fib2 = 1;
    int i=1;
    int a;
    std::cout << "Podaj ile liczb Fibonacciego" << std::endl;
    std::cin >> a;
    a++;
    std::cout << i << ".     "<< fib1 << std::endl;
    i++;
    std::cout << i << ".     " << fib2 << std::endl;
    while (a > i)
    {
        fib1 += fib2;
        std::cout << i << ".     " << fib1 << std::endl;
        i++;
        if (a == i)
        {
            break;
        }
        fib2 += fib1;
        std::cout << i << ".     " << fib2 << std::endl;
        i++;
    }
}
