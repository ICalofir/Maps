#ifndef MYSTRING_H
#define MYSTRING_H

class pointerS // o clasa pentru liste inlantuite
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
    int size() const;
    char *getString();
    char operator [] (int) const;
};

#endif
