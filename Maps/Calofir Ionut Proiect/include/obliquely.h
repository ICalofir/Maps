#ifndef OBLIQUELY_H
#define OBLIQUELY_H

#include "region.h"

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

#endif
