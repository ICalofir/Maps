#ifndef MYVECTOR_H
#define MYVECTOR_H

class pointerV // o clasa pentru liste inlantuite
{
    int info;
    pointerV *next;
public:
    pointerV();
    void set_info(int);
    void set_next(pointerV *);
    int get_info();
    pointerV *get_next();
};

class myVector
{
    int vSize;
    pointerV *start, *now;

public:
    myVector();
    ~myVector();
    void push_back(int);
    int size();
    int operator [] (int);
};

#endif
