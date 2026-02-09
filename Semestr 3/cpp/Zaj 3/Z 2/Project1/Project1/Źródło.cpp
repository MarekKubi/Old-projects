#include <iostream>
using namespace std;

int main()
{
    int x, tab[6];
    cout << "Jaki nr?" << endl;
    cin >> x;

    for (int i = 0; i < 6; i++)
    {
        cout << "Twoje zadanie z listy nr " << i + 1 << " to: ";
        if (i == 0)
        {
            tab[i] = x % 71;
            cout << x % 71 << endl;

        }
        else if (i == 1)
        {
            tab[i] = (x + 15) % 77;
            cout << tab[i] << endl;
        }
        else if (i == 2)
        {
            tab[i] = (x + 30) % 43;
            cout << tab[i] << endl;
        }
        else if (i == 3)
        {
            tab[i] = (x + 45) % 74;
            cout << tab[i] << endl;
        }
        else if (i == 4)
        {
            tab[i] = (x + 60) % 32;
            cout << tab[i] << endl;
        }
        else if (i == 5)
        {
            tab[i] = x % 70;
            cout << tab[i] << endl;
        }
    }

    for (int i = 0; i < 6; i++)
    {
        cout << endl << "Twoi przyjaciele z listy nr " << i + 1 << " to: ";

        if (i == 0)
        {
            for (int j = 1; j < 138; j++)
            {
                if (tab[i] == j % 71 && j != x)
                {
                    cout << j << " ";
                }
            }
        }
        else if (i == 1)
        {
            for (int j = 1; j < 138; j++)
            {
                if (tab[i] == (j + 15) % 77 && j != x)
                {
                    cout << j << " ";
                }
            }
        }
        else if (i == 2)
        {
            for (int j = 1; j < 138; j++)
            {
                if (tab[i] == (j + 30) % 43 && j != x)
                {
                    cout << j << " ";
                }
            }
        }
        else if (i == 3)
        {
            for (int j = 1; j < 138; j++)
            {
                if (tab[i] == (j + 45) % 74 && j != x)
                {
                    cout << j << " ";
                }
            }
        }
        else if (i == 4)
        {
            for (int j = 1; j < 138; j++)
            {
                if (tab[i] == (j + 60) % 32 && j != x)
                {
                    cout << j << " ";
                }
            }
        }
        else if (i == 5)
        {
            for (int j = 1; j < 138; j++)
            {
                if (tab[i] == j % 70 && j != x)
                {
                    cout << j << " ";
                }
            }
        }

        cout << endl;
    }



    return(0);
}