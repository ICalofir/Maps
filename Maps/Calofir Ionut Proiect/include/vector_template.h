#ifndef VECTOR_TEMPLATE_H
#define VECTOR_TEMPLATE_H

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

#include "vector_template.tpp"

#endif
