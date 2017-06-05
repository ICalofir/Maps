#ifndef GET_CITIES_H
#define GET_CITIES_H

#include "myVector.h"
#include "myString.h"
#include "get_cities_size.h"
#include <cmath>

class get_cities
{
    myVector X, Y;
    myString *S;

public:
    get_cities();
    ~get_cities();
    int get_dist(int, int);
    int nr_city(char *);
};

#endif
