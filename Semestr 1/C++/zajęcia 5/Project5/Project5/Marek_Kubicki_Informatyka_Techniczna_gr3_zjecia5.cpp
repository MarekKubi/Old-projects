#include <iostream>

void zadanie1();
void zadanie2();
bool negacja(bool p);
bool implikacja(bool p, bool q);
bool rownowaznosc(bool p, bool q);
bool koniunkcja(bool p, bool q);
bool alternatywa(bool p, bool q);

int main()
{
    int zadanie;

    std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "Zadanie 1 - Zdania logiczne - kalkulator" << std::endl << "Zadanie 2 - Zdania logiczne - ustalone dzialania" << std::endl;
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
        }
        std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "Zadanie 1 - Zdania logiczne - kalkulator" << std::endl << "Zadanie 2 - Zdania logiczne - ustalone dzialania" << std::endl;
        std::cin >> zadanie;
    }
    return 0;
}

void zadanie1()
{
    bool p, q;
    std::cout << "Podaj dwie wartosci logiczne p i q ( 0 lub 1 )" << std::endl;
    std::cin >> p >> q;

    std::cout << "Negacja dla p: " << negacja(p) << std::endl;
    std::cout << "Negacja dla q: " << negacja(q) << std::endl;
    std::cout << "Koniunkcja p i q: " << koniunkcja(p, q) << std::endl;
    /*
    if (p == q && p == 1)
    {
        std::cout << 1 << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
    */
    std::cout << "Alternatywa p lub q: " << alternatywa(p, q) << std::endl;
    /*
    if (p == 1 || q == 1)
    {
        std::cout << 1 << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
    */
    std::cout << "Implikacja p --> q: " << implikacja(p, q) << std::endl;
    /*
    if (p == q)
    {
        std::cout << 1 << std::endl;
    }
    else
    {
        std::cout << q << std::endl;
    }
    */
    std::cout << "Rownowaznosc p <=> q: " << rownowaznosc(p, q) << std::endl;
    /*
    if (p == q)
    {
        std::cout << 1 << std::endl;
    }
    else
    {
        std::cout << 0 << std::endl;
    }
    */
}
void zadanie2()
{
    bool p, q, r;
    std::cout << "p = 5 jest liczba pierwsza; tak => p=1"<< std::endl;
    std::cout << "q = 8 nie jest liczba nieparzysta  tak; => q=1" << std::endl;
    std::cout << "r = jesli odejmiemy 5 od 8, to nie otrzymamy 3  nie; => r=0" << std::endl;
    //std::cin >> p >> q >> r;
    p = 1;
    q = 1;
    r = 0;
    std::cout << "p i q: " << koniunkcja(p, q) << std::endl;
    std::cout << "p lub q: " << alternatywa(p, q) << std::endl;
    std::cout << "-p i (p lub q): " << koniunkcja(!p, alternatywa(p, q)) << std::endl;
    std::cout << "(p i r) -> q: " << implikacja(koniunkcja(p, r), q) << std::endl;
    std::cout << "-(p<->(q lub r)): " << !rownowaznosc(p, alternatywa(q, r)) << std::endl;
    std::cout << "[(p->r) lub -q] <-> [p->(r i q)]: " << rownowaznosc(alternatywa(implikacja(p, r), !q), implikacja(p, koniunkcja(r, q))) << std::endl;
    std::cout << "[(-r lub q) lub -(q i r)] ->[-(q->p)]: " << implikacja(alternatywa(alternatywa(!r, q), !koniunkcja(q, r)), !implikacja(q, p)) << std::endl;

}

bool negacja(bool p)
{
    return !p;
}
bool koniunkcja(bool p, bool q)
{
    if (p == q && p == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool alternatywa(bool p, bool q)
{
    if (p == 1 || q == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
bool implikacja(bool p, bool q)
{
    if (p == q)
    {
        return 1;
    }
    else
    {
        return q;
    }
    
}
bool rownowaznosc(bool p, bool q)
{
    if (p == q)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// ZADANIA 6 18 30
