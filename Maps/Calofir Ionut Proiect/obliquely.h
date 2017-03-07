#ifndef OBLIQUELY_H
#define OBLIQUELY_H

class obliquely : public region
{
	void bellman(int); // calculez cu bellman distanta minima intr-un graf normal sau intr-un dag sau intr-un arbore
    void add_citiesR(int, int);
    int get_minR(int, int);
    void addS(char *);
    void actualize_dist(); // actualizez distanta de la fiecare oras la toate celelalte dintr-o regiune
public:
	void operator = (const obliquely &);
	int isEqual(char *);
};

void obliquely::operator = (const obliquely &ob)
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

int obliquely::isEqual(char *sir)
{
	int lg = strlen(sir);

	if (lg != S.size())
		return 0;

	for (int i = 1; i <= S.size(); ++i)
		if (sir[i - 1] != S[i])
			return 0;

	return 1;
}

void obliquely::bellman(int nodInit)
{
    myVector Q;
    int first = 1;
    Q.push_back(nodInit);

    while (first <= Q.size())
    {
        int now = Q[first];
        ++first;

        for (int i = 1; i <= V[now].size(); ++i)
        {
            int vecin = V[now][i];
            if (D[nodInit][now] + get_dist(now, vecin) < D[nodInit][vecin])
            {
                D[nodInit][vecin] = D[nodInit][now] + get_dist(now, vecin);
                Q.push_back(vecin);
            }
        }
    }
}

void obliquely::addS(char *sir)
{
	int lg = strlen(sir);
	for (int i = 0; i <= lg - 1; ++i)
		S.push_back(sir[i]);
}

void obliquely::add_citiesR(int A, int B)
{
    bool ok = true;
    for (int i = 1; i <= V[A].size(); ++i)
        if (V[A][i] == B)
            ok = false;

    if (ok)
        V[A].push_back(B);
}

int obliquely::get_minR(int A, int B)
{
    return D[A][B];
}

void obliquely::actualize_dist() // 1 - linie, 2 - arbore, 3 - dag, 4 - graf normal, 5 - graf complet
{
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        for (int j = 1; j <= get_cities_size::cities_size(); ++j)
            D[i][j] = INF;
        D[i][i] = 0;

        bellman(i);
    }
}

#endif
