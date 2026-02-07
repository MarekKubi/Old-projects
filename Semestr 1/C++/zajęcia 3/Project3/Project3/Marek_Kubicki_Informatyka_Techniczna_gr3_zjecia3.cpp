
#include <iostream>



void Zadanie1();
void nogi(int kurczaki, int krowy, int swinie);

void Zadanie2();
void zeszleZadanie1();
void zeszleZadanie2();
void zeszleZadanie3();
void zeszleZadanie4();

void Zadanie3();

void Zadanie4();

int rup(int y, int ruch);
int rright(int x, int ruch);
int rdown(int y, int ruch);
int rleft(int x, int ruch);
int knp(int gracz, int komputer, int tab[3][3]);


/*
void nogi(int kurczaki, int krowy, int swinie)
{
    int suma = kurczaki * 2 + krowy * 4 + swinie * 4;
    std::cout << "Liczba nog to: " << suma;
}

void Zadanie1()
{


    int kury;
    int krowy;
    int swinie;

    std::cout << "Podaj liczbe kur" << std::endl;
    std::cin >> kury;

    std::cout << "Podaj liczbe krow" << std::endl;
    std::cin >> krowy;

    std::cout << "Podaj liczbe swin" << std::endl;
    std::cin >> swinie;

    nogi(kury, krowy, swinie);
}

void zeszleZadanie1()
{

}

void zeszleZadanie2()
{

}

void zeszleZadanie3()
{

}

void zeszleZadanie4()
{

}

void Zadanie2()
{
    int nr;

    std::cout << "Wybor zadan" << std::endl;
    std::cin >> nr;

    switch (nr)
    {
    case 1:
    {
        zeszleZadanie1();
    }
    case 2:
    {
        zeszleZadanie2();
    }
    case 3:
    {
        zeszleZadanie3();
    }
    case 4:
    {
        zeszleZadanie4();
    }
    }
}


void Zadanie3()  // SA TYLKO 4 RUCHY; NIE ZROBIONE NA FUNKCJACH!!!
{
    int y = 0;
    int x = 0;
    int i = 0;
    int ruch;
    std::cout << "Podaj wielkoœæ ruchu" << std::endl;
    std::cin >> ruch;
    if (i == 0)
    {
        y += ruch;
        i++;
    }
    else if (i == 1)
    {
        x += ruch;
        i++;
    }
    else if (i == 2)
    {
        y -= ruch;
        i++;
    }
    else
    {
        x -= ruch;
        i = 0;
    }
}

void Zadanie4()
{

}
*/

int main()
{
    int zadanie;

    std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "Zadanie 1 - Farmer i nogi" << std::endl << "Zadanie 2 - Wybor innych zadan (1 lekcja)" << std::endl
        << "Zadanie 3 - Robocik porusza siê po 2D siatce" << std::endl << "Zadanie 4 - kamien, papier, nozyczki" << std::endl;
    std::cin >> zadanie;

    while (zadanie != 0)
    {
        switch (zadanie)
        {
            case 1:
            {
                Zadanie1();
                std::cout << std::endl << std::endl;
                break;
            }
            case 2:
            {
                Zadanie2();
                std::cout << std::endl << std::endl;
                break;
            }
            case 3:
            {
                Zadanie3();
                std::cout << std::endl << std::endl;
                break;
            }
            case 4:
            {
                Zadanie4();
                std::cout << std::endl << std::endl;
                break;
            }
        }
        std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "Zadanie 1 - Farmer i nogi" << std::endl << "Zadanie 2 - Wybor innych zadan (1 lekcja)" << std::endl
            << "Zadanie 3 - Robocik porusza siê po 2D siatce" << std::endl << "Zadanie 4 - kamien, papier, nozyczki" << std::endl;
        std::cin >> zadanie;
    }
    return 0;
}

void Zadanie1()
{


    int kury;
    int krowy;
    int swinie;

    std::cout << "Podaj liczbe kur" << std::endl;
    std::cin >> kury;

    std::cout << "Podaj liczbe krow" << std::endl;
    std::cin >> krowy;

    std::cout << "Podaj liczbe swin" << std::endl;
    std::cin >> swinie;

    nogi(kury, krowy, swinie);
}

void nogi(int kurczaki, int krowy, int swinie)
{
    int suma = kurczaki * 2 + krowy * 4 + swinie * 4;
    std::cout << "Liczba nog to: " << suma;
}

void zeszleZadanie1()
{
    std::cout << std::endl << "Zadanie nr.1" << std::endl;

    int z1zmienna;

    std::cout << "Podaj rok" << std::endl;
    std::cin >> z1zmienna;

    if (z1zmienna % 4 == 0 && z1zmienna % 100 != 0 || z1zmienna % 400 == 0)
    {
        std::cout << "Ten rok jest przestepny" << std::endl;
    }

    else
    {
        std::cout << "Ten rok nie jest przestepny" << std::endl;
    }
}

void zeszleZadanie2()
{

    std::cout << std::endl << "Zadanie nr.2" << std::endl;

    int z2licz1, z2licz2;

    std::cout << "Podaj 2 liczby calkowite ktorych ruznica jest wieksza od 1" << std::endl;
    std::cin >> z2licz1 >> z2licz2;
    std::cout << std::endl;

    if (z2licz1 > z2licz2)
    {
        int x = z2licz1;
        z2licz1 = z2licz2;
        z2licz2 = x;
    }

    if (z2licz2 - z2licz1 > 1)
    {
        int z2i = 0;
        int z2suma = 0;
        if (z2licz1 % 2 != 0)
        {
            z2i++; //Czy nastepna liczba jest nieparzysta
        }
        z2licz1++;

        while (z2licz1 < z2licz2)
        {
            if (z2i == 1)
            {
                z2suma = z2suma + z2licz1;
                z2i--;
            }
            else
            {
                z2i++;
            }

            std::cout << z2licz1 << std::endl;
            z2licz1++;
        }


        std::cout << "Suma liczb parzsytych z podanego przedzialu to:   " << z2suma << std::endl;

    }
    else
    {
        std::cout << "Przedzial wyznaczony przez podane liczby nie zawiera zadnych liczb" << std::endl;
    }
}

void zeszleZadanie3()
{
    std::cout << std::endl << "Zadanie nr.3" << std::endl;

    int z3Liczba;
    int z3i = 0;


    std::cout << "Podaj 5 liczb calkowitych" << std::endl;

    std::cin >> z3Liczba;

    int z3max = z3Liczba;
    int z3min = z3Liczba;

    while (z3i < 4)
    {
        std::cin >> z3Liczba;
        if (z3Liczba > z3max)
        {
            z3max = z3Liczba;
        }
        else
        {
            if (z3Liczba < z3min)
            {
                z3min = z3Liczba;
            }
        }
        z3i++;
    }

    z3Liczba = z3max - z3min;
    std::cout << "Najwieksza z podanych liczb to:  " << z3max << std::endl << "Najmniejsza to:  " << z3min << std::endl << "Ich ruznica to:  " << z3Liczba << std::endl << std::endl;

}

void zeszleZadanie4()
{
    std::cout << std::endl << "Zadanie nr.4" << std::endl;
    std::cout << "Podaj (dodatnia) ilosc liczb n " << std::endl;
    int z4n;
    std::cin >> z4n;
    if (z4n > 0)
    {
        std::cout << "Podaj liczby" << std::endl;

        int z4liczba, z4i = 0, z4suma = 0;
        while (z4i < z4n)
        {
            std::cin >> z4liczba;
            z4suma = z4suma + z4liczba;
            z4i++;
        }
        int z4srednia = z4suma / z4n;

        std::cout << "suma: " << z4suma << std::endl;

        if (z4suma % z4n != 0)
        {
            z4srednia++;
            std::cout << "srednia (zaokraglona do gory): " << z4srednia << std::endl << "Zera:" << std::endl;
        }
        else
        {
            std::cout << "srednia: " << z4srednia << std::endl << "Zera:" << std::endl;
        }

        while (z4srednia > 0)
        {
            std::cout << "0";
            z4srednia--;
        }

    }
    else
    {
        std::cout << "Niewlasciwa ilosc liczb";
    }
}

void Zadanie2()
{
    int nr;

    std::cout << "Wybor zadan 1-4. Wyjscie 5" << std::endl;
    std::cin >> nr;
    while (nr != 5)
    {
        switch (nr)
        {
        case 1:
        {
            zeszleZadanie1();
            std::cout << std::endl;
            break;
        }
        case 2:
        {
            zeszleZadanie2();
            std::cout << std::endl;
            break;
        }
        case 3:
        {
            zeszleZadanie3();
            std::cout << std::endl;
            break;
        }
        case 4:
        {
            zeszleZadanie4();
            std::cout << std::endl;
            break;
        }
        }
        std::cout << "Wybor zadan 1-4. Wyjscie 5" << std::endl;
        std::cin >> nr;
    }
}

/*
void Zadanie3()  // SA TYLKO 4 RUCHY; NIE ZROBIONE NA FUNKCJACH!!!
{
    int y = 0;
    int x = 0;
    int i = 0;
    int ruch;
    std::cout << "Podaj wielkoœæ ruchu" << std::endl;
    std::cin >> ruch;
    if (i == 0)
    {
        y += ruch;
        i++;
    }
    else if (i == 1)
    {
        x += ruch;
        i++;
    }
    else if (i == 2)
    {
        y -= ruch;
        i++;
    }
    else
    {
        x -= ruch;
        i = 0;
    }
}
*/

/*
# include <iostream>

int rup(int y, int ruch);
int rright(int x, int ruch);
int rdown(int y, int ruch);
int rleft(int x, int ruch);
void zadanie3();
void zadanie4();
int ktow(int tab[3][3]);



int main()
{
	


	return 0;
}

*/

void Zadanie3()
{
    int ruch;
	int kroki;
	int y = 0;
	int x = 0;
	int i = 0;
	std::cout << "Podaj liczbe krokow" << std::endl;

	std::cin >> kroki;

	while (kroki > 0)
	{
		switch (i)
		{
			case 0:
			{
                std::cout << "Podaj dlugosc ruchu (na pulnoc)" << std::endl;
                std::cin >> ruch;
				y = rup(y, ruch);
				i++;
                std::cout << "Polozenie: (" << x << "," << y << ")" << std::endl;
				break;
			}
			case 1:
			{
                std::cout << "Podaj dlugosc ruchu (na wsod)" << std::endl;
                std::cin >> ruch;
				x = rright(x, ruch);
				i++;
                std::cout << "Polozenie: (" << x << "," << y << ")" << std::endl;
				break;
			}
			case 2:
			{
                std::cout << "Podaj dlugosc ruchu (na poludnie)" << std::endl;
                std::cin >> ruch;
				y = rdown(y, ruch);
				i++;
                std::cout << "Polozenie: (" << x << "," << y << ")" << std::endl;
				break;
			}
			case 3:
			{
                std::cout << "Podaj dlugosc ruchu (na zachod)" << std::endl;
                std::cin >> ruch;
				x = rleft(x, ruch);
			    i = 0;
                std::cout << "Polozenie: (" << x << "," << y << ")" << std::endl;
				break;
			}
		}
		kroki--;
	}
}


int rup (int y, int ruch)
{
	return y += ruch;
}

int rright(int x, int ruch)
{
	return x += ruch;
}

int rdown(int y, int ruch)
{
	return y -= ruch;
}

int rleft(int x, int ruch)
{
	return x -= ruch;
}



void Zadanie4()
{
	int gracz=0;
	int komputer=0;
	//int cel;
	int w;
    int gr;
    int kp;
    std::string slowa[3];
    slowa[0] = "kamien";
    slowa[1] = "papier";
    slowa[2] = "norzyce";
	int tab[3][3] = { {0,1,-1},{-1,0,1},{1,-1,0} };

	//std::cout << "Podaj do ilu punktow toczy sie gra" << std::endl;
	//std::cin >> cel;


	//while (gracz < cel && komputer < cel)
    for (int i=0; i<3; i++)
	{

        std::cout << "1-Kamien" << std::endl << "2-Papier" << std::endl << "3-Ucinajki" << std::endl << "0-kapitulacja" << std::endl;

        std::cin >> gr;


        srand((unsigned)time(0));
        int kp = (rand() % 3);

        std::cout << slowa[gr-1] << "-" << slowa[kp] << std::endl;

		w = knp(gr,kp,tab);

		if (w==1)
		{
			gracz++;
            std::cout << "Zdobywasz punkt!"<< std::endl << "Aktualny wynik:" << std::endl << "gracz: " << gracz << std::endl << "komputer: " << komputer << std::endl;
		}
		else if (w == -1)
		{
			komputer++;
            std::cout << "Komputer zdobywa punkt"<< std::endl << 
            "Aktualny wynik:" << std::endl << 
            "gracz: " << gracz << std::endl << "komputer: " << komputer << std::endl;
		}
        else if (w == 0)
        {
            std::cout << "Nikt nie zdobyw punktu" << std::endl <<
            "Aktualny wynik:" << std::endl <<
            "gracz: " << gracz << std::endl << "komputer: " << komputer << std::endl;
        }
		else if (w == 2)
		{
			break;
        }
	}

	if (w == 2)
	{
		std::cout << "Nast¹pi³a kapitulacja" << std::endl;
	}

	if (gracz > komputer)
	{
		std::cout << "Wygrales" << std::endl;
	}

	else if (komputer > gracz)
	{
		std::cout << "Przegrales" << std::endl;
	}
    else
    {
        std::cout << "Remis" << std::endl;
    }
}

int knp(int gr, int kp, int tab[3][3])
{
    

	if (gr == 0)
	{
		return 2;
	}
	int w = tab[kp][gr - 1];


	return w;
}
