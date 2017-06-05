#include "vector_template.h"

template<class T>
pointerVT<T>::pointerVT()
{
    next = nullptr;
    prev = nullptr;
}

template<class T>
void pointerVT<T>::set_info(const T &x)
{
    info = x;
}

template<class T>
void pointerVT<T>::set_next(pointerVT *nod)
{
    next = nod;
}

template<class T>
void pointerVT<T>::set_prev(pointerVT *nod)
{
    prev = nod;
}

template<class T>
T &pointerVT<T>::get_info()
{
    return info;
}

template<class T>
pointerVT<T> *pointerVT<T>::get_next()
{
    return next;
}

template<class T>
pointerVT<T> *pointerVT<T>::get_prev()
{
    return prev;
}

template<class T>
myVectorT<T>::myVectorT()
{
    start = nullptr;
    now = nullptr;
    vSize = 0;
}

template<class T>
myVectorT<T>::~myVectorT()
{
    if (vSize >= 1)
    {
        pointerVT<T> *nod = start, *nodAux = start;
        for (int i = 1; i <= vSize - 1; ++i)
        {
            nod = nod->get_next();
            delete nodAux;
            nodAux = nod;
        }
        delete nodAux;
    };
}

template<class T>
void myVectorT<T>::push_back(const T &x)
{
    ++vSize;

    pointerVT<T> *nod = new pointerVT<T>;
    nod->set_info(x);

    if (start == nullptr)
    {
        start = nod;
        now = nod;
        return;
    }
    now->set_next(nod);
    nod->set_prev(now);
    now = nod;
}

template<class T>
void myVectorT<T>::pop(int pos)
{
    pointerVT<T> *nod = start;
    for (int i = 1; i <= pos - 1; ++i)
        nod = nod->get_next();

    if (vSize == 1)
    {
        --vSize;
        delete nod;
        start = nullptr;
        return;
    }

    if (pos == 1)
    {
        nod->get_next()->set_prev(nullptr);
        start = nod->get_next();
    }
    else if (pos == vSize)
    {
        nod->get_prev()->set_next(nullptr);
        now = nod->get_prev();
    }
    else
    {
        nod->get_prev()->set_next(nod->get_next());
        nod->get_next()->set_prev(nod->get_prev());
    }

    --vSize;
    delete nod;
}

template<class T>
T &myVectorT<T>::operator [] (int pos)
{
    pointerVT<T> *nod = start;
    for (int i = 1; i <= pos - 1; ++i)
        nod = nod->get_next();

    return nod->get_info();
}

template<class T>
int myVectorT<T>::size()
{
    return vSize;
}
