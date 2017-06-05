#ifndef CREATE_CITIES_H
#define CREATE_CITIES_H

#include "myString.h"
#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class create_cities
{
    const double PI = M_PI;
    const double R = 6371.0;

    myString name;
    int x, y;
    double lati, longi;

public:
    friend istream &operator >> (istream &, create_cities &); //friend trateaza functia ca pe una exterioara clasei, dar poate sa foloseasca variabilele private si protected ale clasei
    friend ostream &operator << (ostream &, create_cities);
    void setX();
    void setY();
    void pushC(char);
    int getX();
    int getY();
    char getC(int pos);
    int nameSize();
    void write();
};

#endif
