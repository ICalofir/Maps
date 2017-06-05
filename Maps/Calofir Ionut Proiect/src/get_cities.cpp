#include "get_cities.h"

get_cities::get_cities() // preiau toate orasele cu coordonatele X si Y din baza de date(fisierul cities.txt)
{
    S = new myString[get_cities_size::cities_size() + 1];

    ifstream fin("cities.txt");

    char *str;
    str = new char[101];

    fin.getline(str + 1, 101);
    for (int nS = 1; nS <= get_cities_size::cities_size(); ++nS)
    {
        fin.getline(str + 1, 101);
        int lg = strlen(str + 1);

        int i = 1, nr, sign;

        while (((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) && str[i] != ' ')
        {
            S[nS].push_back(str[i]);
            ++i;
        }
        ++i;

        if (str[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else
            sign = 1;

        nr = 0;
        while (str[i] >= '0' && str[i] <= '9' && str[i] != ' ')
        {
            nr = nr * 10 + (int)(str[i] - '0');
            ++i;
        }
        ++i;
        X.push_back(nr * sign);

        if (str[i] == '-')
        {
            sign = -1;
            ++i;
        }
        else
            sign = 1;

        nr = 0;
        while (str[i] >= '0' && str[i] <= '9' && i <= lg)
        {
            nr = nr * 10 + (int)(str[i] - '0');
            ++i;
        }
        Y.push_back(nr * sign);
    }
}

get_cities::~get_cities()
{
    delete[] S;
}

int get_cities::nr_city(char *str) // functia primeste ca parametru numele unui oras si returneaza al catelea oras e in baza de date
{
    int lg = strlen(str);

    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        if (lg != S[i].size())
            continue;

        bool ok = true;
        for (int j = 1; j <= S[i].size() && ok; ++j)
            if (str[j - 1] != S[i][j])
                ok = false;

        if (ok)
            return i;
    }

    return 0;
}

int get_cities::get_dist(int A, int B) // distanta dintre doua orase
{
    int d = sqrt((X[B] - X[A]) * (X[B] - X[A]) + (Y[B] - Y[A]) * (Y[B] - Y[A]));
    return d;
}
