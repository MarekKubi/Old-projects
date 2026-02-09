public /*static*/ class Znak_his_prz extends Thread  {
    int i;
    int a;
    int b;
    Obraz obraz_1;
    public Znak_his_prz(int ia, Obraz ob, int aa, int ba)
    {
        i = ia;
        a = aa;
        b = ba;
        obraz_1 = ob;
    }

    @Override
    public void run()
    {
        obraz_1.calculate_histogram_par(a, b);
        obraz_1.print_histogram_par(a, b,i);
    }

}