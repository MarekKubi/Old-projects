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
        }/*
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
        case 7:
        {
            zadanie7();
            cout << endl << endl;
            break;
        }
        case 8:
        {
            zadanie8();
            cout << endl << endl;
            break;
        }
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
    Potomek zwykly;
    cout << "przez obiekty – \"zwykly\"" << endl;
    zwykly.Metoda();
    Rodzic* wsk;
    wsk = &zwykly;
    cout << "przez wskaznik" << endl;
    (*wsk).Metoda();
}
void zadanie2()
{
    Kula k(5.0);
    cout << "Kula, promien = 5" << endl;
    cout << "Pole = " << k.Pole_Powierzchni() << endl;
    cout << "Objetosc = " << k.Objetosc() << endl;
    
    Prostopadloscian p(5.0, 10.0, 2.5);
    cout << "Prostopadloscian, a = 5, b = 10, h = 2,5" << endl;
    cout << "Pole = " << p.Pole_Powierzchni() << endl;
    cout << "Objetosc = " << p.Objetosc() << endl;

    Bryla a; //stworzyl sie
}

