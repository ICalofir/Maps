// acest program imi genereaza coordonatele X si Y pentru un oras introdus prin longitudine si latitudine, practic mi-am creat o baza de date cu orasele si coordonatele lor
#include <iostream>
#include <fstream>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// mi-am creat clase pentru stringuri si vector salvate prin liste inlantuite, asemanatoare cu cele din stl
#include "string.h"
#include "vector.h"
#include "create_cities.h"

int main()
{
    int nS = 0;
    myVector X, Y;
    myString *S;

    S = new myString[101];

    ifstream fin("cities.txt");

    char *sir;
    sir = new char[101];

    fin.getline(sir + 1, 101); // citesc numarul de orase

    while (fin.getline(sir + 1, 101)) // aici preiau orasele deja existente in fisierul cities.txt ca sa nu le pierd cand mai vreau sa adaug orase noi
    {
        ++nS;
        int lg = strlen(sir + 1);

        int i = 1, nr, sign;

        while (((sir[i] >= 'a' && sir[i] <= 'z') || (sir[i] >= 'A' && sir[i] <= 'Z')) && sir[i] != ' ')
        {
            S[nS].push_back(sir[i]);
            ++i;
        }
        ++i;

        if (sir[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else
            sign = 1;

        nr = 0;
        while (sir[i] >= '0' && sir[i] <= '9' && sir[i] != ' ')
        {
            nr = nr * 10 + (int)(sir[i] - '0');
            ++i;
        }
        ++i;
        X.push_back(nr * sign);

        if (sir[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else
            sign = 1;

        nr = 0;
        while (sir[i] >= '0' && sir[i] <= '9' && i <= lg)
        {
            nr = nr * 10 + (int)(sir[i] - '0');
            ++i;
        }
        Y.push_back(nr * sign);
    }

    delete[] sir;

    fin.close();

    ofstream fout("cities.txt");

    while (true)
    {
        char *sir;
        sir = new char[101];
        cout << "Doriti sa introduceti un oras? (1/0): ";
        cin.getline(sir + 1, 101);

        if (strlen(sir + 1) == 1 && sir[1] == '0')
            break;

        create_cities ob;
        cin >> ob;
        ob.setX();
        ob.setY();

        bool ok = true; // verific pentru orasul curent daca il am deja adaugat in baza de date, daca nu il am, atunci il adaug
        for (int i = 1; i <= nS && ok; ++i)
        {
            if (ob.nameSize() != S[i].size())
                continue;

            int j = 1;
            for (int j = 1; j <= ob.nameSize(); ++j)
                if (ob.getC(j) != S[i][j])
                    break;

            if (j == ob.nameSize() + 1)
                ok = false;
        }

        if (ok)
        {
            ++nS;
            for (int i = 1; i <= ob.nameSize(); ++i)
                S[nS].push_back(ob.getC(i));
            X.push_back(ob.getX());
            Y.push_back(ob.getY());
        }

        delete[] sir;
    }

    fout << nS << '\n';
    for (int i = 1; i <= nS; ++i)
    {
        for (int j = 1; j <= S[i].size(); ++j)
            fout << S[i][j];
        fout << ' ' << X[i] << ' ' << Y[i] << '\n';
    }

    fout.close();

    delete[] S;

    return 0;
}
