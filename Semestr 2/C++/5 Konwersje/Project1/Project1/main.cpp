#include "Header.h"


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
            zadanie2();
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
    TUlamek obiekt1(1, 5);
    TUlamek obiekt2(2, 5);
    TUlamek obiekt3 = mnozenie(obiekt1, obiekt2);
    cout << "Mnozenie 1/5 i 2/5: " << endl;
    obiekt3.wyswietl();
    cout << "Konwertowane: " << obiekt3.konwert() << endl;

    TUlamek obiekt4 = mnozenie(obiekt1, 10);

    cout << "Mnozenie 1/5 i 10: " << endl;
    obiekt4.wyswietl();
    cout << "Konwertowane: " << obiekt4.konwert() << endl;

    cout << "Kwadrat 2/5: " << obiekt2.Kwadrat() << endl;
}

void zadanie2()
{
    cout << "Z dwoma domniemanymi argumentami:" << endl;
    TZespolona c1(1.5, 5.0);
    Pokaz(c1);

    cout << "Z jednym domniemanym argumentem:" << endl;
    TZespolona c2(2.5);
    Pokaz(c2);

    cout << "Dla dynamicznie tworzonego obiektu z jednym argumentem domniemanym:" << endl;
    TZespolona* c3;
    c3 = new TZespolona(3.5);
    Pokaz(*c3);
    delete c3;
}