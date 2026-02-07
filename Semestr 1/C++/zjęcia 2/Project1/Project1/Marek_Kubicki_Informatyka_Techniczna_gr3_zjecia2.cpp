#include <iostream>


int main()
{
	
	std::cout << std::endl <<"Zadanie nr.1"<<std::endl;

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

	


	
	std::cout << std::endl <<"Zadanie nr.2"<<std::endl;

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
	
	std::cout << std::endl <<"Zadanie nr.3"<<std::endl;
	
	int z3Liczba;
	int z3i=0;


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

	

	std::cout <<"Zadanie nr.4" <<std::endl;
	std::cout <<"Podaj (dodatnia) ilosc liczb n " << std::endl;
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
			std::cout << "srednia (zaokraglona do gory): " << z4srednia <<  std::endl << "Zera:"<<std::endl;
		}
		else
		{
			std::cout << "srednia: " << z4srednia << std::endl<<"Zera:"<<std::endl;
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

return 0;
}