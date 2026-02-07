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
    cout << "Funkcja Dodaj:" << endl;

    string s1 = "dziala ";
    string s2 = "poprawnie\n";
    cout << "String \"dziala \" + \"poprawnie\": " << Dodaj(s1, s2);


    int i1 = 2;
    int i2 = 22;
    cout << "Int 2 + 22: " << Dodaj(i1, i2) << endl;


    double d1 = 3.14;
    double d2 = 2.718;
    cout << "Double pi(3.14) + e(2.718): " << Dodaj(d1, d2);
}
void zadanie2()
{
    cout << "Funkcja Max:" << endl;

    int i1 = 2;
    int i2 = 22;
    cout << "Int 2 + 22: " << Max(i1, i2) << endl;


    double d1 = 3.14;
    double d2 = 2.718;
    cout << "Double pi(3.14) + e(2.718): " << Max(d1, d2);
}
void zadanie3()
{
    Tablica<int> obj1(10);  
    Tablica<double> obj2(5);
}

void zadanie4()
{
    Kula<int> obj1(3);
    Kula<float> obj2(3.14f);
    Kula<double> obj3(2.718);

    cout << "int = 3" << endl << "Pole: " << obj1.Pole_Powierzchni() << endl << "Objetosc: " << obj1.Objetosc() << endl << endl;
    cout << "float = 3.14f" << endl << "Pole: " << obj2.Pole_Powierzchni() << endl << "Objetosc: " << obj2.Objetosc() << endl<< endl;
    cout << "double = 2.718" << endl << "Pole: " << obj3.Pole_Powierzchni() << endl << "Objetosc: " << obj3.Objetosc() << endl << endl;
}
