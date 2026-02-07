#include <fstream>
#include <iostream>
#include <cstdlib>

void zadanie1();
void zadanie1_obliczenia(int do_ilu);
void zadanie2();
void zadanie3();
void zadanie4();


int main()
{
    int zadanie;

    std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "Zadanie 1 - Tabliczka mozenia" << std::endl << "Zadanie 2 - Podaj haslo" << std::endl
        << "Zadanie 3 - Macierz sasiedztwa" << std::endl << "Zadanie 4 - 3 ale z pliku" << std::endl;
    std::cin >> zadanie;

    while (zadanie != 0)
    {
        switch (zadanie)
        {
        case 1:
        {
            zadanie1();
            std::cout << std::endl << std::endl;
            break;
        }
        case 2:
        {
            zadanie2();
            std::cout << std::endl << std::endl;
            break;
        }
        
        case 3:
        {
            zadanie3();
            std::cout << std::endl << std::endl;
            break;
        }
        case 4:
        
        {
            zadanie4();
            std::cout << std::endl << std::endl;
            break;
        }
        }
        std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "Zadanie 1 - Tabliczka mozenia" << std::endl << "Zadanie 2 - Podaj haslo" << std::endl
            << "Zadanie 3 - Macierz sasiedztwa" << std::endl << "Zadanie 4 - 3 ale z pliku" << std::endl;
            std::cin >> zadanie;
    }
    return 0;
}

void zadanie1()
{
    int do_ilu;
    std::cout << "Podaj rozmiar tabliczki mnozenia" << std::endl;
    std::cin >> do_ilu;
    zadanie1_obliczenia(do_ilu);
}

void zadanie1_obliczenia(int do_ilu)
{
    std::fstream zapis;

    zapis.open("zapis.txt", std::ios::out);

    int wiersz = 0;
    for (int i = 0; i < do_ilu +1; i++)
    {
        zapis << i << " ";
        std::cout << i << " ";
    }
    std::cout << std::endl;
    do 
    {
        std::cout << std::endl;
        zapis << "\n";
        wiersz++;
        zapis << wiersz << " ";
        std::cout << wiersz << "   ";
        for (int i = 0; i < do_ilu; i++)
        {
            std::cout << wiersz * (i + 1) << " ";
            zapis << wiersz * (i + 1) << " ";
        }
    } while (wiersz < do_ilu);
    zapis.close();
}


void zadanie2()
{
    std::fstream odczyt;
    odczyt.open("haslo.txt", std::ios::in);
    if (odczyt.good() == false)
    {
        std::cout << "Brak pliku" << std::endl;
        exit(0);
    }
    std::string haslo_plik;
    std::string haslo;
    odczyt >> haslo_plik;
    std::cout << "Podaj haslo(maks 20 znakow)(podpowiedŸ: haslo = 'haslo')" << std::endl;
    std::cin >> haslo;
    if (haslo == haslo_plik)
    {
        std::cout << "Haslo prawidlowe" << std::endl;
    }
    else
    {
        /*
        std::cout << "Autodestrukcja za: ";
        for (int i = 3; i > 0; i--)
        {
            std::this_thread::sleep_for(1000);
            std::cout << i << "  ";
        }
        std::cout << std::endl << "Jednak nie, ale chaslo nadal nie rowna sie "<< haslo << std::endl;
        */
        std::cout << "Chaslo nie rowna sie '" << haslo << "'" << std::endl;
    }
}


void zadanie3()
{
    int** tab, w;
    std:: cout << "Podaj rozmiar macierzy: ";

    std::cin >> w;

    tab = new int* [w+1];

    for (int i = 0; i < w+1; i++)
    {
        tab[i] = new int[w+1];
    }    
    for (int i = 1; i < w+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            tab[i][j] = 0;
        }
    }
    for (int i = 0; i < w+1; i++)
    {
        tab[i][0] = i; 
    }
    for (int i = 1; i < w+1; i++)
    {
        tab[0][i] = i;
    }
    std::cout << "Podaj ilosc polaczen: ";
    int ilosc_polaczen;
    std::cin >> ilosc_polaczen;


    int od_w;
    int do_w;

    for (int i = 0; i < ilosc_polaczen; i++)
    {
        std::cout << "Podaj poloczenie(od, do)" << std::endl;
        std::cin >> od_w >> do_w;
        tab[od_w][do_w] = 1;
    }
    for (int i = 0; i < w+1; i++)
    {
        for (int j = 0; j < w+1; j++)
        {
            std::cout << tab[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void zadanie4()
{
    std::fstream odczyt;
    odczyt.open("rozmiar.txt", std::ios::in);
    if (odczyt.good() == false)
    {
        std::cout << "Brak pliku" << std::endl;
        exit(0);
    }
    int do_ilu;
    odczyt >> do_ilu;
    zadanie1_obliczenia(do_ilu);
}