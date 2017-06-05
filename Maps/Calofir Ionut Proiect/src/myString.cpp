#include "myString.h"

pointerS::pointerS()
{
    info = '0';
    next = nullptr;
}

void pointerS::set_info(char x)
{
    info = x;
}

void pointerS::set_next(pointerS *nod)
{
    next = nod;
}

char pointerS::get_info()
{
    return info;
}

pointerS *pointerS::get_next()
{
    return next;
}

myString::myString()
{
    start = nullptr;
    now = nullptr;
    sSize = 0;
}

myString::~myString()
{
    if (sSize >= 1)
    {
        pointerS *nod = start, *nodAux = start;
        for (int i = 1; i <= sSize - 1; ++i)
        {
            nod = nod->get_next();
            delete nodAux;
            nodAux = nod;
        }
        delete nodAux;
    }
}

void myString::push_back(char x)
{
    ++sSize;

    pointerS *nod = new pointerS;
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

char myString::operator [] (int pos) const
{
    pointerS *nod = start;
    for (int i = 1; i <= pos - 1; ++i)
        nod = nod->get_next();

    return nod->get_info();
}

int myString::size() const
{
    return sSize;
}

char *myString::getString()
{
    char *sir;
    sir = new char[sSize];

    pointerS *nod = start;
    for (int i = 1; i <= sSize - 1; ++i)
    {
        sir[i - 1] = nod->get_info();
        nod = nod->get_next();
    }

    sir[sSize - 1] = nod->get_info();
    sir[sSize] = 0;

    return sir;
}
