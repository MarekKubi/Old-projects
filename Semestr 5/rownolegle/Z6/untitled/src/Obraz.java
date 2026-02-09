import  java.util.Random;


class Obraz {

    private int size_n;
    private int size_m;
    private char[][] tab;
    private char[] tab_symb;
    private int[] hist_parallel;
    private int[] znak_count;
    private int[] histogram;


    public Obraz(int n, int m) {

        this.size_n = n;
        this.size_m = m;
        tab = new char[n][m];
        tab_symb = new char[94];

        final Random random = new Random();

        // for general case where symbols could be not just integers
        for(int k=0;k<94;k++) {
            tab_symb[k] = (char)(k+33); // substitute symbols
        }

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                tab[i][j] = tab_symb[random.nextInt(94)];  // ascii 33-127
                //tab[i][j] = (char)(random.nextInt(94)+33);  // ascii 33-127
                System.out.print(tab[i][j]+" ");
            }
            System.out.print("\n");
        }
        System.out.print("\n\n");

        histogram = new int[94];
        hist_parallel = new int[94];
        znak_count = new int[94];
        clear_histogram();
    }

    public void clear_histogram(){

        for(int i=0;i<94;i++)
        {
            histogram[i]=0;
            hist_parallel[i]=0;
            znak_count[i]=0;
        }

    }

    public void test_hist_par(){

        for(int i=0;i<94;i++)
        {
            if(histogram[i]!= hist_parallel[i])
            {
                System.out.print("Histogramy roznia sie od siebie w linijce:    " + i + "  znakiem: " + tab_symb[i]);
            }
        }

    }

    public void calculate_histogram(){

        for(int i=0;i<size_n;i++) {
            for(int j=0;j<size_m;j++) {

                // optymalna wersja obliczania histogramu, wykorzystująca fakt, że symbole w tablicy
                // można przekształcić w indeksy tablicy histogramu
                // histogram[(int)tab[i][j]-33]++;

                // wersja bardziej ogólna dla tablicy symboli nie utożsamianych z indeksami
                // tylko dla tej wersji sensowne jest zrównoleglenie w dziedzinie zbioru znaków ASCII
                for(int k=0;k<94;k++) {
                    if(tab[i][j] == tab_symb[k]) histogram[k]++;
                    //if(tab[i][j] == (char)(k+33)) histogram[k]++;
                }

            }
        }

    }

    public void calculate_histogram_char(int a){
        znak_count[a]=0;
        for(int i=0;i<size_n;i++) {
            for(int j=0;j<size_m;j++)
            {
                    if(tab[i][j] == tab_symb[a]) znak_count[a]++;
                    //if(tab[i][j] == (char)(k+33)) histogram[k]++;

            }
        }

    }

    public void calculate_histogram_par(int a, int b){
        for(int i=0;i<size_n;i++) {
            for(int j=0;j<size_m;j++)
            {
                for(int k=a;k<b;k++) {
                    if(tab[i][j] == tab_symb[k]) hist_parallel[k]++;
                    //if(tab[i][j] == (char)(k+33)) histogram[k]++;
                }

            }
        }

    }
// uniwersalny wzorzec dla różnych wariantów zrównoleglenia - można go modyfikować dla
// różnych wersji dekompozycji albo stosować tak jak jest zapisane poniżej zmieniając tylko
// parametry wywołania w wątkach
//
//calculate_histogram_wzorzec(start_wiersz, end_wiersz, skok_wiersz,
//                            start_kol, end_kol, skok_kol,
//                            start_znak, end_znak, skok_znak){
//
//  for(int i=start_wiersz;i<end_wiersz;i+=skok_wiersz) {
//     for(int j=start_kol;j<end_kol;j+=skok_kol) {
//        for(int k=start_znak;k<end_znak;k+=skok_znak) {
//           if(tab[i][j] == tab_symb[k]) histogram[k]++;
//


    public void print_histogram(){

        for(int i=0;i<94;i++) {
            System.out.print(tab_symb[i]+" "+histogram[i]+"\n");
            //System.out.print((char)(i+33)+" "+histogram[i]+"\n");
        }

    }

    public synchronized void print_histogram_char(int a)
    {
        System.out.print("\nWatek " + a + ": " + tab_symb[a] + "    ");
        for(int i=0;i<znak_count[a];i++)
        {
            System.out.print("#");
            //System.out.print((char)(i+33)+" "+histogram[i]+"\n");
        }
        if(histogram[a]!=znak_count[a])
        {
            System.out.print("\nWYSTAPIL BLAD LICZENIA!!!!!\n");
        }
    }


    public synchronized void print_histogram_par(int a, int b, int id){
int suma = 0;
int sumab = 0;
        System.out.print("\nWatek " + id + ": " + tab_symb[a] + " - " + tab_symb[b] );
        for(int j=a;j<b;j++)
        {
            System.out.print( "\n"+ tab_symb[j] + "    ");
            suma+=histogram[j];
            sumab += hist_parallel[j];
            for (int i = 0; i < hist_parallel[j]; i++) {
                System.out.print("#");
                //System.out.print((char)(i+33)+" "+histogram[i]+"\n");
            }

        }

        if(suma==hist_parallel[a])
        {
            System.out.print("\nWYSTAPIL BLAD LICZENIA!!!!!\n");
        }

    }
}
