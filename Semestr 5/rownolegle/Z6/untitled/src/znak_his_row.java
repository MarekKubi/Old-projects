public /*static*/ class znak_his_row extends Thread  {
   int i;
   Obraz obraz_1;
    public znak_his_row(int ia, Obraz ob)
    {
       i = ia;
       obraz_1 = ob;
    }

    @Override
    public void run()
    {
        obraz_1.calculate_histogram_char(i);
        obraz_1.print_histogram_char(i);
    }

}