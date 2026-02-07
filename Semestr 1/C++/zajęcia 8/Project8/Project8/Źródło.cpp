#include <iostream>
#include <cstdio>
#include <ctime>
#include <string>
void zadanie1(int rozmiar);
void zadanie1_czy();
void zadanie1_stale_wartosci();
void zadanie1_wybrane_wartosci();
void bubble(int rozmiar, int* tab);
void quick_sort(int* tab, int lewy, int prawy);
void swap(int* a, int* b);
void heapify(int arr[], int N, int i);
void heapSort(int arr[], int N);
void selectionSort(int arr[], int n);
void zadanie2();
/*
void zadanie3();
void zadanie4();*/

using namespace std;

int main()
{
    int zadanie;

    std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "Zadanie 1 - Sortowanie - czas" << std::endl << "Zadanie 2 - Palindromy" << std::endl;
    std::cin >> zadanie;

    while (zadanie != 0)
    {
        switch (zadanie)
        {
        case 1:
        {
            zadanie1_czy();
            std::cout << std::endl << std::endl;
            break;
        }
        case 2:
        {
            zadanie2();
            std::cout << std::endl << std::endl;
            break;
        }/*
        case 3:
        {
            zadanie3();
            std::cout << std::endl << std::endl;
            break;
        }
        case 4:

        {
            zadanie4();
            std::cout << std::endl << std::endl;
            break;
        }*/
        }
        std::cout << "Wybor zadan" << std::endl << "0-wyjscie" << std::endl << "Zadanie 1 - Sortowanie - czas" << std::endl << "Zadanie 2 - Palindromy" << std::endl;
        std::cin >> zadanie;
    }
    return 0;
}

void zadanie1(int rozmiar)
{
    int czy_m;
    cout << "1-wszystkie typy sortowanie  2-Quick i Heap (bez Bubble i Selection)" << endl;
    cin >> czy_m;

    int* tab;
    tab = new int[rozmiar];

    for (int i = 0; i < rozmiar; i++)
    {
        srand((unsigned)time(0));
        tab[i] = (rand() % 1000);
    }


    int* copy_tab;
    copy_tab = new int[rozmiar];

    for (int i = 0; i < rozmiar; i++)
        copy_tab[i] = tab[i];

    clock_t start;

    if (czy_m == 1)
    {
        start = clock();
        bubble(rozmiar, copy_tab);
        cout << "Czas sortowania za pomoca Bubble sort: " << clock() - start << "ms" << endl;
        for (int i = 0; i < rozmiar; i++)
        {
            copy_tab[i] = tab[i];
        }
    }
    ////////////////////
    start = clock();
    quick_sort(copy_tab, 0, rozmiar - 1);
    cout << "Czas sortowania za pomoca Quick sort: " << clock() - start << "ms" << endl;
    for (int i = 0; i < rozmiar; i++)
    {
        copy_tab[i] = tab[i];
    }
    ////////////////////
    start = clock();
    heapSort(copy_tab, rozmiar);
    cout << "Czas sortowania za pomoca Heap sort: " << clock() - start << "ms" << endl;
    for (int i = 0; i < rozmiar; i++)
    {
        copy_tab[i] = tab[i];
    }
    ////////////////////
    if (czy_m == 1)
    {
        start = clock();
        selectionSort(copy_tab, rozmiar);
        cout << "Czas sortowania za pomoca Selection sort: " << clock() - start << "ms" << endl;
        for (int i = 0; i < rozmiar; i++)
        {
            copy_tab[i] = tab[i];
        }
    }
    ////////////////////

}

void bubble(int rozmiar, int* tab)
{
    int i, j;
    for (i = 0; i < rozmiar - 1; i++)

        // Last i elements are already in place
        for (j = 0; j < rozmiar - i - 1; j++)
        {
            if (tab[j] > tab[j + 1])
            {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j] = temp;
            }
        }
}

void quick_sort(int* tab, int lewy, int prawy)
{
    if (prawy <= lewy) return;

    int i = lewy - 1, j = prawy + 1,
        pivot = tab[(lewy + prawy) / 2]; //wybieramy punkt odniesienia

    while (1)
    {
        //szukam elementu wiekszego lub rownego piwot stojacego
        //po prawej stronie wartosci pivot
        while (pivot > tab[++i]);

        //szukam elementu mniejszego lub rownego pivot stojacego
        //po lewej stronie wartosci pivot
        while (pivot < tab[--j]);

        //jesli liczniki sie nie minely to zamieñ elementy ze soba
        //stojace po niewlasciwej stronie elementu pivot
        if (i <= j)
            //funkcja swap zamienia wartosciami tab[i] z tab[j]
            swap(tab[i], tab[j]);
        else
            break;
    }

    if (j > lewy)
        quick_sort(tab, lewy, j);
    if (i < prawy)
        quick_sort(tab, i, prawy);
}

void swap(int* a, int* b)
{

    int temp = *a;

    *a = *b;

    *b = temp;
}

void heapify(int arr[], int N, int i)
{
    // Find largest among root, left child and right child

    // Initialize largest as root
    int largest = i;

    // left = 2*i + 1
    int left = 2 * i + 1;

    // right = 2*i + 2
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])

        largest = left;

    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])

        largest = right;

    // Swap and continue heapifying if root is not largest
    // If largest is not root
    if (largest != i) {

        swap(&arr[i], &arr[largest]);

        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{

    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)

        heapify(arr, N, i);

    // Heap sort
    for (int i = N - 1; i >= 0; i--) {

        swap(&arr[0], &arr[i]);

        // Heapify root element to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++)
    {

        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(&arr[min_idx], &arr[i]);
    }
}

void zadanie2()
{
    cout << "Podaj slowo(spacje zostana pominiente): ";
    string slowo_2;
    string slowo_1;
    char* slowo;
    cin >> slowo_1;
    getline(cin, slowo_2);      ////// Nie umia³em wczytac calego wyrazu razem ze spacjami wiec wymyslilem taki rozwiazanie
    int j_1 = slowo_1.length();
    int j_2 = slowo_2.length();
    slowo = new char[j_1+j_2];
    for (int a = 0; a < j_1; a++)
    {
        slowo[a] = slowo_1[a];
    }
    for (int a = 0; a < j_2; a++)
    {
        slowo[j_1+a] = slowo_2[a];
    }
    int j = j_1 + j_2-1;
    int i = 0;
    bool czy_p = 1;
    while (i<j)
    {
        if (slowo[i] == ' ')
        {
            i++;
        }
        else if (slowo[j] == ' ')
        {
            j--;
        }
        else
        {
            if (slowo[i] != slowo[j])
            {
                czy_p = 0;
                break;
            }
            else
            {
                i++;
                j--;
            }
        }
    }
    if (czy_p == 1)
    {
        cout << "Podany wyraz jest palindromem" << endl;
    }
    else
    {
        cout << "Podany wyraz nie jest palindromem" << endl;
    }
    delete[] slowo;
}

void zadanie1_czy()
{
    cout << "Zadane dlugosci(1) czy wlasne dlugosci(2)" << endl;
    int czy;
    cin >> czy;
    if (czy == 1)
    {
        zadanie1_stale_wartosci();
    }
    else if (czy == 2)
    {
        zadanie1_wybrane_wartosci();
    }
}
void zadanie1_stale_wartosci()
{
    int rozmiar = 0;
    cout << "Podaj rozmiar(0-1000; 1-10000; 2-30000; 3-60000; 4-100000)" << endl;
    int jaki_rozmiar = 0;
    while (rozmiar == 0)
    {
        cin >> jaki_rozmiar;
        if (jaki_rozmiar<5 && jaki_rozmiar >-1)
        {
            switch (jaki_rozmiar)
            {
            case 0:
            {
                rozmiar = 1000;
                break;
            }
            case 1:
            {
                rozmiar = 10000;
                break;
            }
            case 2:
            {
                rozmiar = 30000;
                break;
            }
            case 3:
            {
                rozmiar = 60000;
                break;
            }
            case 4:
            {
                rozmiar = 100000;
                break;
            }
            }
        }
        else
        {
            cout << "Niewalsciwy rozmiar" << endl;
        }
    }
    zadanie1(rozmiar);
}


void zadanie1_wybrane_wartosci()
{
    cout << "Podaj rozmiar";
    int rozmiar;
    cin >> rozmiar;
    zadanie1(rozmiar);
}