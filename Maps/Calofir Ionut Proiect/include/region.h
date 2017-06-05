#ifndef REGION_H
#define REGION_H

#include "myVector.h"
#include "myString.h"
#include "get_cities.h"
#include "get_cities_size.h"
#include "cstring"

class region : public get_cities
{
protected:
    const int INF = 0x3f3f3f3f;
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

#endif
