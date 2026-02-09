#include"user_funs.h"
#include <cmath>
using namespace std;
# define M_PIl          3.141592653589793238462643383279502884L
# define g				9.81L
int con = 0;
static bool tak = true;
static matrix previ(2, 1, 0.0);
static matrix previg(2, 1, 0.0);


matrix(*gradg)(matrix, matrix, matrix) = ff4Rgrad;
//ofstream kol;

matrix ff0T(matrix x, matrix ud1, matrix ud2)
{
	matrix y;
	y = pow(x(0) - ud1(0), 2) + pow(x(1) - ud1(1), 2) ;
	return y;
}


matrix ff1T(matrix x, matrix ud1, matrix ud2)
{
	matrix y;
	y = (( - 1 * cos(0.1 * x(0))) * exp(-1 * pow((x(0) * 0.1)- (2 * M_PIl),2))) + (0.002 * pow(0.1 * x(0), 2));
	return y;
}
matrix ff2T(matrix x, matrix ud1, matrix ud2)
{
	matrix y;
	y = pow(x(0),2) + pow(x(1), 2) - cos(2.5 * M_PIl * x(0)) - cos(2.5 * M_PIl * x(1)) + 2;
	return y;
}
matrix ff3TZ(matrix x, matrix ud1, matrix ud2)
{
	matrix y;
	y = (sin(M_PIl * sqrt( pow(x(0) / M_PIl,2) + pow(x(1) / M_PIl, 2)))
		        /(M_PIl *sqrt( pow(x(0) / M_PIl, 2) + pow(x(1) / M_PIl, 2))));
	if (-x(0) + 1 > 0)
	{
		//cout << "A:	" << endl;
		y = y + ud2(0) * pow(-x(0) + 1, 2);
	}
	if (-x(1) + 1 > 0)
	{
		//cout << "A:	" << endl;
		y = y + ud2(0) * pow(-x(1) + 1, 2);
	}
	if (norm(x) - ud1(0) > 0)
	{
		//cout << "B:	"  << endl;
		y = y + ud2(0) * pow(-x(0) -ud1(0), 2);
	}
	return y;
}
matrix ff3TW(matrix x, matrix ud1, matrix ud2)
{
	matrix y;
	y = (sin(M_PIl * sqrt(pow(x(0) / M_PIl, 2) + pow(x(1) / M_PIl, 2))) / (M_PIl * (pow(x(0) / M_PIl, 2) + pow(x(1) / M_PIl, 2))));
	
	for (int i = 0; i < 2; i++)
	{
		if (-x(i) + 1 > 0)
		{
			y = pow(10, 10);
		}
		else if(norm(x) - ud1(0) > 0)
		{
			y = pow(10, 10);
		}
		else
		{
			y = y - ud2(0) / (-x(i) + 1.0);
		}
	}
	return y;
}

/*
matrix Hf4T(matrix x, matrix ud1, matrix ud2)
{
matrix y(2,1,0.0);
	y(0, 0) = 5.0/42.0;
	y(1, 0) = -1.0/21.0;
	y(0, 1) = -1.0/21.0;
	y(1, 1) = 5.0/42.0;
	return y;
}

matrix Gf4T(matrix x, matrix ud1, matrix ud2)
{
	matrix y(2,1,0.0);
	y(0) = 10 * x(0) + 4 * x(1) - 17;
	y(1) = 10 * x(1) + 4 * x(0) - 19;
	return y;
}
/**/
matrix ff4T(matrix x, matrix ud1, matrix ud2)
{
	matrix y;
	if (isnan(ud2(0, 0)))
	{
		y = pow(x(0) + 2 * x(1) - 7, 2) + pow(2 * x(0) + x(1) - 5, 2);
	}
	else
	{
		y = ud1;
		y = y + x(0) * ud2;
		y = ff4T(ud1 + x * ud2);
	}
	return y;
}
matrix ff6T(matrix x, matrix ud1, matrix ud2)
{
	matrix y;
	y = pow(x(0),2) + pow(x(1),2) - cos(2.5 * M_PIl * x(0)) - cos(2.5 * M_PIl * x(1)) + 2;
	return y;
}
matrix Hf4T(matrix x, matrix ud1, matrix ud2)
{
	matrix y(2, 2, 0.0);
	y(0, 0) = 10;
	y(1, 0) = 8;
	y(0, 1) = 8;
	y(1, 1) = 10;
	return y;
}

matrix Gf4T(matrix x, matrix ud1, matrix ud2)
{
	matrix y(2, 1, 0.0);
	y(0) = 10.0 * x(0) + 8.0 * x(1) - 34.0;
	y(1) = 8.0 * x(0) + 10.0 * x(1) - 38.0;
	return y ;
}

matrix Gf4spa(matrix x, matrix ud1, matrix ud2)
{
	matrix y(3, 1, 0.0);
	//y = Gf4T(x, NULL, NULL);
	//cout << "Y:	" << (y) << endl;
	y = -1.0 * gradg(x, ud1, ud2);
	//cout << "Y:	" << (y) << endl;
	return y;
}

matrix Gf4spr(matrix x, matrix ud1, matrix ud2)
{
	matrix y(3, 1, 0.0);
	if (tak)
	{
		y = gradg(x, ud1, ud2);
		previ = y * -1;
		previg = y;
		tak = false;
		return y *-1;
	}
	else
	{
		double ffff;
		y = gradg(x, ud1, ud2);
		ffff = pow(norm(y), 2) / pow(norm(previg), 2);
		previg = y;
		y = -1 * y + ffff * previ;
		previ = y;
		return y;
	}
	/*
	matrix y(2, 1, 0.0);
	if (tak)
	{
		y = Gf4T(x, NULL, NULL);
		previ = y * -1;
		previg = y;
		tak = false;
		return y * -1;
	}
	else
	{
		matrix ffff(2, 1, 0.0);
		y = Gf4T(x, NULL, NULL);
		ffff = pow(norm(y), 2) / pow(norm(previg), 2);
		previg = y;
		y = -1 * y + ffff * previ;
		previ = y;
		return y;
	}/**/
}

matrix reset(matrix x, matrix ud1, matrix ud2)
{
	tak = true;
	return previ;
}

matrix Gf4N(matrix x, matrix ud1, matrix ud2)
{
	matrix y(2, 1, 0.0);
	//y = Gf4T(x, NULL, NULL);
	//cout << "Y:	" << (y) << endl;
	y = -1.0 * inv(ud1) * gradg(x, NULL, NULL);
	//cout << "Y:	" << (y) << endl;
	return y;
}

matrix ff0R(matrix x, matrix ud1, matrix ud2)
{
	matrix y;
	matrix Y0 = matrix(2, 1), MT = matrix(2, new double[2]{ m2d(x),0.5 });
	matrix* Y = solve_ode(df0, 0, 0.1, 10, Y0, ud1, MT);
	int n = get_len(Y[0]);
	double teta_max = Y[1](0, 0);
	for (int i = 1; i < n; ++i)
		if (teta_max < Y[1](i, 0))
			teta_max = Y[1](i, 0);
	y = abs(teta_max - m2d(ud1));
	Y[0].~matrix();
	Y[1].~matrix();
	return y;
}
matrix ff1R(matrix x, matrix ud1, matrix ud2)
{
	matrix y;
	//matrix x
	matrix Y0 = matrix(3, new double[3] { 5, 1,20 });
	//cout << "bbbb" << endl;
	matrix* Y = solve_ode(df1, 0, 1, 2000, Y0, ud1, x);
	//cout << "bbbb" << endl;
	int n = get_len(Y[0]);
	double max = Y[1](0, 2);
	for (int i = 0; i < n; i++)
	{
		//cout << Y[1](0, 2) << endl;
		if (max < Y[1](i, 2))

		{
			max = Y[1](i, 2);
		}
	}
	y = abs(max - 50);
	Y[0].~matrix();
	Y[1].~matrix();
	return y;
}
matrix ff2R(matrix x, matrix ud1, matrix ud2)
{
	//kol.open("symulacja_lab1.csv");
	matrix y(1);
	y(0) = 0;
	//matrix x
	matrix Y0(2,1), Yref(2, new double[2] {  3.14, 0 });
	//cout << "bbbb" << endl;
	matrix* Y = solve_ode(df2, 0, 0.1, 100, Y0, Yref, x);
	ofstream kol;
	kol.open("symulacja_lab1.csv");
	kol << hcat(Y[0], Y[1]);
	//cout << "bbbb" << endl;
	int n = get_len(Y[0]);
	for (int i = 0; i < n; i++)
	{
		y = y + 10.0 * pow(Yref(0) - Y[1](i, 0), 2)
			+ pow(Yref(1) - Y[1](i, 0), 2)
			+ pow(x(0) * (Yref(0) - Y[1](i, 0)) + x(1) * (Yref(1) - Y[1](i, 0)), 2);
		y = 0.1 * y;
	}
	Y[0].~matrix();
	Y[1].~matrix();
	return y;
}

matrix ff3R(matrix x, matrix ud1, matrix ud2)
{
	//kol.open("symulacja_lab1.csv");
	matrix y;
	//matrix x
	matrix Y0(4, new double[4] {  0, x(0),100,0 });
	//cout << "bbbb" << endl;
	matrix* Y = solve_ode(df3, 0, 0.01, 7, Y0, ud1, x(1));
	ofstream kol;
	//cout << "bbbb" << endl;
	int i50 = 0, i0 = 0;
	int n = get_len(Y[0]);
	for (int i = 0; i < n; i++)
	{
		if (abs(Y[1](i, 2) - 50.0) < abs(Y[1](i50, 2) - 50.0))
		{
			i50 = i;
		}
		if (abs(Y[1](i, 2)) < abs(Y[1](i0, 2)))
		{
			i0 = i;
		}
	}
	y = -Y[1](i0, 0);
	//cout << "AAAAAAAAa\n" << Y[1](i0, 0) << endl;
	//cout << "AAAAAAAAa\n" << Y[1][2] << endl;
	if (abs(x(0)) - 10 > 0)
		y = y + ud2 * pow(abs(x(0)) - 10, 2);
	if (abs(x(1)) - 15 > 0)
		y = y + ud2 * pow(abs(x(1)) - 15, 2);
	if (abs(Y[1](i50, 0) - 5.0) - 0.5 > 0)
		y = y + ud2 * pow(abs(Y[1](i50, 0) - 5.0) - 0.5, 2);
	//cout << "Wyn:\n	" << x << "\nwyn y\n" << y << endl;
	kol.open("symulacja_lab1.csv");
	kol << hcat(Y[1][0],Y[1][2]);
	Y[0].~matrix();
	Y[1].~matrix();
	return y;
}
matrix ff4Rh0(matrix x, matrix ud1, matrix ud2)
{
	matrix y;

	//cout << "cccc" << endl;
	y = 1.0 / (1.0 + exp((-1.0 * trans(ud1) * x)(0)));

	//cout << "ccc" << endl;
	return y;
}
matrix ff4Rgrad(matrix x, matrix ud1, matrix ud2)
{
	matrix y(3,1,0.0);
	for (int j = 0; j < 3; j++)
	{
		for (int i = 1; i <= 100; i++)
		{
			//cout << "ddd" << endl;
			y(j) = m2d(y(j)) + m2d(ff4Rh0(ud1[i - 1], x, NULL) - ud2(i - 1)) * ud1[i - 1](j);
			//cout << "y: " << y << endl;
			//cout << "dd" << endl;
		}
		y(j) = (1.0 / 100.0) * y(j);
	}
	return y;
}
matrix ff4RJ(matrix x, matrix ud1, matrix ud2)
{
	matrix y(1,1, 0.0);

	for (int i = 1; i <= 100; i++)
	{
		double a = m2d(ud2(i - 1) * log(ff4Rh0(ud1[i - 1], x, NULL)(0)));
		double b = ((1 - ud2(i - 1)) * log(1 - ff4Rh0(ud1[i - 1], x, NULL)(0)));
		//cout << "AAAA"<< a << endl;
		//cout << "AAAA" << b << endl;
		y = y + (ud2(i - 1) * log(ff4Rh0(ud1[i - 1], x, NULL)(0)) + ((1 - ud2(i - 1)) * log(1 - ff4Rh0(ud1[i - 1], x, NULL)(0))));
		//cout << "y: " << y<< endl;
	}
	y = (- 1.0 / 100.0)* y;
	return y;
}

matrix df0(double t, matrix Y, matrix ud1, matrix ud2)
{
	matrix dY(2, 1);
	double m = 1, l = 0.5, b = 0.5;// g = 9.81;
	double I = m*pow(l, 2);
	dY(0) = Y(1);
	dY(1) = ((t <= ud2(1))*ud2(0) - m*g*l*sin(Y(0)) - b*Y(1)) / I;
	return dY;
}
matrix df1(double t, matrix Y, matrix ud1, matrix ud2)
{
	matrix dY(3, 1);
	double Pa = 0.5;
	double Pb = 1;
	double Ta = 90;
	double Tbin = 20 ;
	//double Tb = 20;
	double Db = 36.5665 / 10000;
	double a = 0.98;
	double b = 0.63;
	//double Vb = 1;
	//double Va = 5;
	double fin = 10 / 1000;
	if (Y(0) > 0)
	{
		dY(0) = (-1) * (a * b * m2d(ud2) * sqrt(2.0 * g * Y(0) / Pa));
	}
	else
	{
		dY(0) = 0;
	}

	if (Y(1) > 0)
	{
		//cout << "bbbb" << endl;
		dY(1) = dY(0) + fin +(-1) * (a * b * m2d(ud2) * sqrt(2.0 * g * Y(1) / Pb));
	}
	else
	{
		dY(1) = dY(0) + fin;
	}
	//cout << "bbbb" << endl;
	dY(2) = fin / Y(1) * (Tbin - Y(2)) - dY(0) / Y(1) * (Ta - Y(2));
	
	if (con == 16)
	{
		//cout << Y(0) << "	" << endl;
		con = -1;
	}
	con++;
	//cout << -Y(0) << endl;
	//cout << -Y(1) << endl;
	cout << -Y(2)  << endl;
	//cout << "gggggg" << endl;
	return dY;
}
matrix df2(double t, matrix Y, matrix ud1, matrix ud2)
{
	matrix dY(2, 1);
	if (con == 100)
	{
		//kol << Y(0) << ";" <<Y(1) << ";\n";
		con = -1;
	}
	con++;
	dY(0) = Y(1);
	double l = 1;
	double mr = 1;
	double mc = 5;
	double I = mr * l * l / 3 + mc * l * l;
	double b = 0.5;
	double Mt = ud2(0) * (ud1(0) - Y(0)) + ud2(1) + (ud1(1) - Y(1));

	dY(1) = (Mt - b *Y(1)) / I;




	return dY;
}
matrix df3(double t, matrix Y, matrix ud1, matrix ud2)
{
	//Wektor zmian po czasie
	matrix dY(4, 1);

	//Zmienne dane
	double x = Y(0);
	double v_x = Y(1);
	double y = Y(2);
	double v_y = Y(3);

	//Dane zadania
	double C = 0.47;
	double rho = 1.2;
	double r = 0.12;
	double m = 0.6;
	//double gr = ud1(4);

	double s = 3.14 * pow(r, 2);

	double D_x = (1.0 / 2.0) * C * rho * s * v_x * abs(v_x);
	double D_y = (1.0 / 2.0) * C * rho * s * v_y * abs(v_y);
	double FM_x = rho * v_y * m2d(ud2) * M_PIl * pow(r, 3);
	double FM_y = rho * v_x * m2d(ud2) * M_PIl * pow(r, 3);

	dY(0) = v_x;
	dY(1) = (-D_x - FM_x) / m;
	dY(2) = v_y;
	dY(3) = ((-m * g) - D_y - FM_y) / m;

	return dY;
}
matrix df6(double t, matrix Y, matrix ud1, matrix ud2)
{
#if 1
	double m1 = 5;
	double m2 = 5;
	double k1 = 1;
	double k2 = 1;
	double F = 1.0;

	double b1 = ud2(0);
	double b2 = ud2(1);

	matrix dY(4, 1);
	dY(0) = Y(1);
	dY(1) = (-b1 * Y(1) - b2 * (Y(1) - Y(3)) - k1 * Y(0) - k2 * (Y(0) - Y(2))) / m1;
	dY(2) = Y(3);
	dY(3) = (F + b2 * (Y(1) - Y(3)) + k2 * (Y(0) - Y(2))) / m2;
	return dY;
#else
	double b1 = ud1(0);
	double b2 = ud1(1);
	double k1 = 1;
	double k2 = 1;
	double m1 = 5;
	double m2 = 5;
	double F = 1;

	matrix dY(4, 1);
	dY(0) = Y(1);
	dY(1) = (-b1 * Y(1) - b2 * (Y(1) - Y(3)) - k1 * Y(0) - k2 * (Y(0) - Y(2))) / m1;
	dY(2) = Y(3);
	dY(3) = (F + b2 * (Y(1) - Y(3)) + k2 * (Y(0) - Y(2))) / m2;

	return dY;
#endif
}

matrix fR6(matrix x, matrix ud1, matrix ud2)
{
#if 1
	matrix y;
	matrix Y0(4, 1);
	matrix* Y = solve_ode(df6, 0, 0.1, 100, Y0, ud1, x[0]);
	for (int i = 0; i < ud1(0); i++)
	{
		y = y + abs(ud2(i, 0) - Y[1](i, 0)) + abs(ud2(i, 1) - Y[1](i, 2));
	}
	y(0) = y(0) / (2 * ud1(0));


	return y;

#else
	matrix Y0(4, new double[4] { 0, 0, 0, 0 });
	matrix* Y = solve_ode(df6, 0, 0.01, 100, Y0, ud1, x(0));
	matrix y;
	int N = get_len(Y[0]);

	for (int i = 0; i < N; i++)
	{
		y = y + abs(x(i, 0) - Y[1](i, 0) + abs(x(i, 1) - Y[1](i, 2)));
	}

	return y;
#endif
}

