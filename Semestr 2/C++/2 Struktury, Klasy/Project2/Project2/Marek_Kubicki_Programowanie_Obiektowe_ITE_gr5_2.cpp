#include <iostream>
#include <string>

using namespace std;

#define SCALAR double
#define TOLERANCJA 1.e-19

struct T_data 
{
    int dzien;
    int miesiac;
    int rok;

    void Pobierz_date();
    void Wypisz_date()
    {
        cout << "Data urodzenia: ";
        if (dzien < 10)
        {
            cout << 0;
        }
        cout << dzien << ".";
        if (miesiac < 10)
        {
            cout << 0;
        }
        cout << miesiac << "." << rok << endl;
    }
};

void T_data::Pobierz_date()
{
    cout << "Podaj date urodzenia (dzien -> miesac -> rok)" << endl;
    cin >> dzien;
    cin >> miesiac;
    cin >> rok;
}

struct T_student
{
    char inicjal[2] ={};
    string nazwisko = "brak";
    int rok =0;
    int grupa =0;
    T_data moje_urodziny= {0,0,0};

    public:
    void Wczytaj();
    void Wypisz();
};

void T_student::Wczytaj()
{
    cout << "Podaj dane (inicjal -> nazwisko -> rok -> grupa" << endl;
    cin >> inicjal[0];
    inicjal[1] = '\0';
    cin >> nazwisko;
    cin >> rok;
    int tak = 0;
    while (rok > 6)
    {
        cout << "Podaj wlascniwy rok (<6)" << endl;
        cin >> rok;
    }
    cin >> grupa;
    if (grupa > 10)
    {
        cout << "Czy to jest wlasciwa grupa?(1-tak 0-nie)" << endl;
        cin >> tak;
        if (tak == 0)
        {
            while (grupa > 10)
            {

                cout << "Podaj grupe" << endl;
                cin >> grupa;
            }
        }
    }
    moje_urodziny.Pobierz_date();
}
void T_student::Wypisz()
{
    cout << "Dane studenta: " << endl << "inicjal i nazwisko: " << inicjal << ". " << nazwisko << endl << "rok: " << rok << endl << "grupa: " << grupa << endl;
    moje_urodziny.Wypisz_date();
}

struct T_pole
{
    float a;
    float b;
    float S;

public:
    void Czytaj_dane();
    void Przetworz_dane();
    void Wyswietl_wynik();
};

void T_pole::Czytaj_dane()
{
    cout << "Podaj dlugosci bokow" << endl;
    cin >> a;
    cin >> b;
}
void T_pole::Przetworz_dane()
{
    S = a * b;
}
void T_pole::Wyswietl_wynik()
{
    cout << "Boki prostokata to: " << a << " i " << b << endl;
    cout << "Pole prostokata to: ";
    printf("%.2f", S);
    cout << endl;
}

struct T_delta
{
    SCALAR a;
    SCALAR b;
    SCALAR c;
    SCALAR x1;
    SCALAR x2;
    int czy_p;
    int nie = 0;

public:
    void Czytaj_dane();
    void Przetworz_dane();
    void Wyswietl_wynik();
};

void T_delta::Czytaj_dane()
{
    cout << "Podaj dane" << endl;
    cin >> a;
    cin >> b;
    cin >> c;
    if (a < TOLERANCJA && -a>TOLERANCJA)
    {
        cout << "Nie jest to rownanie kwadratowe!!!" << endl;
        nie = 1;
    }
}
void T_delta::Przetworz_dane()
{
    SCALAR delta;
    delta = b * b - 4 * a * c;
    if (delta < TOLERANCJA && -delta>TOLERANCJA)
    {
        x1 = -b / (2 * a);
        x2 = x1;
        czy_p = 1;
    }
    else if (delta < 0)
    {
        czy_p = 0;
    }
    else
    {
        SCALAR temp = sqrt(delta);
        czy_p = 2;
        x1 = (-b - temp) / (2 * a);
        x2 = (-b + temp) / (2 * a);
    }
}
void T_delta::Wyswietl_wynik()
{
    if (czy_p = 0)
    {
        printf("Brak pierwiastkow dla rownania %.2fx^2 %.2fx %.2f", a, b, c);
    }
    if (czy_p = 1)
    {
        printf("Jeden pierwiastek dla rownania %.2fx^2 %.2fx %.2f\nPierwiastek: %.2f", a, b, c, x1);
    }
    if (czy_p = 2)
    {
        printf("Dwa pierwiastki dla rownania %.2fx^2 %.2fx %.2f\nPierwiastki: %.2f i %.2f", a, b, c, x1, x2);
    }
}
// Zadania sa wykonane w poszczegulnych funkcjach ponumerowanych tak samo jak zadania

void zadanie1();
void zadanie2();
void zadanie4();
void zadanie5();/*
void zadanie6();
void zadanie7();
void zadanie8();
void zadanie9();*/


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
        }/*
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
        std::cout << "Wybor zadan" << std::endl << "0 : wyjscie" << std::endl << "1-10 : Zadania" << std::endl;
        std::cin >> zadanie;
        cout << endl;
    }
    return 0;
}

void zadanie1() 
{
    T_data Student;
    Student.Pobierz_date();
    Student.Wypisz_date();
}

void zadanie2()
{
    T_student Student1;
    Student1.Wypisz();
    T_student Student2;
    T_student* wsk = & Student2;
    (* wsk).Wczytaj();
    (* wsk).Wypisz();
}

void zadanie4()
{
    T_pole prost1;
    prost1.Czytaj_dane();
    prost1.Przetworz_dane();
    prost1.Wyswietl_wynik();
}

void zadanie5()
{
    T_delta rownanie;
    rownanie.Czytaj_dane();
    if (rownanie.nie == 0)
    {
        rownanie.Przetworz_dane();
        rownanie.Wyswietl_wynik();
    }
}