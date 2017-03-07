#ifndef GET_CITIES_SIZE_H
#define GET_CITIES_SIZE_H

class get_cities_size
{
    static int N;
    static void get_N();

public:
    static int cities_size();
};

int get_cities_size::N = 0;

void get_cities_size::get_N() // calculez cate orase am in baza de date
{
    if (N != 0)
        return;

    ifstream fin("cities.txt"); // baza de date

    char *str;
    str = new char[101];

    fin.getline(str + 1, 101);
    int lg = strlen(str + 1);

    int nr = 0;
    for (int i = 1; i <= lg; ++i)
        nr = nr * 10 + (int)(str[i] - '0');

    fin.close();

    N = nr;
}

int get_cities_size::cities_size() // returnez numarul de orase din baza de date
{
    get_N();
    return N;
}

#endif