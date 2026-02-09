#include"opt_alg.h"

static bool tak = true;
static matrix previ(2, 1, 0.0);


solution MC(matrix(*ff)(matrix, matrix, matrix), int N, matrix lb, matrix ub, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		while (true)
		{
			Xopt = rand_mat(N);
			for (int i = 0; i < N; ++i)
				Xopt.x(i) = (ub(i) - lb(i)) * Xopt.x(i) + lb(i);
			Xopt.fit_fun(ff, ud1, ud2);
			if (Xopt.y < epsilon)
			{
				Xopt.flag = 1;
				break;
			}
			if (solution::f_calls > Nmax)
			{
				Xopt.flag = 0;
				break;
			}
		}

		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution MC(...):\n" + ex_info);
	}
}

double* expansion(matrix(*ff)(matrix, matrix, matrix), double x0, double d, double alpha, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		//cout << "exp " << endl;
		double* ret = new double[2] { 0, 0 };
		int i = 0;
		double x1 = x0 + d;
		double x9 = x1;
		double x8 = x9;
		/**/
		solution tmp1;
		matrix wyn[3];
		tmp1.x(0) = x1;
		//cout << "AAAAAAA" << endl;
		//cout << "AAAAAAA" << endl;
		wyn[0] = tmp1.fit_fun(ff);
		wyn[1] = wyn[0];
		wyn[2] = wyn[0];
		tmp1.x(0) = x0;
		wyn[0] = tmp1.fit_fun(ff);
		//double ret[2];
		//cout << "i: " << i << endl;
		if (wyn[1] == wyn[0])
		{
			ret[0] = x1;
			ret[1] = x0;
			return ret;
		}
		//cout << "i: " << i << endl;
		if (wyn[1] > wyn[0])
		{
			d = -d;
			x1 = x0 + d;
			tmp1.x(0) = x1;
			tmp1.fit_fun(ff);
			wyn[1] = tmp1.y;
			if (wyn[1] > wyn[0])
			{
				ret[0] = x1;
				ret[1] = x0 -d;
				return ret;
			}
		}
		do
		{
			//cout << "i: " << i << endl;
			if (tmp1.f_calls > Nmax)
			{
				//tmp1.f_calls = 0;
				return NULL;
			}
			i = i + 1;
			x8 = x9;
			x9 = x1;
			x1 = x0 + pow(alpha,i) * d;
			wyn[0] = wyn[1];
			wyn[1] = wyn[2];
			tmp1.x = x1;
			wyn[2] = tmp1.fit_fun(ff);
		} while (!(wyn[1] <= wyn[2]));
		//tmp1.f_calls = 0;
		//cout << "w: " << wyn[1] << wyn[2] << endl;
		if (d > 0)
		{
			ret[0] = x8;
			ret[1] = x1;
			//cout << "expw: " << ret[0] << "	" << ret[1] << endl;
			return ret;
		}
		ret[0] = x1;
		ret[1] = x8;
		//cout << "expw: " << ret[0] << "	" << ret[1] << endl;
		return ret;
		//return[x(i + 1), x(i - 1)]
	}

	catch (string ex_info)
	{
		throw ("double* expansion(...):\n" + ex_info);
	}/**/
	return 0;
}

solution fib(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, matrix ud1, matrix ud2)
{
	try
	{
		cout << "fib " << endl;
		double fk[100];
		fk[0] = 1;
		fk[1] = 1;
		int k = 2;
		while (true)
		{
			fk[k] = fk[k - 2] + fk[k - 1];
			if(fk[k] > (b - a) / epsilon)
			{ 
				break;
			}
			k++;
		}
		solution Xopt;
		//znajdŸ najmniejsz¹ liczbê k spe³niaj¹c¹ nierównoœæ k > (b - a) / e;
		//matrix tmp1;
		//matrix tmp2;
		solution tmp1;
		solution tmp2;
		//a(0) = a, b(0) = b;
		double c = b - fk[k-1]/ fk[k] * (b - a);
		double d = a + b - c;
			for (int i = 0; i < (k - 3); i++)
			{
				//cout << b - a << endl;
				//cout << i << endl;
				/*
				Xopt.x(0) = c;
				tmp1 = Xopt.fit_fun(ff, ud1, ud2);
				Xopt.x(0) = d;
				tmp2 = Xopt.fit_fun(ff, ud1, ud2);
				*/
				tmp1.x(0) = c;
				tmp1.fit_fun(ff);
				tmp2.x(0) = d;
				tmp2.fit_fun(ff);
				//cout << "c: " << tmp1.y << endl;
				//cout << "d: " << tmp2.y << endl;
				//if (fit_fun(ff, ud1, ud2)(c) < fit_fun(ff, ud1, ud2)(d))
				if(tmp1.y<tmp2.y)
				{
					//a = a;
					b = d;
				}
				else
				{
					//b = b;
					a = c;
				}
				c = b - (fk[k-i-2] / fk[k-i-1]) * (b - a);
				d = a + b - c;
			}
			//cout << b - a << endl;
		//16 : return x * = c(i + 1);
		Xopt.x(0) = c;
		Xopt.fit_fun(ff);
		//tmp1.f_calls = 0;
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution fib(...):\n" + ex_info);
	}

}

solution lag(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, double gamma, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		cout << "lag" << endl;
		solution Xopt;
		int i = 0;
		//a(0) = a, b(0) = b, c(0) = c
		matrix af, bf, cf, df;
		double c = (a+b) /2.0;
		double d = 0;
		double dp = 0;
		Xopt.x = a;
		af = Xopt.fit_fun(ff);
		Xopt.x = b;
		bf = Xopt.fit_fun(ff);
		Xopt.x = c;
		cf = Xopt.fit_fun(ff);
		do //repeat
		{
			//cout << b - a << endl;
			double l = af(0) * (pow(b, 2) - pow(c, 2)) + bf(0)*(pow(c, 2) 
				- pow(a, 2)) + cf(0)*(pow(a, 2) - (b, 2));
			double m = af(0) * (b - c) + bf(0)*(c - a) + m2d(cf)*(a - b);
			//cout << "lagm : " << m << "	" << l << endl;
			if (m <= 0)
			{
				//cout << "ret f : " << a << "	" << b << "	" << c << "	" << d << endl;
				//return error;
				//Xopt.x = 890;
				//Xopt.y = 789;
				df = Xopt.fit_fun(ff);
				return Xopt;
			}/**/
			dp = d;
			d = (0.5 * l) / m;
			/*
			Xopt.x = a;
			af = Xopt.fit_fun(ff);
			Xopt.x = b;
			bf = Xopt.fit_fun(ff);
			Xopt.x = c;
			cf = Xopt.fit_fun(ff);
			/**/
			Xopt.x = dp;
			df = Xopt.fit_fun(ff);
			if (a < d && d < c)
			{
				if (df(0) < cf(0))
				{
					//a = a;
					b = c;
					Xopt.x = b;
					bf = Xopt.fit_fun(ff);
					c = d;
					Xopt.x = c;
					cf = Xopt.fit_fun(ff);
				}
				else
				{
					a = d;
					Xopt.x = a;
					af = Xopt.fit_fun(ff);
					//c = c;
					//b = b;
				}
			}
			else 
			{
				if (c < d && d< b) 
				{
					if (df(0) < cf(0)) 
					{
						a = c;
						Xopt.x = a;
						af = Xopt.fit_fun(ff);
						c = d;
						Xopt.x = c;
						cf = Xopt.fit_fun(ff);
						//b = b;
					}
					else 
					{
						//a = a;
						//c = c;
						b = d;
						Xopt.x = b;
						bf = Xopt.fit_fun(ff);
					}
				}				
				else 
				{
					//cout << "ret ff : " << a<< "	" << b << "	" << c << "	"<< d << endl;
					//Xopt.x = 130;
					//Xopt.y = 4329;
					Xopt.x = d;
					Xopt.fit_fun(ff);
					return Xopt;
					
				}
			}
			i = i + 1;
			if (Xopt.f_calls > Nmax)
			{
				//cout << "ret call : " << (b - a) << endl;
				//Xopt.x = 130000;
				//Xopt.y = 4329;
				Xopt.x = d;
				df = Xopt.fit_fun(ff);
				return Xopt;
				//return error
			}

			//cout << "lage : " << (b- a)<< endl;

			//cout << "lagg : " << (d-dp) << endl;
		} while (!((b - a) < epsilon || abs(d - dp) < gamma));
		//return x * = d(i)
		/**/
		cout << b - a << endl;
		Xopt.x = d;
		df = Xopt.fit_fun(ff);
		return Xopt;
		/**/
	}
	catch (string ex_info)
	{
		throw ("solution lag(...):\n" + ex_info);
	}
}

solution HJ(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt0;
		Xopt0.x = x0;
		Xopt0.fit_fun(ff);
		solution XoptB;
		XoptB.x = x0;
		XoptB.fit_fun(ff);
		//cout << XoptB.x(0) << "	" << XoptB.x(1) << endl;
		matrix xBpod(2,1,0.0);
		//cout << XoptB.x(0) << "	" << XoptB.x(1) << endl;
		//cout << "a" << endl;
		//ofstream kol;
		//kol.open("symulacja_lab1.csv");
		do
		{//"	" << Xopt0.y << "	" << Xopt0.y << endl;
			XoptB.x = Xopt0.x;
			XoptB.fit_fun(ff);
			Xopt0 = HJ_trial(ff,XoptB, s, ud1, ud2);
			Xopt0.fit_fun(ff);
		//cout << "a" << endl;
			if (Xopt0.y < XoptB.y)
			{
				//cout << "b" << endl;
				do
				{
					//cout << Xopt0.x(0) << Xopt0.x(1) << endl;
					//kol << to_string(Xopt0.x(0)) << ";" << to_string(Xopt0.x(1)) << "\n";
					xBpod = XoptB.x;
					XoptB.x = Xopt0.x;
					//XoptB.x = XoptB.x;
					XoptB.fit_fun(ff);
					//cout << Xopt0.x(0) << "	" << Xopt0.x(1) << "	" << Xopt0.y << "	" << Xopt0.y << endl;
					Xopt0.x = 2 * XoptB.x - xBpod;
					//cout << Xopt0.x(0) << "	" << Xopt0.x(1) << "	" << Xopt0.y << "	" << Xopt0.y << endl;
					//Xopt0.fit_fun(ff);
					Xopt0.fit_fun(ff);
					Xopt0 = HJ_trial(ff, Xopt0, s, ud1, ud2);
					Xopt0.fit_fun(ff);
					if (Xopt0.f_calls > Nmax)
					{
						Xopt0.x = -500900;
						Xopt0.y = -500900;
						return Xopt0;
					}
				} while (!(Xopt0.y >= XoptB.y));
				Xopt0.x = XoptB.x;
				Xopt0.fit_fun(ff);
			}
			else
			{
				s = alpha * s;
			}
			if (Xopt0.f_calls > Nmax)
			{
				Xopt0.x = -500901;
				Xopt0.y = -500901;
				return Xopt0;
			}
		} while (!(s < epsilon));

			//22 : return x * = xB
		Xopt0.x = XoptB.x;
		Xopt0.fit_fun(ff);
		return Xopt0;
	}
	catch (string ex_info)
	{
		throw ("solution HJ(...):\n" + ex_info);
	}
}

solution HJ_trial(matrix(*ff)(matrix, matrix, matrix), solution Xopt0, double s, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopte;

		matrix e(2, 2, 0.0);
		for (int k = 0; k < 2; k++)
		{
			e(k, k) = 1;//ej;//, j = 1, 2, …, n
		}

		for (int j = 0; j < get_len(Xopt0.x); j++) // j <n
		{// to n do
			Xopte.x = (Xopt0.x + s * e[j]);
			Xopte.fit_fun(ff);
			if (Xopte.y < Xopt0.y)
			{
				Xopt0.x = Xopte.x;
				Xopt0.fit_fun(ff);
			}
			else
			{
				Xopte.x = (Xopt0.x - s * e[j]);
				Xopte.fit_fun(ff);
				if (Xopte.y < Xopt0.y)
				{
					Xopt0.x = Xopte.x;
					Xopt0.fit_fun(ff);
				}
			}
		}
		return Xopt0.x;
	}
	catch (string ex_info)
	{
		throw ("solution HJ_trial(...):\n" + ex_info);
	}
}

solution Rosen(matrix(*ff)(matrix, matrix, matrix), matrix x0, matrix s0, double alpha, double beta, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		matrix s0j = s0;
		double maxi = 0;
		solution Xopt;
		Xopt.x = x0;
		int i = 0;
		int n = 2;
		matrix dj(2,2, 0.0);
		matrix Q(2, 2, 0.0);
		matrix mn(2, 2, 0.0);
		matrix V(2, 2, 0.0);
		bool tak = true;
		//ofstream kol;
	//kol.open("symulacja_lab1.csv");
		for (int k = 0; k < 2; k++)
		{
			dj(k, k) = 1;//ej;//, j = 1, 2, …, n
		}
		matrix lambj(2,1, 0.0);//, j = 1, 2, …, n
		matrix pj(2,1, 0.0);//, j = 1, 2, …, n
		solution xB;
		xB.x = x0;
		xB.fit_fun(ff);
		do
		{	//repeat
			//cout << "a" << endl;

			//cout << "a" << endl;
			for (int j = 0; j<n; j++) 
			{
				//cout << Xopt.x(0) << Xopt.x(1) << endl;
				//kol << to_string(Xopt.x(0)) << ";" << to_string(Xopt.x(1)) << "\n";
				Xopt.x = xB.x + s0(j) * dj[j];
				Xopt.fit_fun(ff);
				xB.fit_fun(ff);
				//cout << "a" << endl;
				if (Xopt.y < xB.y)
				{
					//cout << "a" << endl;
					xB.x = xB.x + s0(j) * dj(j);
					lambj(j) = lambj(j) + s0(j);
					s0(j) = alpha * s0(j);
					//cout << "a" << endl;
				}
				else
				{
					//cout << "b" << endl;
					s0(j) = -beta * s0(j);
					pj(j) = pj(j) +1;
				}
			}
			//cout << "a" << endl;
			i = i + 1;
			x0 = xB.x;
			//cout <<x0  << endl << endl;
			tak = true;
			for (int k = 0; k < 2; k++)
			{
				if (lambj(k) == 0 || pj(k) == 0)
				{
					tak = false;
				}
			}
			if (tak)
			{// != 0, j = 1, 2, …, n then
				for (int k = 0; k < 2; k++)
				{
					for (int h = 0; h < 2; h++)
					{
						if (k <= h)
						{
							mn(k, h) = lambj(k);
						}
					}
				}
				Q = dj * mn;
				V(0) = Q(0);
				V(1) = Q(1) - ((trans(Q(0)) * dj(0))(0) * dj(0));
				dj = V;
				//20 : zmiana bazy kierunków dj(i)
				for (int k = 0; k < 2; k++)
				{
					lambj(k) = 0;//ej;//, j = 1, 2, …, n
					pj(k) = 0;
				}
				//cout << "s" << endl;
				s0 = s0j;
			}
			if (Xopt.f_calls > Nmax)
			{
					//return error
			}
			//cout << "AFSAFDSAF" << maxi << "	" << s0(0) << endl;
			//cout << "AFSAFDSAF" << maxi << "	" << s0(1) << endl;
			maxi = 0;
			//cout << maxi << "	" << epsilon << endl;

			for (int k = 0; k < 2; k++)
			{
				//cout << "AFSAFDSAF" << maxi << "	" << s0(k) << endl;
				if (s0(k) < 0)
				{
					if (maxi < -s0(k))
					{
						maxi = -s0(k);
					}
				}
				else
				{
					if (maxi < s0(k))
					{
						maxi = s0(k);
					}
				}
			}
			//cout << maxi << "	" << epsilon << endl;
			if (maxi < epsilon)
			{
				break;
			}
		} while (1);//(!(maxi < epsilon));//(max < epsilon); // until maxj = 1, …, n(| sj(i) | ) < epsilon
			//29 : return x * = x(i)
		//cout << maxi << "	" << epsilon << endl;
		Xopt.x = x0;
		Xopt.fit_fun(ff);
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Rosen(...):\n" + ex_info);
	}
}

/*/**/
solution pen(matrix(*ff)(matrix, matrix, matrix), matrix x0, double c, double dc, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try {
		solution Xopt, Xopt1;
		Xopt.x = x0;
		Xopt1.x = x0;
		Xopt.ud = ud2;
		Xopt1.ud = ud2;
		double alfa = 1, beta = 0.5, gama = 2, delta = 0.5, s = 0.5;
		//double tab[2] = { c, ud1(0)};
		matrix u1 = ud1;
		matrix u2 = c;
		Xopt1.fit_fun(ff, u1, u2);
		bool tak = true;
		int i = 0;
		do {
			Xopt = Xopt1;
			i = i + 1;
			Xopt1.ud = u2;
			//cout << "XP:\n" << Xopt.x << endl;
			Xopt1 = sym_NM(ff, Xopt.x, s, alfa, beta, gama, delta, epsilon, Nmax, u1, u2);

			//cout << "XA:\n" << Xopt.x << endl;
			u2 = u2 * dc; // = c * a

			if (Xopt.f_calls > Nmax)
			{
				//Xopt.x(0) = -99999;
				return Xopt;
			}
			if (norm(Xopt1.x - Xopt.x ) < epsilon)
			{
				//cout << Xopt1.x << "	" << Xopt.x << x0 << endl;
				tak = false;
			}
		} while (tak);
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution pen(...):\n" + ex_info);
	}
}
solution sym_NM(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double beta, double gamma, double delta, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		bool tak = true;
		int n = 3;
		solution Xopt;
		//matrix p(3,2,0.0);
		matrix p[3];
		p[0] = x0;
		//cout << "P:\n" << p << endl;
		//cout << "X0:\n" << x0 << endl;
		//p[0] = x0[0];
		//cout << "P:\n" << p << endl;
		double max;
		int max_id=0;
		double min;
		int min_id = 0;
		double odb;
		matrix p_p(2, 1, 0.0);
		matrix p_odb(2, 1, 0.0);
		matrix p_e(2, 1, 0.0);
		double pe;
		matrix p_z(2, 1, 0.0);
		double pz;
		matrix e(2, 2, 0.0);
		//cout << "ABVAC " << endl;
		for (int i = 0; i < 2; i++)
		{
			e(i,i) = 1;
		}
		//cout << "AAAAAA" << endl;
		//cout << "P[0]:\n" << p[0] << endl;
		for (int i = 1; i < n; i++)
		{
			p[i] = p[0] + s * e[i-1];
			//cout << "P[i]:\n" << p[i] << endl;
		}

		//cout << "P:\n" << p << endl;
		do //repeat
		{
			Xopt.x = p[0];
			Xopt.fit_fun(ff, ud1, ud2);
			max = Xopt.y(0);
			max_id = 0;
			min = Xopt.y(0);
			min_id = 0;
			//cout << "ABVAC " << endl;
			for (int i = 0; i < n; i++)
			{
				//cout << "X:	" << Xopt.x(0) << "	" << Xopt.x(1) << endl;
				Xopt.x = p[i];
				//cout << "X:	" << Xopt.x(0) << "	" << Xopt.x(1) << endl;
				//cout << "I:	" << i   << endl;
				Xopt.fit_fun(ff, ud1, ud2);
				//cout << "I:	" << i << endl;
				if (Xopt.y(0) > max)
				{
					max = Xopt.y(0);
					max_id = i;
				}
				if (Xopt.y(0) <= min && i != max_id)
				{
					min = Xopt.y(0);
					min_id = i;
				}
			}
				// 
				// 
			for (int i = 0; i < n; i++)
			{
				if (max_id != i)
				{
					p_p = p_p + p[i];
				}
			}
			p_p = p_p / (double)n;
			p_odb = p_p + alpha * (p_p - p[max_id]);

			Xopt.x = p_odb;
			Xopt.fit_fun(ff,ud1,ud2);
			odb = Xopt.y(0);

			if (odb < min)
			{
				p_e = p_p + gamma * (p_odb - p_p);
				Xopt.x = p_odb;
				Xopt.fit_fun(ff, ud1, ud2);
				pe = Xopt.y(0);

				if (pe < odb)
				{
					p[max_id] = p_e;
					max = pe;
				}
				else
				{
					p[max_id] = p_odb;
					max = odb;
				}
			}
			else
			{
				if ((min <= odb) && (odb < max))
				{
					p[max_id] = p_odb;
					max = odb;
				}
				else
				{
					p_z = p_p + beta * (p[max_id] - p_p);
					Xopt.x = p_z;
					Xopt.fit_fun(ff, ud1, ud2);
					pz = Xopt.y(0);
					if (pz >= max)
					{
						for (int i = 0; i < n; i++)
						{
							if (i != min_id)
							{
								p[i] = delta * (p[i] + p[min_id]);
							}
						}
					}
					else
					{
						p[max_id] = p_z;
						max = pz;
					}
				}
			}

		if (Xopt.f_calls > Nmax)
		{
			Xopt.x(0) = -99999;
			return Xopt;
		}

		for (int i = 0; i < n; i++)
		{
			if (norm(p[min_id] - p[i]) < epsilon)// && (norm(p[min_id] - p[i]) > epsilon))
			{
				tak = false;
			}
		}
		} while (tak);

		Xopt.x = p[min_id];
		Xopt.fit_fun(ff, ud1, ud2);
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution sym_NM(...):\n" + ex_info);
	}
}
/**//*
solution pen(matrix(*ff)(matrix, matrix, matrix), matrix x0, double c, double dc, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try {
		solution XB;
		XB.x = x0;
		XB.fit_fun(ff, ud1, ud2);

		solution XT;
		XT = XB;

		double s = 0.5; //D³ugoœæ boku trójk¹ta
		double alpha = 1.0; //Wspó³czynnik odbicia
		double beta = 0.5; //Wspó³czynnik zwê¿enia
		double gamma = 2.0; //Wspó³czynnik ekspansji
		double delta = 0.5; //Wspó³czynnik redukcji

		do
		{
			XT.x = XB.x;
			XT = sym_NM(ff, XB.x, s, alpha, beta, gamma, delta, epsilon, Nmax, ud1, c);
			c *= dc;

			if (solution::f_calls > Nmax)
			{
				XT.flag = 0;
				throw std::string("Maximum amount of f_calls reached!");
			}

			if (norm(XT.x - XB.x) < epsilon)
				break;

			XB = XT;
		} while (true);


		XB.fit_fun(ff, ud1, c);
		return XB;
	}
	catch (string ex_info)
	{
		throw ("solution pen(...):\n" + ex_info);
	}
}

solution sym_NM(matrix(*ff)(matrix, matrix, matrix), matrix x0, double s, double alpha, double beta, double gamma, double delta, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		//Funkcja pomocnicza do znajdywania maksymum normy
		auto max = [&](std::vector<solution> sim, int i_min) -> double
			{
				double result = 0.0;
				for (int i = 0; i < sim.size(); ++i)
				{
					double normal = norm(sim[i_min].x - sim[i].x);
					if (result < normal)
						result = normal;
				}
				return result;
			};

		int n = get_len(x0);

		//Tworzenie bazy ortogonalnej
		matrix d = matrix(n, n);
		for (int i = 0; i < n; ++i)
			d(i, i) = 1.0;

		//Tworzenie simplexu i uzupe³nianie go danymi
		std::vector<solution> simplex;
		simplex.resize(n + 1);
		simplex[0].x = x0;
		simplex[0].fit_fun(ff, ud1, ud2);
		for (int i = 1; i < simplex.size(); ++i)
		{
			simplex[i].x = simplex[0].x + s * d[i - 1];
			simplex[i].fit_fun(ff, ud1, ud2);
		}

		//Indeks najmniejszej wartoœci wierzcho³ka simplexu
		int i_min{};
		//Indeks najwiêkszej wartoœci wierzcho³ka simplexu
		int i_max{};

		while (max(simplex, i_min) >= epsilon)
		{
			//Wyznaczanie maksymalnego i minimalnego indeksu
			i_min = 0;
			i_max = 0;
			for (int i = 1; i < simplex.size(); ++i)
			{
				if (simplex[i].y < simplex[i_min].y)
					i_min = i;
				if (simplex[i].y > simplex[i_max].y)
					i_max = i;
			}

			//Wyznaczenie œrodka ciê¿koœci
			matrix simplex_CoG{};
			for (int i = 0; i < simplex.size(); ++i)
			{
				if (i == i_max)
					continue;
				simplex_CoG = simplex_CoG + simplex[i].x;
			}
			simplex_CoG = simplex_CoG / simplex.size();

			//Obliczanie wartoœci funkcji odbitego simplexu
			solution simplex_reflected{};
			simplex_reflected.x = simplex_CoG + alpha * (simplex_CoG - simplex[i_max].x);
			simplex_reflected.fit_fun(ff, ud1, ud2);

			if (simplex_reflected.y < simplex[i_min].y)
			{
				//Obliczanie wartoœci funkcji powiêkszonego simplexu
				solution simplex_expansion{};
				simplex_expansion.x = simplex_CoG + gamma * (simplex_reflected.x - simplex_CoG);
				simplex_expansion.fit_fun(ff, ud1, ud2);
				if (simplex_expansion.y < simplex_reflected.y)
					simplex[i_max] = simplex_expansion;
				else
					simplex[i_max] = simplex_reflected;
			}
			else
			{
				if (simplex[i_min].y <= simplex_reflected.y && simplex_reflected.y < simplex[i_max].y)
					simplex[i_max] = simplex_reflected;
				else
				{
					//Obliczanie wartoœci funkcji pomniejszonego simplexu
					solution simplex_narrowed{};
					simplex_narrowed.x = simplex_CoG + beta * (simplex[i_max].x - simplex_CoG);
					simplex_narrowed.fit_fun(ff, ud1, ud2);
					if (simplex_narrowed.y >= simplex[i_max].y)
					{
						for (int i = 0; i < simplex.size(); ++i)
						{
							if (i == i_min)
								continue;
							simplex[i].x = delta * (simplex[i].x + simplex[i_min].x);
							simplex[i].fit_fun(ff, ud1, ud2);
						}
					}
					else
						simplex[i_max] = simplex_narrowed;
				}
			}

			if (solution::f_calls > Nmax)
			{
				simplex[i_min].flag = 0;
				throw std::string("Maximum amount of f_calls reached!");
			}

		}

		return simplex[i_min];
	}
	catch (string ex_info)
	{
		throw ("solution sym_NM(...):\n" + ex_info);
	}
}
/**/

solution SD(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		int* n = get_size(x0);
		matrix O(2,2,0.0);
		O(0, 0) = -10;
		O(0, 1) = 10;
		O(1, 0) = -10;
		O(1, 1) = 10;
		double b = 0;
		solution Xopt;
		Xopt.x = x0;
		matrix xp = x0;
		//matrix h;
		//cout << (Xopt.x - xp) << endl;
		//cout << (Xopt.x) << endl;
		//cout << (xp) << endl;
		int i = 0;
		double hi = h0;
		bool pen = true;
		matrix p1(2, 1, 0.0);
		matrix p2(2, 1, 0.0);
		cout << (Xopt.x) << endl;
		do
		{
			//cout << "A" << endl;
			xp(0) = Xopt.x(0);
			xp(1) = Xopt.x(1);
			//repeat
			//3 : wyznacz d(i)
			solution h,d;
			d.x = Xopt.x;
			d.y = d.grad(gf, ud1, ud2);
			//cout << "d:	" << d.y << endl;
			//cout << (Xopt.x) << endl;
			b = compute_b(d.x, d.y, O);
			//cout << "B:	" << b << endl;


			if (h0 == -1)
			{
				h.y = (golden(ff, 0, b, epsilon, Nmax, xp, d.y)).x;
			}
			else
			{
				h.y = h0;
				//cout <<"h:	" << h.y << endl;
			}
			//cout << "krok:	" << h.y << endl;
			//cout << "A" << endl;
			//h.x = Xopt.x;
			//h.fit_fun(gf, ud1, ud2);
			//	4 : wyznacz h(i)
			//cout << "A" << endl;
			Xopt.x = Xopt.x + h.y * d.y;//(i + 1) = x(i) + h(i)*d(i)
			i = i + 1;
			if (Xopt.f_calls > Nmax || i>Nmax)
			{//// then
				//Xopt.x = 999999;
				return Xopt;
			}//	9 : end if
			//cout <<"norm:	"<< norm(Xopt.x - xp) << endl;
			//cout << "d:	" << d.y << endl;
			//cout << (Xopt.x) << endl;
			//cout << ff4T(Xopt.x) << endl;
			if (norm(Xopt.x - xp) < epsilon)
			{
				pen = false;
			}
		} while (pen);// until || x(i) – x(i - 1) || 2 < epsilon
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution SD(...):\n" + ex_info);
	}
}

solution CG(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		Xopt.x = x0;
		matrix xp = x0;
		matrix O(2, 2, 0.0);
		O(0, 0) = -10;
		O(0, 1) = 10;
		O(1, 0) = -10;
		O(1, 1) = 10;
		double b = 0;
		//cout << (Xopt.x - xp) << endl;
		//cout << (Xopt.x) << endl;
		//cout << (xp) << endl;
		int i = 0;
		double hi = h0;
		bool pen = true;
		do
		{
			//cout << "A" << endl;
			xp(0) = Xopt.x(0);
			xp(1) = Xopt.x(1);
			xp(2) = Xopt.x(2);
			//repeat
			//3 : wyznacz d(i)
			solution h, d;
			d.x = Xopt.x;
			d.y = d.grad(gf, ud1, ud2);
			//cout << "d:	" << d.y << endl;
			//cout << (Xopt.x) << endl;
			//cout << "B:	"  << endl;
			h.y(0) = h0;
			//cout << "B:	" << endl;
			//b = compute_b(d.x, d.y, O);
			//cout << "B:	" << endl;
			//cout << "B:	" << b << endl;


			if (h0 == -1)
			{
				h.y = (golden(ff, 0, b, epsilon, Nmax, xp, d.y)).x;
			}
			else
			{
				h.y = h0;
			}
			//h.x = Xopt.x;
			//h.fit_fun(gf, ud1, ud2);
			//	4 : wyznacz h(i)
			//cout << "Aaaaaaaaaaaaaaaaaaaaaaaa" << endl;
			Xopt.x = Xopt.x + h.y * d.y;//(i + 1) = x(i) + h(i)*d(i)
			i = i + 1;
			if (Xopt.f_calls > Nmax || i > Nmax)
			{//// then
				//Xopt.x = 999999;
				return Xopt;
			}//	9 : end if
			//cout << "norm:	" << norm(Xopt.x - xp) << endl;
			//cout << (Xopt.x) << endl;
			//cout << (xp) << endl;
			//cout <<"norm:	"<< norm(Xopt.x - xp) << endl;
			//cout << (Xopt.x) << endl;
			//cout << (xp) << endl;
			if (norm(Xopt.x - xp) < epsilon)
			{
				pen = false;
			}
			//cout << "norma:	" << norm(Xopt.x - xp) << endl;
		//	cout << (Xopt.x) << endl;
		//	cout << (xp) << endl;
		} while (pen);// until || x(i) – x(i - 1) || 2 < epsilon
		//cout << "normaaaaaaaaaaaa:	" << norm(Xopt.x - xp) << endl;
		//cout << (Xopt.x) << endl;
		//cout << (xp) << endl;
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution CG(...):\n" + ex_info);
	}
}

solution Newton(matrix(*ff)(matrix, matrix, matrix), matrix(*gf)(matrix, matrix, matrix),
	matrix(*Hf)(matrix, matrix, matrix), matrix x0, double h0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt;
		Xopt.x = x0;
		matrix xp = x0;
		matrix O(2, 2, 0.0);
		O(0, 0) = -10;
		O(0, 1) = 10;
		O(1, 0) = -10;
		O(1, 1) = 10;
		double b = 0;
		//cout << (Xopt.x - xp) << endl;
		//cout << (Xopt.x) << endl;
	//	cout << (xp) << endl;
		int i = 0;
		double hi = h0;
		bool pen = true;
		do
		{
			//cout << "A" << endl;
			xp(0) = Xopt.x(0);
			xp(1) = Xopt.x(1);
			//repeat
			//3 : wyznacz d(i)
			solution h, he, d;
			d.x = Xopt.x;
			h.x = Xopt.x;
			he.y=he.hess(Hf);
			d.y = d.grad(gf, he.y, ud2);
			//h.y(0) = h0;
			b = compute_b(d.x, d.y, O);
			//cout << "B:	" <<b << endl;

			if(h0 ==-1)
			{
				h.y = (golden(ff, 0, b, epsilon, Nmax, xp, d.y)).x;
			}
			else 
			{
				h.y = h0;
			}
			//h.x = Xopt.x;
			//h.fit_fun(gf, ud1, ud2);
			//	4 : wyznacz h(i)
			//cout << "A" << endl;
			Xopt.x = Xopt.x + h.y * d.y;//(i + 1) = x(i) + h(i)*d(i)
			i = i + 1;
			if (Xopt.f_calls > Nmax || i > Nmax)
			{//// then
				//Xopt.x = 999999;
			}//	9 : end if
			if (norm(Xopt.x - xp) < epsilon)
			{
				pen = false;
			}
		} while (pen);// until || x(i) – x(i - 1) || 2 < epsilon
		//cout << "normaaaaaaaaaaaa:	" << norm(Xopt.x - xp) << endl;
		//cout << (Xopt.x) << endl;
		//cout << (xp) << endl;
		//Xopt.fit_fun(ff4T);
		return Xopt;
	}
	catch (string ex_info)
	{
		throw ("solution Newton(...):\n" + ex_info);
	}
}

double compute_b(matrix x, matrix d, matrix limits)
{
	int* n = get_size(x);
	double b = 1e9, bi;
	for (int i = 0; i < n[0]; ++i)
	{
		if (d(i) == 0)
			bi = 1e9;
		else if (d(i) > 0)
			bi = (limits(i, 1) - x(i)) / d(i);
		else
			bi = (limits(i, 0) - x(i)) / d(i);
		if (b != bi)
			b = bi;
	}
	return b;
}

solution golden(matrix(*ff)(matrix, matrix, matrix), double a, double b, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt, Xopt_a, Xopt_b, Xopt_c, Xopt_d;
		int i = 0;
		double al = (sqrt(5.0) - 1.0) / 2.0;
		//a(0) = a, b(0) = b
		matrix tmp;
		Xopt_a.x = a;
		Xopt_a.fit_fun(ff, ud1, ud2);
		Xopt_b.x = b;
		Xopt_b.fit_fun(ff, ud1, ud2);
		Xopt_c.x = Xopt_b.x - al*(Xopt_b.x - Xopt_a.x);
		Xopt_c.fit_fun(ff, ud1, ud2);
		Xopt_d.x = Xopt_a.x + al*(Xopt_b.x - Xopt_a.x);
		Xopt_d.fit_fun(ff, ud1, ud2);
		//cout << "d:	" << Xopt_d.y << endl;
		//cout << "c:	" << Xopt_d.y << endl;
		do//	6 : repeat
		{
			i++;
			//cout << "A:	" << Xopt_a.x << endl;
			if (Xopt_c.y < Xopt_d.y)
			{//then
				//cout << "Afff:	" << Xopt_a.x << endl;
			//	8 : a(i + 1) = a(i)
				//tmp = Xopt_b.x;
				Xopt_b = Xopt_d;
				Xopt_d = Xopt_c;
				Xopt_c.x = Xopt_b.x - al * (Xopt_b.x - Xopt_a.x);
				//cout << "Ai:	" << Xopt_a.x << endl;
				Xopt_c.fit_fun(ff, ud1, ud2);
				//cout << "A:	" << Xopt_a.x << endl;
			}
			else
			{
				//cout << "Aiasda:	" << Xopt_a.x << endl;
			Xopt_a = Xopt_c;
			//14 : b(i + 1) = b(i)
			Xopt_c = Xopt_d;
			Xopt_d.x = Xopt_a.x + al * (Xopt_b.x - Xopt_a.x);
			//cout << "Aiasda:	" << Xopt_a.x << endl;
			Xopt_c.fit_fun(ff, ud1, ud2);
			//cout << "A:	" << Xopt_a.x << endl;
			}//	17 : end if
			i = i + 1;
			if (i > Nmax)//
			{
				//Xopt.x(0) = -99999;
				return Xopt;
			}//	21 : end if
			if (Xopt_b.x - Xopt_a.x < epsilon)
			{
				break;
			}
		} while (true);//(b - a < epsilon);
		//		22 : until b(i) – a(i) < epsilon
		Xopt.x = (Xopt_a.x + Xopt_b.x) / 2.0;
		//cout << "gold: " << Xopt.x << endl;
		//Xopt.fit_fun(ff, ud1, ud2);
		return Xopt;//x * = (a(i) + b(i)) / 2
	}
	catch (string ex_info)
	{
		throw ("solution golden(...):\n" + ex_info);
	}
}

solution Powell(matrix(*ff)(matrix, matrix, matrix), matrix x0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution Xopt; 
		int i = 0;
		matrix e(2, 2, 0.0);
		matrix p(2, 2, 0.0);
		matrix d(2, 2, 0.0);
		matrix h(2, 2, 0.0);

			
		return Xopt; 

	}
	catch (string ex_info)
	{
		throw ("solution Powell(...):\n" + ex_info);
	}
}

solution EA(matrix(*ff)(matrix, matrix, matrix), int N, matrix lb, matrix ub, int mi, int lambda, matrix sigma0, double epsilon, int Nmax, matrix ud1, matrix ud2)
{
	try
	{
		solution* P = new solution[mi + lambda];
		solution* Pm = new solution[mi];

		matrix IFF(mi, 1), temp(N, 2);

		double r, s, s_IFF;
		double tau = 1.0 / sqrt(2 * N), tau1 = 1.0 / sqrt(2 * sqrt(N));

		int j_min;

		for (int i = 0; i < mi; ++i)
		{
			P[i].x = matrix(N, 2);

			P[i].x(0, 0) = (lb(1) - lb(0)) * m2d(rand_mat()) + lb(0);
			P[i].x(0, 1) = sigma0(0);

			P[i].x(1, 0) = (ub(1) - ub(0)) * m2d(rand_mat()) + ub(0);
			P[i].x(1, 1) = sigma0(0);

			P[i].fit_fun(ff, ud1, ud2);

			if (P[i].y < epsilon)
			{
				P[i].flag = 1;
				return P[i];
			}
		}
		while (true)
		{
			s_IFF = 0;

			for (int i = 0; i < mi; ++i)
			{
				IFF(i) = 1 / P[i].y(0);
				s_IFF += IFF(i);
			}

			for (int i = 0; i < lambda; ++i)
			{
				r = s_IFF * m2d(rand_mat()); ;
				s = 0;
				for (int j = 0; j < mi; ++j)
				{
					s += IFF(j);
					if (r <= s)
					{
						P[mi + i] = P[j];
						break;
					}
				}
			}

			for (int i = 0; i < lambda; ++i)
			{
				r = m2d(randn_mat());
				for (int j = 0; j < N; ++j)
				{
					P[mi + i].x(j, 1) *= exp(tau1 * r + tau * m2d(randn_mat()));
					P[mi + i].x(j, 0) += P[mi + i].x(j, 1) * m2d(randn_mat());
	}
}

			for (int i = 0; i < lambda; i += 2)
			{
				r = m2d(rand_mat());
				temp = P[mi + i].x;
				P[mi + i].x = r * P[mi + i].x + (1 - r) * P[mi + i + 1].x;
				P[mi + i + 1].x = r * P[mi + i + 1].x + (1 - r) * temp;
			}

			for (int i = 0; i < lambda; ++i)
			{
				P[mi + i].fit_fun(ff, ud1, ud2);
				if (P[mi + i].y < epsilon)
				{

					P[mi + i].flag = 1;
					return P[mi + i];
				}
			}

			for (int i = 0; i < mi; ++i)
			{
				j_min = 0;
				for (int j = 1; j < mi + lambda; ++j)
					if (P[j_min].y > P[j].y)
						j_min = j;
				Pm[i] = P[j_min];
				P[j_min].y = 1e10;
			}

			for (int i = 0; i < mi; ++i)
				P[i] = Pm[i];

			if (solution::f_calls > Nmax)
				break;
		}

		P[0].flag = 0;

		return P[0];
	}
	catch (string ex_info)
	{
		throw ("solution EA(...):\n" + ex_info);
	}
}
