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
        }/*
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
    Class zb_1(1, 5);
    cout << "Zbiot 1:" << endl << "x = " << zb_1.x << endl << "y = " << zb_1.y << endl;

    Class zb_2(20, 7);
    cout << "Zbiot 2:" << endl << "x = " << zb_2.x << endl << "y = " << zb_2.y << endl << endl;

    Class wynik = zb_1 + zb_2;
    cout << "Wynik:" << endl << "x = " << wynik.x << endl << "y = " << wynik.y << endl;
}

void zadanie2()
{
    klassa_2 zb_1(1, 5);
    cout << "Zbiot 1:" << endl << "x = " << zb_1.daj_x() << endl << "y = " << zb_1.daj_y() << endl;

    klassa_2 zb_2(20, 7);
    cout << "Zbiot 2:" << endl << "x = " << zb_2.daj_x() << endl << "y = " << zb_2.daj_y() << endl << endl;

    klassa_2 wynik = zb_1 + zb_2;
    cout << "Wynik:" << endl << "x = " << wynik.daj_x() << endl << "y = " << wynik.daj_y() << endl;
}

void zadanie3()
{
    Punkt2D a(2, 3);
    cin >> a;
    cout << "Punkt: " << a << endl;
}

