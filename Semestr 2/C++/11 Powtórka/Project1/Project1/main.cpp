#include "header.h"


int main()
{
    int zadanie;

    std::cout << "Wybor zadan" << std::endl << "0 : wyjscie" << std::endl << "1-6 : Zadania" << std::endl;
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
        }/*
        case 6:
        {
            zadanie6();
            cout << endl << endl;
            break;
        }/*
        case 7:
        {
            zadanie7();
            cout << endl << endl;
            break;
        }/*
        case 8:
        {
            zadanie8();
            cout << endl << endl;
            break;
        }/*
        case 9:
        {
            zadanie9();
            cout << endl << endl;
            break;
        }*/
        default:
        {
            cout << "Nie ma takiego zadania (albo go nie zrobilem)" << endl << endl;
        }
        }
        std::cout << "Wybor zadan" << std::endl << "0 : wyjscie" << std::endl << "1-6 : Zadania" << std::endl;
        std::cin >> zadanie;
        cout << endl;
    }
    return 0;
}

void zadanie1()
{
    adres* wsk = new adres("Glowna", 2137);
    pracownik p1("Jan", "Kowalski", wsk);
    pracownik p2("Magdalena", "Kowalska", wsk);
    p1.pokaz_p();
    p1.pokaz_a();
    p2.pokaz_p();
    p2.pokaz_a();
    delete wsk;
}

void zadanie2()
{
    int tab[5] = { 1,2,3,4,5 };
    wypisz(tab,5);
}

void zadanie3()
{
    int tab[5] = {96,8,2137,-42,8};
    cout << "Tablica: ";
    wypisz(tab, 5);
    cout << endl;
    znajdz_m<int> helper;
    cout << "Max = " << helper.daj_max(tab, 5) << endl << "Min = " << helper.daj_min(tab, 5) << endl;
}

void zadanie4()
{
    kadra a("Tomasz", "Karolak", "Wyzsze");
    a.pokaz_c();
}

void zadanie5()
{
    MyClass a(1);
    MyClass b(a);
}
