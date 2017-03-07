#ifndef VECTOR_TEMPLATE_H
#define VECTOR_TEMPALTE_H

template<class T>
class pointerVT
{
    T info;
    pointerVT *next, *prev;
public:
    pointerVT();
    void set_info(const T &);
    void set_next(pointerVT *);
    void set_prev(pointerVT *);
    T &get_info();
    pointerVT<T> *get_next();
    pointerVT<T> *get_prev();
};

template<class T>
pointerVT<T>::pointerVT()
{
    next = NULL;
    prev = NULL;
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
class myVectorT
{
    int vSize;
    pointerVT<T> *start, *now;

public:
    myVectorT();
    ~myVectorT();
    void push_back(const T &);
    void pop(int);
    int size();
    T &operator [] (int);
};

template<class T>
myVectorT<T>::myVectorT()
{
    start = NULL;
    now = NULL;
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

    if (start == NULL)
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
        start = NULL;
        return;
    }

    if (pos == 1)
    {
        nod->get_next()->set_prev(NULL);
        start = nod->get_next();
    }
    else if (pos == vSize)
    {
        nod->get_prev()->set_next(NULL);
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

#endif
