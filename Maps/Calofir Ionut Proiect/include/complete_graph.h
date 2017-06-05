#ifndef COMPLETE_GRAPH_H
#define COMPLETE_GRAPH_H

#include "region.h"

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

#endif
