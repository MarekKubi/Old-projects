import java.util.Scanner;


class Histogram_test {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.println("Set image size: n (#rows), m(#kolumns)");
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        Obraz obraz_1 = new Obraz(n, m);

        obraz_1.calculate_histogram();
        obraz_1.print_histogram();

         System.out.println("Set number of threads char");
         int num_threads = scanner.nextInt();

        znak_his_row[] NewThr = new znak_his_row[num_threads];

         for (int i = 0; i < num_threads; i++) {
             NewThr[i] = new znak_his_row(i, obraz_1);
             NewThr[i].start();
         }
         for (int i = 0; i < num_threads; i++) {
             try {
         	NewThr[i].join();
                 if (Thread.interrupted()) {
                     throw new InterruptedException();
                 }
             } catch (InterruptedException e) {}
         }

        System.out.println("\nSet number of threads bound");
        int num_threads_b = scanner.nextInt();
        int krok = 94/num_threads_b;
        Znak_his_prz[] NewThr_B = new Znak_his_prz[num_threads];

        for (int i = 0; i < num_threads_b; i++) {
            if(num_threads_b == i-1)
            {
                NewThr_B[i] = new Znak_his_prz(i, obraz_1 , krok * i, 94);
                NewThr_B[i].start();
            }
            else
            {
                NewThr_B[i] = new Znak_his_prz(i, obraz_1 , krok * i, krok * i +krok);
                NewThr_B[i].start();
            }
        }


        for (int i = 0; i < num_threads_b; i++) {
            try {
                NewThr_B[i].join();
                if (Thread.interrupted()) {
                    throw new InterruptedException();
                }
            } catch (InterruptedException e) {}
        }

    }

}

