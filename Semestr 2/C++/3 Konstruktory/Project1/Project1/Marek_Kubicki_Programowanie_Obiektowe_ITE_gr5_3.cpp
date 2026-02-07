#include <iostream>
#include <string>

using namespace std;

class kasa
{
    int ilosc_szt;
    int cena_c;
    int ilosc_p[100];
    int cena_p[100];
    int i;
public:
    kasa();
    void wyczysc();
    void dodaj_p(int il, int wart);
    void pobierz_war(int wart);
    void ustal_il(int il);
    void wyswietl();
};

kasa::kasa()
{
    ilosc_szt = 0;
    cena_c = 0;
    ilosc_p[0] = {};
    cena_p[0] = {};
    i = -1;
}
void kasa::wyczysc()
{
    ilosc_szt = 0;
    cena_c = 0;
    i = -1;
}
void kasa::dodaj_p(int il, int wart)
{
    i++;
    ilosc_p[i] = il;
    cena_p[i] = wart;
}
void kasa::pobierz_war(int wart)
{
    cena_p[i] = wart;
}
void kasa::ustal_il(int il)
{
    ilosc_p[i] = il;
}
void kasa::wyswietl()
{
    for(int j = 0; j<=i; j++)
    {
        ilosc_szt += ilosc_p[j];
        cena_c += ilosc_p[j] * cena_p[j];
    }
    cout << "Ilosc produktow: " << ilosc_szt << endl << "Laczna cena: " << cena_c << endl;
}

class konto_bankowe
{
    int saldo;
public:
    konto_bankowe();
    konto_bankowe(int a);
    void depozyt();
    void wyplaty();
    void pobierz_saldo();
};
konto_bankowe::konto_bankowe()
{
    saldo = 0;
}
konto_bankowe::konto_bankowe(int a)
{
    saldo = a;
}
void konto_bankowe::depozyt()
{
    int a=0;
    cout << "Podaj wplacona kwote" << endl;
    cin >> a;
    saldo = saldo + a;
}
void konto_bankowe::wyplaty()
{
    int a=0;
    cout << "Podaj kwote do wyplaty" << endl;
    cin >> a;
    saldo = saldo - a;
}
void konto_bankowe::pobierz_saldo()
{
    cout << "Aktualne srodki na kacie: " << saldo << endl;
}


void zadanie1();
void zadanie2();/*
void zadanie4();
void zadanie5();
void zadanie6();
void zadanie7();
void zadanie8();
void zadanie9();*/


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
    kasa klient; 
    int a;
    int b;
    cout << "Podaj produkt" << endl;
    cin >> a;
    cin >> b;
    klient.dodaj_p(a, b);
    cout << "Podaj nowa cene" << endl;
    cin >> b;
    klient.pobierz_war(b);
    cout << "Podaj nowa ilosc" << endl;
    cin >> a;
    klient.ustal_il(a);

    cout << "Podaj produkt" << endl;
    cin >> a;
    cin >> b;
    klient.dodaj_p(a, b);

    cout << "Podaj produkt" << endl;
    cin >> a;
    cin >> b;
    klient.dodaj_p(a, b);

    klient.wyswietl();
    klient.wyczysc();
    klient.wyswietl();
}
void zadanie2()
{
    konto_bankowe klient_1;
    konto_bankowe klient_2(100);

    klient_1.depozyt();
    klient_2.depozyt();

    klient_1.wyplaty();
    klient_2.wyplaty();

    klient_1.pobierz_saldo();
    klient_2.pobierz_saldo();

}