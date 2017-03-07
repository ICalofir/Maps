#ifndef REGION_H
#define REGION_H

class region : public get_cities
{
protected:
    myVector *V;
    bool *used;
    int **D; // D[i][j] - reprezinta distanta minima de la orasul i la orasul j
    myString S;
    int check_linie();
    int check_arbore();
    int check_dag();
    int check_graf_complet();
    void dfs(int);
public:
    void operator = (const region &);
    region();
    ~region();
    virtual void add_citiesR(int, int) = 0;
    virtual int get_minR(int, int) = 0;
    virtual void addS(char *) = 0;
    int get_type(); // actualizez tipul regiunii
    virtual void actualize_dist() = 0; // actualizez distanta de la fiecare oras la toate celelalte dintr-o regiune
};

void region::operator = (const region &ob)
{
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
        for (int j = 1; j <= get_cities_size::cities_size(); ++j)
            D[i][j] = ob.D[i][j];
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
        used[i] = ob.used[i];
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
        for (int j = 1; j <= ob.V[i].size(); ++j)
            V[i].push_back(ob.V[i][j]);
    for (int i = 1; i <= ob.S.size(); ++i)
        S.push_back(ob.S[i]);
}

region::region() : get_cities()
{
    V = new myVector[get_cities_size::cities_size() + 1];
    used = new bool[get_cities_size::cities_size() + 1];
    D = new int *[get_cities_size::cities_size() + 1];
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        used[i] = false;
        D[i] = new int[get_cities_size::cities_size() + 1];
        for (int j = 1; j <= get_cities_size::cities_size(); ++j)
            D[i][j] = 0;
    }
}

region::~region()
{
    delete[] V;
    delete[] used;
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
        delete[] D[i];
    delete[] D;
}

void region::dfs(int nod)
{
    for (int i = 1; i <= V[nod].size(); ++i)
    {
        if (!used[V[nod][i]])
        {
            used[V[nod][i]] = true;
            dfs(V[nod][i]);
        }
    }
}

int region::check_dag()
{
    bool ok;
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        for (int j = 1; j <= V[i].size(); ++j)
        {
            ok = true;
            for (int k = 1; k <= V[V[i][j]].size(); ++k)
                if (i == V[V[i][j]][k]) // daca descopar o strada care e bidirectionala inseamna ca nu e dag
                    ok = false;

            if (!ok)
                return 0;
        }
    }

    return 1;
}

int region::check_linie()
{
    bool ok;
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        for (int j = 1; j <= V[i].size(); ++j)
        {
            ok = false;
            for (int k = 1; k <= V[V[i][j]].size(); ++k)
                if (i == V[V[i][j]][k])
                    ok = true;

            if (!ok) // daca descopar o strada care e unidirectionala inseamna ca nu e graf linie
                return 0;
        }
    }

    int nod = 0;
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        if (V[i].size() == 1)
            ++nod;
        if (V[i].size() > 2)
            return 0;
    }

    if (nod % 2 == 0 && nod != 0)
        return 1;

    return 0;
}

int region::check_arbore()
{
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
        used[i] = false;

    bool ok;
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        for (int j = 1; j <= V[i].size(); ++j)
        {
            ok = false;
            for (int k = 1; k <= V[V[i][j]].size(); ++k)
                if (i == V[V[i][j]][k])
                    ok = true;

            if (!ok) // daca descopar o strada care e unidirectionala inseamna ca nu e arbore
                return 0;
        }
    }

    int m = 0, isConex = 0, n = 0;

    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        if (V[i].size() == 0)
            continue;

        if (!used[i])
        {
            ++isConex;
            used[i] = true;
            dfs(i);
        }
    }

    if (isConex > 1)
        return 0;

    int sum = 0;
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        if (V[i].size() != 0)
            ++n;
        sum += V[i].size();
    }

    if (sum == 2 * (n - 1))
        return 1;

    return 0;
}

int region::check_graf_complet()
{
    bool ok;
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        for (int j = 1; j <= V[i].size(); ++j)
        {
            ok = false;
            for (int k = 1; k <= V[V[i][j]].size(); ++k)
                if (i == V[V[i][j]][k])
                    ok = true;

            if (!ok) // daca descopar o strada care e unidirectionala inseamna ca nu e graf complet
                return 0;
        }
    }

    int n = 0;
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        if (V[i].size() != 0)
            ++n;
    }
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        if (V[i].size() != 0 && V[i].size() != n - 1)
            return 0;
    }

    return 1;
}

int region::get_type() // 1 - linie, 2 - arbore, 3 - dag, 4 - graf normal, 5 - graf complet
{
    if (check_dag())
        return 3;
    else if (check_linie())
        return 1;
    else if (check_arbore())
        return 2;
    else if (check_graf_complet())
        return 5;

    return 4;
}

#endif
