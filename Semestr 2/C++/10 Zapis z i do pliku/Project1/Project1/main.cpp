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
    ofstream plik;
    plik.open("nowy_plik.txt");
    string tekst;
    if (plik.good())
    {
        cout << "Podaj imie: ";
        cin >> tekst;
        plik << tekst << "\n";
        cout << "Podaj nazwisko: ";
        cin >> tekst;
        plik << tekst << "\n";
        cout << "Podaj rok studiow: ";
        cin >> tekst;
        plik << tekst << "\n";
    }
    plik.close();
}

void zadanie2()
{
    ifstream plik;
    plik.open("nowy_plik.txt");
    string wiersz;
    if (plik.good())
    {
        getline(plik, wiersz);
        while (wiersz != "") {
            cout << wiersz << endl;
            getline(plik, wiersz);
        }
    }
    plik.close();
}

void zadanie3()
{
    fstream plik;
    plik.open("wizytowka.txt", ios::app);
    string tekst;
    if (plik.good())
    {
        cout << "Podaj imie: ";
        cin >> tekst;
        plik << tekst << "\n";
        cout << "Podaj nazwisko: ";
        cin >> tekst;
        plik << tekst << "\n";
        cout << "Podaj nr. telefonu: ";
        cin >> tekst;
        plik << tekst << "\n";
    }
    plik.close();
}

void zadanie4()
{
    fstream plik;
    plik.open("wizytowka.txt");
    string wiersz;
    if (plik.good())
    {
        getline(plik, wiersz);
        while (wiersz != "") {
            cout << wiersz << endl;
            getline(plik, wiersz);
        }
    }
    else
    {
        cout << "PLIK NIE ISTNIEJE!!!" << endl;
        exit;
    }
    plik.close();
}

void zadanie5()
{
    t10X10 p;
    p.czytaj_dane();
    p.zapisz_dane_do_pliku();
    p.czytaj_dane_z_pliku();
}