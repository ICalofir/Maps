#ifndef MAP_H
#define MAP_H

class Map
{
    myVectorT<line> L;
    myVectorT<tree> T;
    myVectorT<obliquely> O;
    myVectorT<simple_graph> SG;
    myVectorT<complete_graph> CG;
    int get_min_all(region &, int, int);
    void add_cities_all(region &, int, int);
    void addS_all(region &, char *);
    void actualize_all(region &);
    void actualize(region &, int);
    void do_copy(region &n, region &);
public:
    void add_region(char *);
    int get_min(int, int, char *);
    void add_cities(int, int, char *);
};

void Map::addS_all(region &ob, char *sir)
{
    ob.addS(sir);
}

void Map::add_region(char *sir)
{
    int pos = 0;

    for (int i = 1; i <= L.size() && !pos; ++i)
        if (L[i].isEqual(sir))
            pos = i;

    for (int i = 1; i <= T.size() && !pos; ++i)
        if (T[i].isEqual(sir))
            pos = i;

    for (int i = 1; i <= O.size() && !pos; ++i)
        if (O[i].isEqual(sir))
            pos = i;

    for (int i = 1; i <= SG.size() && !pos; ++i)
        if (SG[i].isEqual(sir))
            pos = i;

    for (int i = 1; i <- CG.size() && !pos; ++i)
        if (CG[i].isEqual(sir))
            pos = i;

    if (pos != 0)
    {
        cout << "Regiunea exista deja!\n";
        return;
    }

    line *obL = new line;
    L.push_back(*obL);
    addS_all(L[L.size()], sir);

    delete obL;
}

void Map::actualize_all(region &ob)
{
    ob.actualize_dist();
}

void Map::add_cities_all(region &ob, int A, int B)
{
    ob.add_citiesR(A, B);
}

void Map::do_copy(region &nowOb, region &ob)
{
    nowOb = ob;
}

void Map::actualize(region &ob, int type)
{
    if (type == 1)
    {
        line *nowOb = new line;
        do_copy(*nowOb, ob);
        L.push_back(*nowOb);
        actualize_all(L[L.size()]);

        delete nowOb;
    }
    else if (type == 2)
    {
        tree *nowOb = new tree;
        do_copy(*nowOb, ob);
        T.push_back(*nowOb);
        actualize_all(T[T.size()]);

        delete nowOb;
    }
    else if (type == 3)
    {
        obliquely *nowOb = new obliquely;
        do_copy(*nowOb, ob);
        O.push_back(*nowOb);
        actualize_all(O[O.size()]);

        delete nowOb;
    }
    else if (type == 4)
    {
        simple_graph *nowOb = new simple_graph;
        do_copy(*nowOb, ob);
        SG.push_back(*nowOb);
        actualize_all(SG[SG.size()]);

        delete nowOb;
    }
    else
    {
        complete_graph *nowOb = new complete_graph;
        do_copy(*nowOb, ob);
        CG.push_back(*nowOb);
        actualize_all(CG[CG.size()]);

        delete nowOb;
    }
}

void Map::add_cities(int A, int B, char *sir)
{
    int pos = 0;

    char c;
    cout << "Drumul este bidirectional? 1/0: ";
    cin >> c;

    for (int i = 1; i <= L.size() && !pos; ++i)
        if (L[i].isEqual(sir))
        {
            pos = i;

            if (c == '1')
            {
                add_cities_all(L[pos], A, B);
                add_cities_all(L[pos], B, A);
            }
            else
            {
                add_cities_all(L[pos], A, B);
            }

            int type = L[pos].get_type();
            actualize(L[pos], type);
            L.pop(pos);
        }

    for (int i = 1; i <= T.size() && !pos; ++i)
        if (T[i].isEqual(sir))
        {
            pos = i;

            if (c == '1')
            {
                add_cities_all(T[pos], A, B);
                add_cities_all(T[pos], B, A);
            }
            else
            {
                add_cities_all(T[pos], A, B);
            }

            int type = T[pos].get_type();
            actualize(T[pos], type);
            T.pop(pos);
        }

    for (int i = 1; i <= O.size() && !pos; ++i)
        if (O[i].isEqual(sir))
        {
            pos = i;

            if (c == '1')
            {
                add_cities_all(O[pos], A, B);
                add_cities_all(O[pos], B, A);
            }
            else
            {
                add_cities_all(O[pos], A, B);
            }

            int type = O[pos].get_type();
            actualize(O[pos], type);
            O.pop(pos);
        }

    for (int i = 1; i <= SG.size() && !pos; ++i)
        if (SG[i].isEqual(sir))
        {
            pos = i;

            if (c == '1')
            {
                add_cities_all(SG[pos], A, B);
                add_cities_all(SG[pos], B, A);
            }
            else
            {
                add_cities_all(SG[pos], A, B);
            }

            int type = SG[pos].get_type();
            actualize(SG[pos], type);
            SG.pop(pos);
        }

    for (int i = 1; i <= CG.size() && !pos; ++i)
        if (CG[i].isEqual(sir))
        {
            pos = i;

            if (c == '1')
            {
                add_cities_all(CG[pos], A, B);
                add_cities_all(CG[pos], B, A);
            }
            else
            {
                add_cities_all(CG[pos], A, B);
            }

            int type = CG[pos].get_type();
            actualize(CG[pos], type);
            CG.pop(pos);
        }

    if (pos == 0)
    {
        cout << "Regiunea introdusa nu exista!\n";
        return;
    }
}

int Map::get_min_all(region &ob, int A, int B)
{
    return ob.get_minR(A, B);
}

int Map::get_min(int A, int B, char *sir)
{
    int pos = 0;

    for (int i = 1; i <= L.size() && !pos; ++i)
        if (L[i].isEqual(sir))
        {
            pos = i;
            return get_min_all(L[pos], A, B);
        }

    for (int i = 1; i <= T.size() && !pos; ++i)
        if (T[i].isEqual(sir))
        {
            pos = i;
            return get_min_all(T[pos], A, B);
        }

    for (int i = 1; i <= O.size() && !pos; ++i)
        if (O[i].isEqual(sir))
        {
            pos = i;
            return get_min_all(O[pos], A, B);
        }

    for (int i = 1; i <= SG.size() && !pos; ++i)
        if (SG[i].isEqual(sir))
        {
            pos = i;
            return get_min_all(SG[pos], A, B);
        }

    for (int i = 1; i <= CG.size() && !pos; ++i)
        if (CG[i].isEqual(sir))
        {
            pos = i;
            return get_min_all(CG[pos], A, B);
        }

    return -1;
}

#endif
