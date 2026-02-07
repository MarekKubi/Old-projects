#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>

void zadanie1();
void zapis_Rot();
void odczyt_Rot();
void zadanie2();
void zapis_VIG();
void odczyt_VIG();

using namespace std;

int main()
{
    int zadanie;

    std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "1- szyfr ROT-n" << std::endl << "2 - szyfr Vigenera" << std::endl;
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
        std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "1- szyfr ROT-n" << std::endl << "2 - szyfr Vigenera" << std::endl;
        std::cin >> zadanie;
    }
    return 0;
}

void zadanie1()
{
    int zadanie = -1;
    while (zadanie != 0)
    {
        std::cout << "Wybor operacji" << std::endl << "0-wyjscie" << std::endl << "1- zapis " << std::endl << "2 - odczyt" << std::endl;
        std::cin >> zadanie;
        if (zadanie == 1)
        {
            zapis_Rot();
        }
        else if (zadanie == 2)
        {
            odczyt_Rot();
        }
    }
}
void zapis_Rot()
{
    std::fstream zapis;
    zapis.open("ROT.txt", std::ios::out);
    int n;
    cout << "Podaj nr przestawienia: ";
    cin >> n;
    n = (n % 26);
    cout << "Podaj wyraz do zaszyfrowania: ";
    string slowo_2;
    string slowo_1;
    char* slowo;
    cin >> slowo_1;
    getline(cin, slowo_2);      ////// Nie umia³em wczytac calego wyrazu razem ze spacjami wiec wymyslilem taki rozwiazanie
    int j_1 = slowo_1.length();
    int j_2 = slowo_2.length();
    slowo = new char[j_1 + j_2];
    for (int a = 0; a < j_1; a++)
    {
        slowo[a] = slowo_1[a];
    }
    for (int a = 0; a < j_2; a++)
    {
        slowo[j_1 + a] = slowo_2[a];
    }
    int j = j_1 + j_2;
    for (int i = 0; i < j; i++)
    {
        if (slowo[i] == ' ')
        {
            slowo[i] = '_';
        }
        else if ((slowo[i] > 64) && (slowo[i] < 91))
        {
            if (slowo[i] + n < 91)
            {
                slowo[i] = (slowo[i] + n);
            }
            else
            {
                slowo[i] = n - (90 - slowo[i]) + 64;
            }
        }
        else if ((slowo[i] > 96) && (slowo[i] < 123))
        {
            if (slowo[i] + n < 123)
            {
                slowo[i] = (slowo[i] + n);
            }
            else
            {
                slowo[i] = n - (122 - slowo[i]) + 96;
            }
        }
    }

    cout << endl;
    for (int i = 0; i < j; i++)
    {
        zapis << slowo[i];
    }
    zapis.close();
}
void odczyt_Rot()
{
    std::fstream odczyt;
    odczyt.open("ROT.txt", std::ios::in);
    std::string slowo;
    odczyt >> slowo;
    odczyt.close();

    int n;
    cout << "Podaj nr przestawienia: ";
    cin >> n;

    int j = slowo.length();

    for (int i = 0; i < j; i++)
    {
        if (slowo[i] == '_')
        {
            slowo[i] = ' ';
        }
        else if ((slowo[i] > 64) && (slowo[i] < 91))
        {
            if (slowo[i] - n > 65)
            {
                slowo[i] = (slowo[i] - n);
            }
            else
            {
                slowo[i] = (slowo[i]-65) + 91 -n;
            }
        }
        else if ((slowo[i] > 96) && (slowo[i] < 123))
        {
            if (slowo[i] - n > 96)
            {
                slowo[i] = (slowo[i] - n);
            }
            else
            {
                slowo[i] = (slowo[i] - 97) + 123 - n;
            }
        }
    }
    for (int i = 0; i < j; i++)
    {
        cout << slowo[i];
    }
    cout << endl;
}

void zadanie2()
{
    int zadanie = -1;
    while (zadanie != 0)
    {
        std::cout << "Wybor operacji" << std::endl << "0-wyjscie" << std::endl << "1- zapis " << std::endl << "2 - odczyt" << std::endl;
        std::cin >> zadanie;
        if (zadanie == 1)
        {
            zapis_VIG();
        }
        else if (zadanie == 2)
        {
            odczyt_VIG();
        }
    }
}
void zapis_VIG()
{
    std::fstream zapis;
    zapis.open("VIG.txt", std::ios::out);
    cout << "Podaj slowo klucz: ";
    int n=0;
    string vig_2;
    string vig_1;
    char* vig;
    cin >> vig_1;
    getline(cin, vig_2); 
    int v_1 = vig_1.length();
    int v_2 = vig_2.length();
    int v = v_1 + v_2;
    vig = new char[v_1 + v_2];
    for (int a = 0; a < v_1; a++)
    {
        vig[a] = vig_1[a];
    }
    int a;
    for (a = 0; a < v_2; a++)
    {
        vig[v_1 + a] = vig_2[a];
    }
    int b = 0;
    int r = 0;
    for (a = 0; a < v; a++)
    {
        while (vig[a] == ' ' && a < v)
        {
            a++;
            r++;
        }
        vig[b] = vig[a];
        b++;
    }
    v = v - r;

    cout << "Podaj wyraz do zaszyfrowania: ";
    string slowo_2;
    string slowo_1;
    char* slowo;
    cin >> slowo_1;
    getline(cin, slowo_2);  
    int j_1 = slowo_1.length();
    int j_2 = slowo_2.length();
    slowo = new char[j_1 + j_2];
    for (int a = 0; a < j_1; a++)
    {
        slowo[a] = slowo_1[a];
    }
    for (int a = 0; a < j_2; a++)
    {
        slowo[j_1 + a] = slowo_2[a];
    }
    int j = j_1 + j_2;
    for (int i = 0; i < j; i++)
    {
        if (slowo[i] == ' ')
        {
            slowo[i] = '_';
        }
        else
        {
            if ((vig[i % v] > 64) && (vig[i % v] < 91))
            {
                n = vig[i % v] - 65;
            }
            else if ((vig[i % v] > 96) && (vig[i % v] < 123))
            {
                n = vig[i % v] - 97;
            }
            if ((slowo[i] > 64) && (slowo[i] < 91))
            {
                if (slowo[i] + n < 91)
                {
                    slowo[i] = (slowo[i] + n);
                }
                else
                {
                    slowo[i] = n - (90 - slowo[i]) + 64;
                }
            }
            else if ((slowo[i] > 96) && (slowo[i] < 123))
            {
                if (slowo[i] + n < 123)
                {
                    slowo[i] = (slowo[i] + n);
                }
                else
                {
                    slowo[i] = n - (122 - slowo[i]) + 96;
                }
            }
        }
    }

    cout << endl;
    for (int i = 0; i < j; i++)
    {
        zapis << slowo[i];
    }
    zapis.close();
}
void odczyt_VIG()
{
    std::fstream odczyt;
    odczyt.open("VIG.txt", std::ios::in);
    std::string slowo;
    odczyt >> slowo;
    odczyt.close();

    int n = 0;
    cout << "Podaj slowo klucz: ";
    string vig_2;
    string vig_1;
    char* vig;
    cin >> vig_1;
    getline(cin, vig_2);
    int v_1 = vig_1.length();
    int v_2 = vig_2.length();
    int v = v_1 + v_2;
    vig = new char[v_1 + v_2];
    for (int a = 0; a < v_1; a++)
    {
        vig[a] = vig_1[a];
    }
    int a;
    for (a = 0; a < v_2; a++)
    {
        vig[v_1 + a] = vig_2[a];
    }
    int b = 0;
    int r = 0;
    for (a = 0; a < v; a++)
    {
        while (vig[a] == ' ' && a < v)
        {
            a++;
            r++;
        }
        vig[b] = vig[a];
        b++;
    }
    v = v - r;

    int j = slowo.length();

    for (int i = 0; i < j; i++)
    {
        if (slowo[i] == '_')
        {
            slowo[i] = ' ';
        }
        else
        {
            if ((vig[i % v] > 64) && (vig[i % v] < 91))
            {
                n = vig[i % v] - 65;
            }
            else if ((vig[i % v] > 96) && (vig[i % v] < 123))
            {
                n = vig[i % v] - 97;
            }
            if ((slowo[i] > 64) && (slowo[i] < 91))
            {
                if (slowo[i] - n > 65)
                {
                    slowo[i] = (slowo[i] - n);
                }
                else
                {
                    slowo[i] = (slowo[i] - 65) + 91 - n;
                }
            }
            else if ((slowo[i] > 96) && (slowo[i] < 123))
            {
                if (slowo[i] - n > 96)
                {
                    slowo[i] = (slowo[i] - n);
                }
                else
                {
                    slowo[i] = (slowo[i] - 97) + 123 - n;
                }
            }
        }
    }
    for (int i = 0; i < j; i++)
    {
        cout << slowo[i];
    }
    cout << endl;
}