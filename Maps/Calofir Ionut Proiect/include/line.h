#ifndef LINE_H
#define LINE_H

#include "region.h"

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

#endif
