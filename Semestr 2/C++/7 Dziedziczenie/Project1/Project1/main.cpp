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
        }/*
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
    Prostokat pr;
    Trojkat tr;
    pr.Ustaw_wartosc(5, 10);
    tr.Ustaw_wartosc(5, 10);
    cout << "Prostokat: " << pr.daj_V() << endl << "Trojkat: " << tr.daj_V() << endl;

}

void zadanie2()
{
    Z helper;
    helper.met_z();
}

void zadanie3()
{
    Kolo a;
    a.Wyswietl();
}

void zadanie4()
{
    Hipopotam h;
    Kot k;
    string im = "klap";
    string ko = "czerwony";

    Pies p(im,ko,2,6);

    cout << "Hipopotam wiek = " << h.wiek << endl;
    cout << "Kot:" << endl;
    k.pokaz();
    cout << "Pies:" << endl;
    p.pokaz();
}
