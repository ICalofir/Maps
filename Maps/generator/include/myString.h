#ifndef MYSTRING_H
#define MYSTRING_H

class pointerS
{
    char info;
    pointerS *next;
public:
    pointerS();
    void set_info(char);
    void set_next(pointerS *);
    char get_info();
    pointerS *get_next();
};

class myString
{
    int sSize;
    pointerS *start, *now;

public:
    myString();
    ~myString();
    void push_back(char);
    int size();
    char *getString();
    char operator [] (int);
};

#endif
