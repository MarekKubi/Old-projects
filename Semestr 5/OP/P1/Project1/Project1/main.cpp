/*********************************************
Kod stanowi uzupe³nienie materia³ów do æwiczeñ
w ramach przedmiotu metody optymalizacji.
Kod udostêpniony na licencji CC BY-SA 3.0
Autor: dr in¿. £ukasz Sztangret
Katedra Informatyki Stosowanej i Modelowania
Akademia Górniczo-Hutnicza
Data ostatniej modyfikacji: 19.09.2023
*********************************************/

#include"opt_alg.h"
using namespace std;


void lab0();
void lab1();
void lab2();
void lab3();
void lab4();
void lab5();
void lab6();

int main()
{
	try
	{

		/*
		matrix p(2, 3, 0.0);

		p(0, 0) = 1;
		p(1, 0) = 2;
		cout << "P:\n" << p << endl;
		p[1] = p[0];
		cout << "P1:\n" << p[0] << endl;
		cout << "P:\n" << p << endl;

		matrix p1(3, 2, 0.0);
		
		cout << "P:\n" << p << endl;
		cout << "P1:\n" << p1 << endl;
		cout << "P:\n" << p(0) << endl;
		cout << "P1:\n" << p1(0) << endl;
		cout << "P:\n" << p[0] << endl;
		cout << "P1:\n" << p1[0] << endl;/**/



		srand((unsigned)time(0));
		lab6();
	}
	catch (string EX_INFO)
	{
		cerr << "ERROR:\n";
		cerr << EX_INFO << endl << endl;
	}
	system("pause");
	return 0;
}

void lab0()
{
	//Funkcja testowa
	double epsilon = 1e-2;
	int Nmax = 10000;
	matrix lb(2, 1, -5), ub(2, 1, 5), a(2, 1);
	solution opt;
	a(0) = -1;
	a(1) = 2;
	opt = MC(ff0T, 2, lb, ub, epsilon, Nmax, a);
	std::cout << opt << endl << endl;
	solution::clear_calls();

	//Wahadlo
	Nmax = 1000;
	epsilon = 1e-2;
	lb = 0;
	ub = 5;
	double teta_opt = 1;
	opt = MC(ff0R, 1, lb, ub, epsilon, Nmax, teta_opt);
	std::cout << opt << endl << endl;
	solution::clear_calls();

	//Zapis symulacji do pliku csv
	matrix Y0 = matrix(2, 1), MT = matrix(2, new double[2]{ m2d(opt.x),0.5 });
	matrix* Y = solve_ode(df0, 0, 0.1, 10, Y0, NAN, MT);
	ofstream Sout("symulacja_lab0.csv");
	Sout << hcat(Y[0], Y[1]);
	Sout.close();
	Y[0].~matrix();
	Y[1].~matrix();
}

void lab1()
{//11 cm
	solution Xopt;
	Xopt.x = 0.131545;
	matrix af = Xopt.fit_fun(ff1R);
	//cout << af(0) << endl;
	int wyb = 9;
	if (wyb==0)
	{
		//Funkcja testowa
		double epsilon = 1e-2;
		int Nmax = 10000;
		matrix lb(2, 1, -5), ub(2, 1, 5), a(2, 1);
		solution opt;
		a(0) = -1;
		a(1) = 2;
		//double* w = expansion(ff1T, 0.01, 0.01, 1.2, 100);
		double w[2] = { -100, 100 };
		cout << "expw: " << w[0] << "	" << w[1] << endl;
		opt = fib(ff1R, w[0], w[1], epsilon, Nmax, a);
		cout << opt << endl << endl;
		solution::clear_calls();

		//Wahadlo
		Nmax = 1000;
		epsilon = 1e-2;
		lb = 0;
		ub = 5;
		double teta_opt = 1;
		opt = lag(ff1R, w[0], w[1], epsilon, epsilon, Nmax, 0);
		cout << opt << endl << endl;
		solution::clear_calls();

		//Zapis symulacji do pliku csv
		matrix Y0 = matrix(2, 1), MT = matrix(2, new double[2] { m2d(opt.x), 0.5 });
		matrix* Y = solve_ode(df0, 0, 0.1, 10, Y0, NAN, MT);
		ofstream Sout("symulacja_lab0.csv");
		Sout << hcat(Y[0], Y[1]);
		Sout.close();
		Y[0].~matrix();
		Y[1].~matrix();
	}
	else if(wyb ==2)
	{
		double glob = 62.7;
		double loc = 0;
		double alp = 1.1 + (fmod(rand(), 200) / 1000.0);
		ofstream kol;
		string f ="";
		kol.open("symulacja_lab1.csv");
		bool wh = true;
		bool l = false;
		while (wh)
		{
			kol.close();
			kol.open("symulacja_lab1.csv");
			alp += 0.000001;
			for (int i = 0; i < 100; i++)
			{
				kol.flush();
				double epsilon = 1e-2;
				int Nmax = 10000;
				matrix lb(2, 1, -5), ub(2, 1, 5), a(2, 1);
				solution opt;
				a(0) = -1;
				a(1) = 2;
				double x0 = (fmod(rand(), 20) / 100.0);
				double* w = expansion(ff1R, x0, 1, alp, 10);
				if (w[0] > w[1])
				{
					double a = w[1];
					w[1] = w[0];
					w[0] = a;
				}
				kol << to_string(x0);
				kol << ";";
				kol << to_string(w[0]);
				kol << ";";
				kol << to_string(w[1]);
				kol << ";";
				kol << to_string(opt.f_calls);
				opt.f_calls = 0;
				opt = fib(ff1R, w[0], w[1], epsilon, Nmax, a);
				//cout <<"\t" << w[0] << "\t" << w[1]<<"\t" << opt.f_calls << opt.y;

				//f = f + to_string(x0);
				kol << ";";
				kol << to_string(opt.x(0));
				kol << ";";
				kol << to_string(opt.y(0));
				kol << ";";
				kol << to_string(opt.f_calls);
				kol << ";";
				if ((opt.x(0) - glob) < 1 && (opt.x(0) - glob) > -1 && (opt.x(0)<w[1] && opt.x(0)> w[0]))
				{
					kol << "glob";//to_string(1000);
				}
				else if ((opt.x(0) - loc) < 1 && (opt.x(0) - loc) > -1 && (opt.x(0) < w[1] && opt.x(0) > w[0]))
				{
					kol << "loc";//to_string(2);
					l = true;
				}
				else
				{
					kol << "brak";// to_string(-1);
				}
				opt.f_calls = 0;
				solution::clear_calls();

				//Wahadlo
				Nmax = 1000;
				epsilon = 1e-2;
				lb = 0;
				ub = 5;
				double teta_opt = 1;
				opt = lag(ff1R, w[0], w[1], epsilon, epsilon, Nmax, 0);
				//cout << "\t" << w[0] << "\t" << w[1] << "\t" << opt.f_calls << opt.y << endl;
				kol << ";";
				kol << to_string(opt.x(0));
				kol << ";";
				kol << to_string(opt.y(0));
				kol << ";";
				kol << to_string(opt.f_calls);
				kol << ";";
				if ((opt.x(0) - glob) < 1 && (opt.x(0) - glob) > -1 && (opt.x(0) < w[1] && opt.x(0) > w[0]))
				{
					kol << "glob";//to_string(1000);
					wh = false;
				}
				else if ((opt.x(0) - loc) < 1 && (opt.x(0) - loc) > -1 && (opt.x(0) < w[1] && opt.x(0) > w[0]))
				{
					kol << "loc";//to_string(2);
					if (l)
					{
						cout << "loc" << endl;
					}
				}
				else
				{
					kol << "brak";// to_string(-1);
				}
				wh = false;
				kol << ";";
				opt.f_calls = 0;
				kol << "\n";
				solution::clear_calls();
				kol.flush();
				
				//cout << f;
				//kol << f;
				//Zapis symulacji do pliku csv
				/*
				matrix Y0 = matrix(2, 1), MT = matrix(2, new double[2] { m2d(opt.x), 0.5 });
				matrix* Y = solve_ode(df0, 0, 0.1, 10, Y0, NAN, MT);
				ofstream Sout("symulacja_lab0.csv");
				Sout << hcat(Y[0], Y[1]);
				Sout.close();
				Y[0].~matrix();
				Y[1].~matrix();
				/**/
			}
			kol << ";";
			kol << to_string(alp);
			if (alp > 10.75)
			{
				alp = 1;
			}
		}
	}
}

void lab2()
{
	/*
	//Funkcja testowa
	double epsilon = 1e-4;
	int Nmax = 10000;
	matrix lb(2, 1, -5), ub(2, 1, 5), a(2, 1), s(2,1);
	solution opt;
	a(0) = 0.5;
	a(1) = 0.5;
	s(0) = 1;
	s(1) = 1;
	opt = HJ(ff2T, a, 0.3, 0.5, epsilon, Nmax);
	//opt = MC(ff0T, 2, lb, ub, epsilon, Nmax, a);
	std::cout << opt << endl << endl;
	solution::clear_calls();

	//Wahadlo
	Nmax = 1000;
	epsilon = 1e-2;
	lb = 0;
	ub = 5;
	double teta_opt = 1; 
	opt = Rosen(ff2T, a, s , 2, 0.5,epsilon, Nmax);
	std::cout << opt << endl << endl;
	solution::clear_calls();

	//Zapis symulacji do pliku csv
	matrix Y0 = matrix(2, 1), MT = matrix(2, new double[2] { m2d(opt.x), 0.5 });
	matrix* Y = solve_ode(df0, 0, 0.1, 10, Y0, NAN, MT);
	ofstream Sout("symulacja_lab0.csv");
	Sout << hcat(Y[0], Y[1]);
	Sout.close();
	Y[0].~matrix();
	Y[1].~matrix();
	/**/
	double glob = 0;
	double loc = 0;
	double alp = 1.1 + (fmod(rand(), 200) / 1000.0);
	string f = "";
	ofstream kol;
	kol.open("symulacja_lab1.csv");
	bool wh = true;
	bool l = false;
	double step = 0.03 + (fmod(rand(), 500) / 100000.0) ;;
	double epsilon = 1e-4;
	int Nmax = 10000;
	matrix lb(2, 1, -5), ub(2, 1, 5), a(2, 1), s(2,1);
	s(0) = step;
	s(1) = step;
	solution opt;
	a(0) = (fmod(rand(), 100) / 100.0) - 1;
	a(1) = (fmod(rand(), 100) / 100.0) - 1;
	kol.flush();
	if (l)
	{
		while (wh)
		{
			kol.close();
			kol.open("symulacja_lab1.csv");
			alp += 0.000001;
			for (int i = 0; i < 100; i++)
			{
				//a(0) = -1;
				//a(1) = 2;
				a(0) = (fmod(rand(), 100) / 100.0) - 1;
				a(1) = (fmod(rand(), 100) / 100.0) - 1;
				cout << "a\n" << a << endl;
				opt = HJ(ff2T, a, step, 0.5, epsilon, Nmax);
				kol << to_string(a(0));
				kol << ";";
				kol << to_string(a(1));
				kol << ";";
				kol << to_string(opt.x(0));
				kol << ";";
				kol << to_string(opt.x(1));
				kol << ";";
				kol << to_string(opt.y(0));
				kol << ";";
				kol << to_string(opt.f_calls);
				kol << ";";
				opt.f_calls = 0;

				if ((opt.x(0) - glob) < 0.3 && (opt.x(0) - glob) > -0.3 && (opt.x(1) < 0.3 && opt.x(1) > -0.3))
				{
					kol << "Tak";//to_string(1000);
				}
				else
				{
					kol << "Nie";//to_string(2);
				}
				solution::clear_calls();
				cout << "a" << endl;
				kol << ";";

				//Wahadlo
				opt = Rosen(ff2T, a, s, 2, 0.5, epsilon, Nmax);
				kol << to_string(opt.x(0));
				kol << ";";
				kol << to_string(opt.x(1));
				kol << ";";
				kol << to_string(opt.y(0));
				kol << ";";
				kol << to_string(opt.f_calls);
				kol << ";";
				opt.f_calls = 0;
				cout << "a" << endl;

				if ((opt.x(0) - glob) < 0.3 && (opt.x(0) - glob) > -0.3 && (opt.x(1) < 0.3 && opt.x(1) > -0.3))
				{
					kol << "Tak";//to_string(1000);
				}
				else
				{
					kol << "Nie";//to_string(2);
				}
				wh = false;
				kol << ";";
				opt.f_calls = 0;
				kol << "\n";
				solution::clear_calls();
				//kol.flush();

				//cout << f;
				//kol << f;
				//Zapis symulacji do pliku csv
				/*
				matrix Y0 = matrix(2, 1), MT = matrix(2, new double[2] { m2d(opt.x), 0.5 });
				matrix* Y = solve_ode(df0, 0, 0.1, 10, Y0, NAN, MT);
				ofstream Sout("symulacja_lab0.csv");
				Sout << hcat(Y[0], Y[1]);
				Sout.close();
				Y[0].~matrix();
				Y[1].~matrix();
				/**/
			}
			kol << ";";
			kol << to_string(step);
			if (alp > 10.75)
			{
				alp = 1;
			}
		}
	}
	else
	{
		/**/
		s(0) = 0.1;
		s(1) = 0.1;
		//a(0) = 0.0174209;
		a(0) = 0.174015;
		a(1) = a(0);
		//a(0) = 5;
		//a(1) = 5;
		/**/
		opt.x = a;
		opt.fit_fun(ff2R);
		//cout << s(0) << endl << a << endl;
		//opt = Rosen(ff2R, a, s, 1.5, 1.0/1.5, epsilon, Nmax);
		//cout << "Wyn:	" << opt.x << opt.y << endl << opt.f_calls << endl;
		//opt = HJ(ff2R, a, s(0), 1.0 / 1.5, epsilon, Nmax);
		//cout << "Wyn:	" << opt.x << opt.y << endl << opt.f_calls << endl;
	}
}

void lab3()
{
	double glob = 0;
	double loc = 0;
	double alp = 1.1 + (fmod(rand(), 200) / 1000.0);
	string f = "";
	ofstream kol;
	kol.open("symulacja_lab1.csv");
	bool wh = true;
	bool l = true;
	double step = 0.03 + (fmod(rand(), 500) / 100000.0);;
	double epsilon = 1e-5;
	int Nmax = 10000;
	matrix lb(2, 1, -5), ub(2, 1, 5), a(2, 1), s(2, 1);
	matrix ud1(2, 1, 0.0);
	double zminn_a = 4;
	//double zminn_a = 4.4934;
	//double zminn_a = 5;
	ud1(0) = zminn_a;
	s(0) = step;
	s(1) = step;
	solution opt;
	a(0) = (fmod(rand(), 5000) / 1000.0) + 1;
	a(1) = (fmod(rand(), 5000) / 1000.0) + 1;
	while (norm(a)-zminn_a >0)
	{
		a(0) = (fmod(rand(), 5000) / 1000.0) + 1;
		a(1) = (fmod(rand(), 5000) / 1000.0) + 1;
	}
	kol.flush();
	if (l)
	{
		while (wh)
		{
			kol.close();
			kol.open("symulacja_lab1.csv");
			alp += 0.000001;
			for (int i = 0; i < 100; i++)
			{
				//a(0) = -1;
				//a(1) = 2;
				a(0) = (fmod(rand(), 5000) / 1000.0) + 1;
				a(1) = (fmod(rand(), 5000) / 1000.0) + 1;
				while (norm(a) - zminn_a > 0)
				{
					a(0) = (fmod(rand(), 5000) / 1000.0) + 1;
					a(1) = (fmod(rand(), 5000) / 1000.0) + 1;
				}
				cout << "a\n" << a << endl;
				opt = pen(ff3TW, a ,1.1, 2, epsilon, Nmax, ud1);
				//cout << "a\n" << a << endl;
				kol << to_string(a(0));
				kol << ";";
				kol << to_string(a(1));
				kol << ";";
				kol << to_string(opt.x(0));
				kol << ";";
				kol << to_string(opt.x(1));
				kol << ";";
				kol << to_string(norm(opt.x));
				kol << ";";
				kol << to_string(opt.y(0));
				kol << ";";
				kol << to_string(opt.f_calls);
				kol << ";";
				opt.f_calls = 0;
				/*
				if ((opt.x(0) - glob) < 0.3 && (opt.x(0) - glob) > -0.3 && (opt.x(1) < 0.3 && opt.x(1) > -0.3))
				{
					kol << "Tak";//to_string(1000);
				}
				else
				{
					kol << "Nie";//to_string(2);
				}*/
				solution::clear_calls();
				//cout << "a" << endl;
				//kol << ";";

				//Wahadlo
				opt = pen(ff3TZ, a, 1.1, 0.5, epsilon, Nmax, ud1);
				kol << to_string(opt.x(0));
				kol << ";";
				kol << to_string(opt.x(1));
				kol << ";";
				kol << to_string(norm(opt.x));
				kol << ";";
				kol << to_string(opt.y(0));
				kol << ";";
				kol << to_string(opt.f_calls);
				kol << ";";
				opt.f_calls = 0;
				/*
				if ((opt.x(0) - glob) < 0.3 && (opt.x(0) - glob) > -0.3 && (opt.x(1) < 0.3 && opt.x(1) > -0.3))
				{
					kol << "Tak";//to_string(1000);
				}
				else
				{
					kol << "Nie";//to_string(2);
				}*/
				wh = false;
				kol << ";";
				opt.f_calls = 0;
				kol << "\n";
				solution::clear_calls();
				//kol.flush();

				//cout << f;
				//kol << f;
				//Zapis symulacji do pliku csv
				/*
				matrix Y0 = matrix(2, 1), MT = matrix(2, new double[2] { m2d(opt.x), 0.5 });
				matrix* Y = solve_ode(df0, 0, 0.1, 10, Y0, NAN, MT);
				ofstream Sout("symulacja_lab0.csv");
				Sout << hcat(Y[0], Y[1]);
				Sout.close();
				Y[0].~matrix();
				Y[1].~matrix();
				/**/
			}
			kol << ";";
			kol << to_string(step);
			if (alp > 10.75)
			{
				alp = 1;
			}
		}
	}
	else
	{
		/*
		
		
		a(0) = 1.54134;
		a(1) = 0.0991239;
		*/
		s(0) = 0.1;
		s(1) = 0.1;
		//a(0) = 0.0174209;
		a(0) = (fmod(rand(), 1000) / 1000.0) + 4.5;
		a(1) = a(0);
		a(0) = 1.59675;
		a(1) = -0,246853;
		cout << a << endl;
		//a(0) = 5;
		//a(1) = 5;
		/**/
		opt.x = a;
		opt.fit_fun(ff3R, ud1,ud1);
		//opt = pen(ff3R, a, 1.1, 2, epsilon, Nmax, ud1, ud1);
		//cout << s(0) << endl << a << endl;
		//opt = Rosen(ff2R, a, s, 1.5, 1.0/1.5, epsilon, Nmax);
		cout << "Wyn:\n	" << opt.x << "\nwyn y\n" << opt.y << endl << opt.f_calls << endl;
		//opt = HJ(ff2R, a, s(0), 1.0 / 1.5, epsilon, Nmax);
		//cout << "Wyn:	" << opt.x << opt.y << endl << opt.f_calls << endl;
	}
}

void lab4()
{
	double glob = 0;
	double loc = 0;
	double alp = 1.1 + (fmod(rand(), 200) / 1000.0);
	string f = "";
	ofstream kol;
	kol.open("symulacja_lab1.csv");
	bool wh = true;
	bool l = false;
	double step = 0.03 + (fmod(rand(), 500) / 100000.0);;
	double epsilon = 1e-5;
	int Nmax = 100000;
	matrix lb(2, 1, -5), ub(2, 1, 5), a(2, 1), s(2, 1);
	matrix ud1(3, 100, 1.0);
	matrix ud2(100, 1.0);
	ifstream read, read2;
	string dane;
	read.open("XData.txt");
	int k =0;
	int i = 0;
	int sum = 0;
	int len;
	getline(read, dane);
	//cout << dane;
	getline(read, dane);
	//cout << dane;
	len = dane.length();
	while(true)
	{
		if (k>=len)
		{
			break;
		}
		else if(dane[k] != ';')
		{
			sum = sum * 10;
			sum += dane[k] - 48;
			//cout << "k dod " << k << " w " << dane[k] << " s " << sum << endl;
			//cout << "k dod " << k << " w " << dane[k] << endl;
			k++;
		}
		else
		{
			ud1(1, i) = sum;
			//cout << "k skip " << k << " w " << dane[k] << " s " << sum << endl;
			sum = 0;
			i++;
			k = k + 2;
		}
	}
	getline(read, dane);
	len = dane.length();
	k = 0;
	sum = 0;
	i = 0;
	while (true)
	{
		if (k >= len)
		{
			break;
		}
		else if (dane[k] != ';')
		{
			sum = sum * 10;
			sum += dane[k] - 48;
			k++;
		}
		else
		{
			ud1(2, i) = sum;
			sum = 0;
			i++;
			k = k + 2;
		}
	}
	read2.open("YData.txt");
	getline(read2, dane);
	len = dane.length();
	k = 0;
	sum = 0;
	i = 0;
	while (true)
	{
		if (k >= len)
		{
			break;
		}
		else if (dane[k] != ';')
		{
			sum = sum * 10;
			sum += dane[k] - 48;
			k++;
		}
		else
		{
			ud2(i) = sum;
			sum = 0;
			i++;
			k = k + 2;
		}
	}
	//cout << ud1 << endl << endl;
	//cout << ud2;
	double zminn_a = 4;
	//double zminn_a = 4.4934;
	//double zminn_a = 5;
	ud1(0) = zminn_a;
	s(0) = step;
	s(1) = step;
	double h = -1;
	solution opt;
	a(0) = (fmod(rand(), 5000) / 1000.0) + 1;
	a(1) = (fmod(rand(), 5000) / 1000.0) + 1;
	while (norm(a) - zminn_a > 0)
	{
		a(0) = (fmod(rand(), 5000) / 1000.0) + 1;
		a(1) = (fmod(rand(), 5000) / 1000.0) + 1;
	}
	kol.flush();
	if (l)
	{
		while (wh)
		{
			kol.close();
			kol.open("symulacja_lab1.csv");
			alp += 0.000001;
			for (int i = 0; i < 100; i++)
			{
				//a(0) = -1;
				//a(1) = 2;
				a(0) = (fmod(rand(), 20000) / 1000.0) - 10.0;
				a(1) = (fmod(rand(), 20000) / 1000.0) - 10.0;
//SD(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
				
				opt = SD(ff4T, Gf4spa, a, h, epsilon, Nmax, ud1);
				opt.fit_fun(ff4T);
				//cout << "a\n" << a << endl;
				kol << to_string(a(0));
				kol << ";";
				kol << to_string(a(1));
				kol << ";";
				kol << to_string(opt.x(0));
				kol << ";";
				kol << to_string(opt.x(1));
				kol << ";";
				kol << to_string(opt.y(0));
				kol << ";";
				kol << to_string(opt.f_calls);
				kol << ";";
				kol << to_string(opt.g_calls);
				kol << ";";
				opt.fit_fun(reset);
				opt.f_calls = 0;
				opt.g_calls = 0;
				/*
				if ((opt.x(0) - glob) < 0.3 && (opt.x(0) - glob) > -0.3 && (opt.x(1) < 0.3 && opt.x(1) > -0.3))
				{
					kol << "Tak";//to_string(1000);
				}
				else
				{
					kol << "Nie";//to_string(2);
				}*/
				solution::clear_calls();
				//cout << "a" << endl;
				//kol << ";";

				//Wahadlo
				//cout << "a\n" << a << endl;
				opt = CG(ff4T, Gf4spr, a, h, epsilon, Nmax, ud1);
				opt.fit_fun(ff4T);
				//cout << "aaaaaaaaaa\n" << endl;
				//opt.fit_fun(ff4T);
				//cout << "aaaaaaaaaa\n" << endl;
				//cout << "a\n" << a << endl;
				kol << to_string(opt.x(0));
				kol << ";";
				kol << to_string(opt.x(1));
				kol << ";";
				kol << to_string(opt.y(0));
				kol << ";";
				kol << to_string(opt.f_calls);
				kol << ";";
				kol << to_string(opt.g_calls);
				kol << ";";
				opt.fit_fun(reset);
				opt.f_calls = 0;
				opt.g_calls = 0;
				/*
				if ((opt.x(0) - glob) < 0.3 && (opt.x(0) - glob) > -0.3 && (opt.x(1) < 0.3 && opt.x(1) > -0.3))
				{
					kol << "Tak";//to_string(1000);
				}
				else
				{
					kol << "Nie";//to_string(2);
				}*/


				opt = Newton(ff4T, Gf4N, Hf4T, a, h, epsilon, Nmax, ud1);
				opt.fit_fun(ff4T);
				//cout << "a\n" << a << endl;
				kol << to_string(opt.x(0));
				kol << ";";
				kol << to_string(opt.x(1));
				kol << ";";
				kol << to_string(opt.y(0));
				kol << ";";
				kol << to_string(opt.f_calls);
				kol << ";";
				kol << to_string(opt.g_calls);
				kol << ";";
				kol << to_string(opt.H_calls);
				kol << ";";
				opt.fit_fun(reset);
				opt.f_calls = 0;
				opt.g_calls = 0;



				wh = false;
				kol << ";";
				opt.f_calls = 0;
				kol << "\n";
				solution::clear_calls();
				//kol.flush();

				//cout << f;
				//kol << f;
				//Zapis symulacji do pliku csv
				/*
				matrix Y0 = matrix(2, 1), MT = matrix(2, new double[2] { m2d(opt.x), 0.5 });
				matrix* Y = solve_ode(df0, 0, 0.1, 10, Y0, NAN, MT);
				ofstream Sout("symulacja_lab0.csv");
				Sout << hcat(Y[0], Y[1]);
				Sout.close();
				Y[0].~matrix();
				Y[1].~matrix();
				/**/
			}
			kol << ";";
			kol << to_string(step);
			if (alp > 10.75)
			{
				alp = 1;
			}
		}
	}
	else
	{
		/*


		a(0) = 1.54134;
		a(1) = 0.0991239;
		*/
		s(0) = 0.1;
		s(1) = 0.1;
		//a(0) = 0.0174209;
		a(0) = (fmod(rand(), 1000) / 1000.0) + 4.5;
		a(1) = a(0);
		a(0) = 2+0.15;
		a(1) = 1.5+0.25;
		/*
		a(0) = 0,4312;
		a(1) = 3,93124;
		a(0) = -0,81234;
		a(1) = 5,48765;
		a(0) = 9;
		a(1) = -5;
		
		*/
		//cout << a << endl;
		//a(0) = 5;
		//a(1) = 5;
		/**/
		matrix b(3, 1, 0.0);
		opt.x = b;

		//for (int i = 0; i < 100; i++)
		//{
		//	//cout << "i = " << i << endl << ud1[i] << endl;
		//}
		//cout << ud1[0] << endl;
		//cout << ud2[0] << endl;
		opt.y = ff4RJ(b,ud1,ud2);
		//cout << "AAAA" << endl;
		//opt = pen(ff3R, a, 1.1, 2, epsilon, Nmax, ud1, ud1);
		//cout << s(0) << endl << a << endl;
		//opt = Rosen(ff2R, a, s, 1.5, 1.0/1.5, epsilon, Nmax);
		//cout << "Wyn:\n	" << opt.x << "\nwyn y\n" << opt.y << endl << opt.f_calls << endl;
		opt.y = ff4Rgrad(b, ud1, ud2);
		//cout << opt.y << endl;
		//opt = HJ(ff2R, a, s(0), 1.0 / 1.5, epsilon, Nmax);
		cout << "Wyn:	" << opt.x << opt.y << endl << opt.f_calls << endl;
		h = 0.0001;
		/*
		
		opt = CG(ff4RJ, Gf4spa, b, h, epsilon, Nmax, ud1,ud2);
		//cout << "a\n" << a << endl;
		kol << to_string(opt.x(0));
		kol << ";";
		kol << to_string(opt.x(1));
		kol << ";";
		kol << to_string(opt.x(2));
		kol << ";";
		opt.y = ff4RJ(opt.x, ud1, ud2)(0);
		kol << to_string(opt.y(0));
		kol << ";";
		sum = 0;
		for (int i = 0; i < 100; i++)
		{
			double tmp = ff4Rh0( ud1[i],opt.x, ud2)(0);
			cout << "tmp" << tmp << endl << "ud\n" << ud1[i] << endl;
			if (tmp>=0.5 && tmp < 1.5)
			{
				sum++;
			}
		}
		kol << (sum/100.0);
		kol << ";";
		kol << to_string(opt.g_calls);
		kol << ";";
		opt.fit_fun(reset);
		opt.f_calls = 0;
		opt.g_calls = 0;
		/**//*
		opt.y = ff4RJ(b, ud1, ud2);
		cout << "Wyn:	" << opt.y  << endl;
		opt.y = ff4Rgrad(b, ud1, ud2);
		cout << "Wyn:	" <<opt.y << endl;/**////*
		for (int i = 200; i < 1000; i++)
		{
			kol<< to_string(double(i)/10.0);
			kol << ";";
			kol << to_string(-1.0* (double(i)/10.0 * 0.034235 + 3.724485) / 0.048827);
			kol << "\n";
		}/**/

	}
}


void lab5()
{

}

void lab6()
{

	ofstream kol;
	kol.open("symulacja_lab1.csv");
	double sigma_tab[] = { 0.01, 0.1, 1, 10, 100 };
	int N = 2;

	matrix lb(N, 1);
	lb(0) = -5;
	lb(1) = -5;

	matrix ub(N, 1);
	ub(0) = 5;
	ub(1) = 5;

	int mi = 20;
	int lambda = 40;
	double epsilon = 1e-5;
	int Nmax = 10000;

	//
	// Test
	//
	bool a = false;
if(a)
{
	string msg;
	for (auto sigma : sigma_tab)
	{
		for (int i = 0; i < 100; i++)
		{
			cout << "i:	" << i  << endl;
			solution result = EA(ff6T, N, lb, ub, mi, lambda, sigma, epsilon, Nmax);

			msg = solution::f_calls > Nmax ? "nie" : "tak";

			kol << ("Test-" + to_string(sigma) + ".txt") <<  ";" << result.x(0) << ";" << result.x(1) << ";" << result.y(0) << ";" << solution::f_calls << ";" << msg << "\n";

			solution::clear_calls();
		}
	}
}//#endif
else
{
	//
	// Real
	//
	lb = matrix(2, 1, 0.1);
	ub = matrix(2, 1, 3);
	matrix ud1(1001, 2, 1.0);
	ifstream read, read2;
	string linia;
	read.open("polozenia.txt");
	int k = 0;
	int i = 0;
	int sum = 0;
	int len;
	double neg = 1;
	double mult = 0;
	int b = 0;
	double liczba = 0;
	//getline(read, dane);
	//cout << dane;
	for (int k = 0; k < 1001; k++)
	{
		cout << "i:	" << k << endl;
		i = 0;
		getline(read, linia);
		//cout << dane;
		len = linia.length();
		int l = linia.length();
		mult = 0;
		b = 0;
		//cout << "l   " << l << endl;
		for (b = 0; b < 2;)
		{
			//cout << "i:	" << b << endl;
			// cout << "A:  " << (linia[i] - 48.0) << endl;
			 //cout << "liczba: " << liczba << endl;
			while (linia[i] < '0' || linia[i]>'9')
			{
				i++;
				//cout << "A:  " << (linia[i] - 48.0) << endl;
				if (linia[i] == '-')
				{
					neg = -1;
				}
			}
			for (; i < l; i++)
			{
				if (linia[i] < '0' || linia[i]>'9')
				{
					if (linia[i] == ',')
					{
						i++;
						mult = 10;
					}
					else
					{
						break;
					}
				}
				if (linia[i] < '0' || linia[i]>'9')
				{
					break;
				}
				if (mult == 0)
				{
					//cout << "A:  " << linia[i] << endl;
					//cout << "A:  " << (linia[i] - 48.0)  << endl;
					liczba = liczba * 10.0 + (double)(linia[i] - 48.0) * neg;
					//cout << "liczba: " << liczba << endl;
				}
				else
				{
					//cout << "A:  " << linia[i] << endl;
					//cout << "A:  " << linia[i] << endl;
					liczba = liczba + (double)(linia[i] - 48.0) * neg / mult;
					//cout << "   " << liczba << endl;
					//cout << "liczba: " << liczba << endl;
					mult *= 10;
				}
			}
			//cout << "laaaaaaaaaaaaaaaa: " << liczba << endl;
			neg = 1;
			ud1(k, b) = liczba;
			liczba = 0;
			mult = 0;
			b++;
		}
	}
	/*
	auto dataPtr = FileReaderFactory().CreateFileReader(FileTypeEnum::Lab6)->Read(
		vector<filesystem::path>{"../Input/Project 6/polozenia.txt"});
	Lab6_DataType* data = dynamic_cast<Lab6_DataType*>(dataPtr.get());
	/**/
	//matrix ud2(100, 1.0);
	cout << ud1 << endl << endl << endl;
	solution result = EA(fR6, N, lb, ub, mi, lambda, matrix(2, 1, 1), 1e-2, Nmax, 1001, ud1);

	kol << result.x(0) << ";" << result.x(1) << ";" << result.y(0) << ";" << solution::f_calls << "\n";

	kol << "\n";
	solution::clear_calls();

	//
	// Simulation
	//

	matrix y;
	matrix Y0(4, 1);
	matrix* Y = solve_ode(df6, 0, 0.1, 100, Y0, NAN, result.x[0]);
	cout << Y[1];
	kol << Y[1];
}
}
