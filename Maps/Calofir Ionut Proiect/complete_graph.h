#ifndef COMPLETE_GRAPH_H
#define COMPLETE_GRAPH_H

class complete_graph : public region
{
	void complete_graph_dist(int);
    void add_citiesR(int, int);
    int get_minR(int, int);
    void addS(char *);
    void actualize_dist(); // actualizez distanta de la fiecare oras la toate celelalte dintr-o regiune
public:
	void operator = (const complete_graph &);
	int isEqual(char *);
};

void complete_graph::operator = (const complete_graph &ob)
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

int complete_graph::isEqual(char *sir)
{
	int lg = strlen(sir);

	if (lg != S.size())
		return 0;

	for (int i = 1; i <= S.size(); ++i)
		if (sir[i - 1] != S[i])
			return 0;

	return 1;
}

void complete_graph::complete_graph_dist(int nodInit)
{
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
        D[nodInit][i] = get_dist(nodInit, i);
}

void complete_graph::addS(char *sir)
{
	int lg = strlen(sir);
	for (int i = 0; i <= lg - 1; ++i)
		S.push_back(sir[i]);
}

void complete_graph::add_citiesR(int A, int B)
{
    bool ok = true;
    for (int i = 1; i <= V[A].size(); ++i)
        if (V[A][i] == B)
            ok = false;

    if (ok)
        V[A].push_back(B);
}

int complete_graph::get_minR(int A, int B)
{
    return D[A][B];
}

void complete_graph::actualize_dist() // 1 - linie, 2 - arbore, 3 - dag, 4 - graf normal, 5 - graf complet
{
    for (int i = 1; i <= get_cities_size::cities_size(); ++i)
    {
        for (int j = 1; j <= get_cities_size::cities_size(); ++j)
            D[i][j] = INF;
        D[i][i] = 0;

        complete_graph_dist(i);
    }
}

#endif
