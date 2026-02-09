import java.util.concurrent.ForkJoinPool;
import java.util.concurrent.RecursiveTask;

class DivideTask extends RecursiveTask<int[]>
{

    int[] arrayToDivide;

    public DivideTask(int[] arrayToDivide)
    {
        this.arrayToDivide = arrayToDivide;
    }

    protected int[] compute() {

        // .......
        int a = arrayToDivide.length/2;
        int[] ar1 = new int[a];
        for(int i=0; i<a; i++)
        {
            ar1[i] = arrayToDivide[i];
        }

        a = arrayToDivide.length/2;
        int[] ar2 = new int[a];
        for(int i=0; i<a; i++)
        {
            ar2[i] = arrayToDivide[i];
        }


        DivideTask task1 = new DivideTask(ar1);
        DivideTask task2 = new DivideTask(ar2);

        // .......

        //Wait for results from both tasks
        int[] tab1 = task1.join();
        int[] tab2 = task2.join();
        int[] scal_tab = new int[tab1.length+tab2.length];
        scal_tab(tab1, tab2, scal_tab);
        return scal_tab;
    }

    private void scal_tab(
            int[] tab1,
            int[] tab2,
            int[] scal_tab)
    {

        int i = 0, j = 0, k = 0;

        while ((i < tab1.length) && (j < tab2.length)) {

            if (tab1[i] < tab2[j]) {
                scal_tab[k] = tab1[i++];
            } else {
                scal_tab[k] = tab2[j++];
            }

            k++;
        }

        if (i == tab1.length) {

            for (int a = j; a < tab2.length; a++) {
                scal_tab[k++] = tab2[a];
            }

        } else {

            for (int a = i; a < tab1.length; a++) {
                scal_tab[k++] = tab1[a];
            }

        }
    }

}
