#include "myVector.h"

pointerV::pointerV()
{
    info = 0;
    next = nullptr;
}

void pointerV::set_info(int x)
{
    info = x;
}

void pointerV::set_next(pointerV *nod)
{
    next = nod;
}

int pointerV::get_info()
{
    return info;
}

pointerV *pointerV::get_next()
{
    return next;
}

myVector::myVector()
{
    start = nullptr;
    now = nullptr;
    vSize = 0;
}

myVector::~myVector()
{
    if (vSize >= 1)
    {
        pointerV *nod = start, *nodAux = start;
        for (int i = 1; i <= vSize - 1; ++i)
        {
            nod = nod->get_next();
            delete nodAux;
            nodAux = nod;
        }
        delete nodAux;
    }
}

void myVector::push_back(int x)
{
    ++vSize;

    pointerV *nod = new pointerV;
    nod->set_info(x);

    if (now == nullptr)
    {
        start = nod;
        now = nod;
        return;
    }
    now->set_next(nod);
    now = nod;
}

int myVector::operator [] (int pos)
{
    pointerV *nod = start;
    for (int i = 1; i <= pos - 1; ++i)
        nod = nod->get_next();

    return nod->get_info();
}

int myVector::size()
{
    return vSize;
}
