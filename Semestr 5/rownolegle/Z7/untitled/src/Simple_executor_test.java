import java.util.concurrent.*;
import java.util.ArrayList;
import java.util.List;
import java.util.concurrent.Executors;

public class Simple_executor_test {

    private static final int NTHREADS = 5;

    public static void main(String[] args) {

        Counter counter = new Counter();
        ExecutorService executor = Executors.newFixedThreadPool(NTHREADS);

        double dx = 0.0001;
        double pi = Math.PI;
        int ilosc = 50;
        List<Future<Double>> flist = new ArrayList<>();
        pi = pi/ (double) ilosc;

        for (int i = 0; i < ilosc; i++)
        {
            Callable worker = new Calka_callable(i*pi, (i+1)*pi, dx);
            flist.add(executor.submit(worker));
        }
        executor.shutdown();
        while (!executor.isTerminated()) {}

        double wyn =0;
        try {
            for (Future<Double> f : flist) {
                wyn += f.get();
            }
        }
        catch (Exception e) {}
        System.out.println("Wynik: " + wyn);
    }
}
