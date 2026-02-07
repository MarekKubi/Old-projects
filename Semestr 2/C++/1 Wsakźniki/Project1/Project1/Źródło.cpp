#include <iostream>

 // Zadania s¹ wykonane w poszczególnych funkcjach ponumerowanych tak samo jak zadania

void zadanie1();
void zadanie2();
void zadanie3();
void zadanie4();
void zadanie5();
int dodaj_liczbe(int* wsk_1, int* wsk_2);
void zadanie6(); // Na potrzeby tego zadania funkcja zadanie6 = main
int Zmien(int* a);
void Wypisz(int a);
void zadanie9();
void Funkcja_1(int tab[4], int a);
void Funkcja_2(int* tab, int a);
void Funkcja_3(int tab[], int a);

using namespace std;

int main()
{
    int zadanie;

    std::cout << "Wybor zadan" << std::endl << "0 : wyjscie" << std::endl << "1-10 : Zadania" << std::endl;
    std::cin >> zadanie;
    cout << endl;
    while (zadanie != 0)
    {
        switch (zadanie)
        {
        case 1:
        {
            zadanie1();
            cout << endl << endl;
            break;
        }
        case 2:
        {
            zadanie2();
            cout << endl << endl;
            break;
        }
        case 3:
        {
            zadanie3();
            cout << endl << endl;
            break;
        }
        case 4:
        {
            zadanie4();
            cout << endl << endl;
            break;
        }
        case 5:
        {
            zadanie5();
            cout << endl << endl;
            break;
        }
        case 6:
        {
            zadanie6();
            cout << endl << endl;
            break;
        }
        case 9:
        {
            zadanie9();
            cout << endl << endl;
            break;
        }
        default:
        {
            cout << "Nie ma takiego zadania (albo go nie zrobi³em)" << endl << endl;
        }
        }
        std::cout << "Wybor zadan" << std::endl << "0 : wyjscie" << std::endl << "1-10 : Zadania" << std::endl; 
        std::cin >> zadanie;
        cout << endl;
    }
    return 0;
}


void zadanie1()
{
    int a = 0;
    int* pa = &a;
    int b = *pa;
    int c = a;
    if (a == c)
    {
        cout << "Instrukcje sa rownowazne" << endl;
    }
    else
    {
        cout << "Instrukcje nie sa rownowazne" << endl;
    }
}

void zadanie2()
{
    int tab_d[6] = { 0, 1, 2, 3, 4, 5};
    double tab_lf[6] = { 0.0, 1.0, 2.0, 3.0, 4.0, 5.0 };
    int* wsk_d;
    double* wsk_lf;
    for (int i = 0; i < 6; i++)
    {
        wsk_d = &tab_d[i];
        wsk_lf = &tab_lf[i];
        cout << "Nr. petli: " << i << endl << "Wskaznik na int: " << wsk_d << endl << "Wskaznik na double: " << wsk_lf << endl << endl;
    }
}

void zadanie3()
{
    srand((unsigned)time(0));
    int tab[15];
    cout << "Losowa tablica (zakres 0-1000): " << endl;
    for (int i = 0; i < 15; i++)
    {
        tab[i] = rand() %1000;
        cout << tab[i] << " ";
    }
    cout << endl << endl;

    int* wsk_1 = &tab[4]; //tab[4] jest pi¹tym elementem poniewa¿ elementy numeruje siê od 0
    int* wsk_2 = &tab[9];
    int* wsk_3 = &tab[10];


    cout << "Roznica wskaznikow wskazujacych na tab[10]-tab[4]: " << (wsk_3 - wsk_1) << endl;
    cout << "Roznica wskaznikow wskazujacych na tab[10]-tab[9]: " << (wsk_3 - wsk_2) << endl;
    cout << "Roznica wskaznikow wskazujacych na tab[9]-tab[4]: " << (wsk_2 - wsk_1) << endl;

    cout << endl;

    cout << "Roznica wskaznikow wskazujacych na tab[10]-tab[4]: " << (*wsk_3 - *wsk_1) << endl;
    cout << "Roznica wskaznikow wskazujacych na tab[10]-tab[9]: " << (*wsk_3 - *wsk_2) << endl;
    cout << "Roznica wskaznikow wskazujacych na tab[9]-tab[4]: " << (*wsk_2 - *wsk_1) << endl;

}

void zadanie4()
{
    int tab[5];
    int* wsk_1 = nullptr;
    int* wsk_2 = {};

    wsk_1 = &tab[2];

    cout << "Podaj na jaki element tablicy ma wskazywac 2 wskaznik (0 = tab[0])" << endl;
    int i;

    cin >> i;
    wsk_2 = &tab[i];

    if (i < 2 && -i <2)
    {
        cout << "2 wskaznik wskazuje na miejsce blizej poczatku tablicy";
    }
    else if (i == 2 || i == -2)
    {
        cout << "2 wskaznik wskazuje na miejsce w takiej samej odleglosci co 1 wskaznik";
    }
    else
    {
        cout << "2 wskaznik wskazuje na miejsce dalej od poczatku tablicy";
    }

    cout << endl << endl;

    if (i < 0 || i>4)
    {
        cout << "Uytkownik wybral element spoza tablicy" << endl;
    }
}

void zadanie5()
{
    int a, b;
    cout << "Podaj 2 liczby calkowite" << endl;
    cin >> a >> b;
    cout << "Suma tych liczb to: " << dodaj_liczbe(&a, &b);
}

int dodaj_liczbe(int* wsk_1, int* wsk_2)
{
    return (*wsk_1 + *wsk_2);
}

void zadanie6()
{
    int a = 100;
    Wypisz(a);
    Zmien(&a);
    Wypisz(a);
    Zmien(&a);
    Wypisz(a);
}


int Zmien(int* a)
{
    *a = *a + 5;
    return 0;
}

void Wypisz(int a)
{
    cout << "Wartosc zmiennej: " << a << endl;
}

void zadanie9()
{
    int tab[4] = { 5, 10 ,15 ,20 };

    Funkcja_1(tab, 4);
    Funkcja_2(&tab[0], 4);
    Funkcja_3(tab, 4);
}


void Funkcja_1(int tab[4], int a)
{
    cout << "Tablica: " << endl;
    for (int i = 0; i < a; i++)
    {
        cout << tab[i] << " " << endl;
    }
}
void Funkcja_2(int* tab, int a)
{
    cout << "Tablica: " << endl;
    for (int i = 0; i < a; i++)
    {
        cout << tab[i] << " " << endl;
    }
}
void Funkcja_3(int tab[], int a)
{
    cout << "Tablica: " << endl;
    for (int i = 0; i < a; i++)
    {
        cout << tab[i] << " " << endl;
    }
}