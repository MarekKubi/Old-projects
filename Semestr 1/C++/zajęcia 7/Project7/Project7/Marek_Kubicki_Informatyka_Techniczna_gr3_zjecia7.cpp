#include <iostream>
#include <string>
#include <math.h>

// stingMoj.c 

using namespace std;

string liczby_16 = "0123456789ABCDEF";

void zadanie_10_do_2();
void obliczenia_10_do_2(int liczba_wejscowa, char* liczba_wyjscowa, int rzad_wielkosci);
void zadanie_10_do_16();
void obliczenia_10_do_16(int liczba_wejscowa, char* liczba_wyjscowa, int rzad_wielkosci_2, int rzad_wielkosci_16);
void zadanie_2_do_10();
int obliczenia_2_do_10(char* liczba_b, int len);
void zadanie2_do_16();
void obliczenia2_do_16(char* liczba_wejscowa, char* liczba_wyjscowa, int rzad_wielkosci_2, int rzad_wielkosci_16);
void zadanie8_do_2();
void zadanie8_16_10();
int obliczenia8_16_do_10(char* liczba_wejscowa, int rzad_wielkosci_8_16, int typ_wejsca);
void zadanie8_do_16();

int main()
{
    int zadanie;

    cout << "UWAGA!!!  liczby w systemie szesnastkowym nalezy podawac za pomoca duzych liter (A B C D E F)" << endl;
    std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "1-Zadanie a - 10_do_2" << std::endl << "2-Zadanie b - 10_do_16" << std::endl
        << "3-Zadanie c - 2_do_10" << std::endl << "4-Zadanie d - 2_do_16" << std::endl << "5-Zadanie e - 8_do_2" << std::endl << "6-Zadanie f - 16_do_10" << std::endl << "7-Zadanie g - 8_do_16" << std::endl;
    std::cin >> zadanie;

    while (zadanie != 0)
    {
        switch (zadanie)
        {
        case 1:
        {
            zadanie_10_do_2();
            std::cout << std::endl << std::endl;
            break;
        }
        case 2:
        {
            zadanie_10_do_16();
            std::cout << std::endl << std::endl;
            break;
        }

        case 3:
        {
            zadanie_2_do_10();
            std::cout << std::endl << std::endl;
            break;
        }
        case 4:
        {
            zadanie2_do_16();
            std::cout << std::endl << std::endl;
            break;
        }
        case 5:
        {
            zadanie8_do_2();
            std::cout << std::endl << std::endl;
            break;
        }
        case 6:
        {
            zadanie8_16_10();
            std::cout << std::endl << std::endl;
            break;
        }
        case 7:
        {
            zadanie8_do_16();
            std::cout << std::endl << std::endl;
            break;
        }
        }
        cout << "UWAGA!!!  liczby w systemie szesnastkowym nalezy podawac za pomoca duzych liter (A B C D E F)" << endl;
        std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "1-Zadanie a - 10_do_2" << std::endl << "2-Zadanie b - 10_do_16" << std::endl
            << "3-Zadanie c - 2_do_10" << std::endl << "4-Zadanie d - 2_do_16" << std::endl << "5-Zadanie e - 8_do_2" << std::endl << "6-Zadanie f - 16_do_10" << std::endl << "7-Zadanie g - 8_do_16" << std::endl;
        std::cin >> zadanie;
    }
    return 0;
}

void zadanie_10_do_2()
{
    int liczba_wejscowa;
    cout << "Pdaj liczbe(10): ";
    cin >> liczba_wejscowa;
    char* liczba_wyjscowa;
    int rzad_wielkosci = 1;
    while (true)
    {
        if (pow(2, rzad_wielkosci)> liczba_wejscowa)
        {
            break;
        }
        else 
        {
            rzad_wielkosci++;
        }
    }
    liczba_wyjscowa= new char [rzad_wielkosci];
    obliczenia_10_do_2(liczba_wejscowa, liczba_wyjscowa, rzad_wielkosci);
    cout << endl << "Ta liczba w zapisie binarnym to: ";
    for (int i = 0; i < rzad_wielkosci; i++)
    {
        cout << liczba_wyjscowa[i];
    }
    delete[] liczba_wyjscowa;
}
void obliczenia_10_do_2(int liczba_wejscowa, char* liczba_wyjscowa, int rzad_wielkosci)
{
    for (int i = 0; i < rzad_wielkosci; i++)
    {
        if (liczba_wejscowa >= (pow(2, rzad_wielkosci - i -1)))
        {
            liczba_wyjscowa[i] = '1';
            liczba_wejscowa = liczba_wejscowa - (pow(2, rzad_wielkosci - i - 1));
        }
        else
        {
            liczba_wyjscowa[i] = '0';
        }
    }
}
void zadanie_10_do_16()
{
    int liczba_wejscowa = 0;
    cout << "Pdaj liczbe(10): ";
    cin >> liczba_wejscowa;
    char* liczba_wyjscowa;
    int rzad_wielkosci_2 = 1;
    while (true)
    {
        if (pow(2, rzad_wielkosci_2) > liczba_wejscowa)
        {
            break;
        }
        else
        {
            rzad_wielkosci_2++;
        }

    }
    int rzad_wielkosci_16 = rzad_wielkosci_2 / 4;
    if ((rzad_wielkosci_2 % 4) != 0)
    {
        rzad_wielkosci_16++;
    }
    
    liczba_wyjscowa = new char[rzad_wielkosci_16];

    obliczenia_10_do_16(liczba_wejscowa, liczba_wyjscowa, rzad_wielkosci_2, rzad_wielkosci_16);
    cout << endl << "Ta liczba w zapisie szesnastkowym to: ";
    for (int i = 0; i < rzad_wielkosci_16; i++)
    {
        cout << liczba_wyjscowa[i];
    }
    delete[] liczba_wyjscowa;
}
void obliczenia_10_do_16(int liczba_wejscowa, char* liczba_wyjscowa, int rzad_wielkosci_2, int rzad_wielkosci_16)
{
    
    char* liczba_b;
    liczba_b = new char[rzad_wielkosci_2];
    obliczenia_10_do_2(liczba_wejscowa, liczba_b, rzad_wielkosci_2);

    obliczenia2_do_16(liczba_b, liczba_wyjscowa, rzad_wielkosci_2, rzad_wielkosci_16);

    delete[] liczba_b;
}  
void zadanie_2_do_10()
{
    string liczba;
    char* liczba_b;
    cout << "Podaj liczbe(2): ";
    cin >> liczba;
    int len = liczba.length();
    liczba_b = new char [len];
    for (int i = 0; i < len; i++)
    {
        liczba_b[i] = liczba[i];
    }
    int liczba_d = obliczenia_2_do_10(liczba_b, len);
    cout << endl << "Ta liczba w zapisie dziesietnym to: ";
    cout << liczba_d;
    delete[] liczba_b;
}
int obliczenia_2_do_10(char* liczba_b, int len)
{
    int liczba_d = 0;
    for (int i = 1; i < len+1; i++)
    {
        if (liczba_b[len-i] == '1')
        {
            liczba_d += (pow(2, i-1));
        }
    }
    return liczba_d;
}
void zadanie2_do_16()
{
    string liczba;
    char* liczba_b;
    cout << "Podaj liczbe(2): ";
    cin >> liczba;
    int len = liczba.length();
    liczba_b = new char[len];
    char* liczba_wyjscowa;
    for (int i = 0; i < len; i++)
    {
        liczba_b[i] = liczba[i];
    }
    int rzad_wielkosci_16 = len / 4;
    if ((len % 4) != 0)
    {
        rzad_wielkosci_16++;
    }
    liczba_wyjscowa = new char[rzad_wielkosci_16];

    obliczenia2_do_16(liczba_b, liczba_wyjscowa, len, rzad_wielkosci_16);

    cout << endl << "Ta liczba w zapisie szesnastkowym to: ";

    for (int i = 0; i < rzad_wielkosci_16; i++)
    {
        cout << liczba_wyjscowa[i];
    }
    
}
void obliczenia2_do_16(char* liczba_wejscowa, char* liczba_wyjscowa, int rzad_wielkosci_2, int rzad_wielkosci_16)
{
    int pozycja = 0;
    int roznica = (rzad_wielkosci_16 * 4) - rzad_wielkosci_2 ;
    for (int i = rzad_wielkosci_16 - 1; i > -1; i--)
    {
        for (int j = 0; j < 4; j++)
        {
            if (((i * 4) + 3 - roznica - j) < 0)
            {
                liczba_wyjscowa[i] = liczby_16[pozycja];
                break;
            }
            if (liczba_wejscowa[(i * 4) +3 - roznica -j] == '1')
            {
                pozycja = pozycja + pow(2, j);
            }
        }
        liczba_wyjscowa[i] = liczby_16[pozycja];
        pozycja = 0;
    }
}
void zadanie8_do_2()
{
    string liczba;
    int typ_wejsca = 8;
    char* liczba_wejscowa;
    cout << "Podaj liczbe(8): ";
    cin >> liczba;
    int len = liczba.length();
    liczba_wejscowa = new char[len];
    for (int i = 0; i < len; i++)
    {
        liczba_wejscowa[i] = liczba[i];
    }
    int liczba_d = obliczenia8_16_do_10(liczba_wejscowa, len, typ_wejsca);
    char* liczba_wyjscowa;
    int rzad_wielkosci = 1;
    while (true)
    {
        if (pow(2, rzad_wielkosci) > liczba_d)
        {
            break;
        }
        else
        {
            rzad_wielkosci++;
        }
    }
    liczba_wyjscowa = new char[rzad_wielkosci];
    obliczenia_10_do_2(liczba_d, liczba_wyjscowa, rzad_wielkosci);
    cout << endl << "Ta liczba w zapisie binarnym to: ";
    for (int i = 0; i < rzad_wielkosci; i++)
    {
        cout << liczba_wyjscowa[i];
    }
    delete[] liczba_wejscowa;

    delete[] liczba_wyjscowa;
}
void zadanie8_16_10()
{
    string liczba;
    int typ_wejsca = 16;
    char* liczba_wejscowa;
    cout << "Podaj liczbe(16): ";
    cin >> liczba;
    int len = liczba.length();
    liczba_wejscowa = new char[len];
    for (int i = 0; i < len; i++)
    {
        liczba_wejscowa[i] = liczba[i];
    }
    int liczba_d = obliczenia8_16_do_10(liczba_wejscowa, len, typ_wejsca);
    cout << endl << "Ta liczba w zapisie dziesietnym to: " << liczba_d << endl;
}
int obliczenia8_16_do_10(char* liczba_wejscowa, int rzad_wielkosci_8_16, int typ_wejsca)
{
    int wynik = 0;
    int ktore = 0;
    for (int i = rzad_wielkosci_8_16 - 1; i > -1; i--)
    {
        for (int j = 0; j < 16; j++)
        {
            if (liczby_16[j] == liczba_wejscowa[i])
            {
                ktore = j;
                break;
            }
        }
        wynik += (pow(typ_wejsca, rzad_wielkosci_8_16 - i - 1) * ktore);
    }
    return wynik;
}
void zadanie8_do_16()
{
    string liczba;
    int typ_wejsca = 8;
    char* liczba_wejscowa;
    cout << "Podaj liczbe(8): ";
    cin >> liczba;
    int len = liczba.length();
    liczba_wejscowa = new char[len];
    for (int i = 0; i < len; i++)
    {
        liczba_wejscowa[i] = liczba[i];
    }
    int liczba_d = obliczenia8_16_do_10(liczba_wejscowa, len, typ_wejsca);

    char* liczba_wyjscowa;
    int rzad_wielkosci_2 = 1;
    while (true)
    {
        if (pow(2, rzad_wielkosci_2) > liczba_d)
        {
            break;
        }
        else
        {
            rzad_wielkosci_2++;
        }

    }
    int rzad_wielkosci_16 = rzad_wielkosci_2 / 4;
    if ((rzad_wielkosci_2 % 4) != 0)
    {
        rzad_wielkosci_16++;
    }

    liczba_wyjscowa = new char[rzad_wielkosci_16];

    obliczenia_10_do_16(liczba_d, liczba_wyjscowa, rzad_wielkosci_2, rzad_wielkosci_16);

    cout << endl << "Ta liczba w zapisie szesnastkowym to: ";

    for (int i = 0; i < rzad_wielkosci_16; i++)
    {
        cout << liczba_wyjscowa[i];
    }
}