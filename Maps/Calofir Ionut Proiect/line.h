#ifndef LINE_H
#define LINE_H

class line : public region
{
    void line_graph(int, int); // calculez distanta minima intr-un graf linie
    void add_citiesR(int, int);
    int get_minR(int, int);
    void addS(char *);
    void actualize_dist(); // actualizez distanta de la fiecare oras la toate celelalte dintr-o regiune
public:
	void operator = (const line &);
	int isEqual(char *);
};

void line::operator = (const line &ob)
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

int line::isEqual(char *sir)
{
	int lg = strlen(sir);

	if (lg != S.size())
		return 0;

	for (int i = 1; i <= S.size(); ++i)
		if (sir[i - 1] != S[i])
			return 0;

	return 1;
}

void line::addS(char *sir)
{
	int lg = strlen(sir);
	for (int i = 0; i <= lg - 1; ++i)
		S.push_back(sir[i]);
}

void line::line_graph(int nodInit, int nod)
{
    for (int i = 1; i <= V[nod].size(); ++i)
    {
        int vecin = V[nod][i];
        if (!used[vecin])
        {
            used[vecin] = true;
            D[nodInit][vecin] = D[nodInit][nod] + get_dist(nod, vecin);
            line_graph(nodInit, vecin);
        }
    }
}

void line::add_citiesR(int A, int B)
{
    bool ok = true;
    for (int i = 1; i <= V[A].size(); ++i)
        if (V[A][i] == B)
            ok = false;

    if (ok)
        V[A].push_back(B);
}

int line::get_minR(int A, int B)
{
    return D[A][B];
}

void line::actualize_dist() // 1 - linie, 2 - arbore, 3 - dag, 4 - graf normal, 5 - graf complet
{
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        for (int j = 1; j <= get_cities_size::cities_size(); ++j)
            D[i][j] = INF;
        D[i][i] = 0;

        for (int j = 1; j <= get_cities_size::cities_size(); ++j)
            used[j] = false;

        line_graph(i, i);
    }
}

#endif