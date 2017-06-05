#ifndef MYMAP_H
#define MYMAP_H

#include "myVector.h"
#include "vector_template.h"
#include "region.h"
#include "line.h"
#include "tree.h"
#include "obliquely.h"
#include "simple_graph.h"
#include "complete_graph.h"
#include <iostream>

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

#endif
