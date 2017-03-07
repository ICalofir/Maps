#ifndef CREATE_CITIES_H
#define CREATE_CITIES_H

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

istream &operator >> (istream &in, create_cities &ob)
{
    char *name_city = new char[101];
    double h, m, s;

    cout << "Introduceti numele orasului: ";
    in.getline(name_city + 1, 101);
    int lg = strlen(name_city + 1);
    for (int i = 1; i <= lg; ++i)
        ob.pushC(name_city[i]);

    cout << "Introduceti orele, minutele si secundele pentru latitudine: ";
    in >> h >> m >> s;
    ob.lati = h + m * (1.0 / 60.0) + s * (1.0 / 3600.0);

    cout << "Introduceti orele, minutele si secundele pentru longitudine: ";
    in >> h >> m >> s;
    ob.longi = h + m * (1.0 / 60.0) + s * (1.0 / 3600.0);

    in.getline(name_city + 1, 101);
    delete[] name_city;

    return in;
}

ostream &operator << (ostream &out, create_cities ob)
{
    for (int i = 1; i <= ob.name.size(); ++i)
        out << ob.name[i];
    out << ' ' << ob.x << ' ' << ob.y << '\n';

    return out;
}

void create_cities::setX()
{
    x = R * cos(lati * PI / 180.0) * cos(longi * PI / 180.0);
}

void create_cities::setY()
{
    y = R * cos(lati * PI / 180.0) * sin(longi * PI / 180.0);
}

void create_cities::pushC(char c)
{
    name.push_back(c);
}

int create_cities::getX()
{
    return x;
}

int create_cities::getY()
{
    return y;
}

char create_cities::getC(int pos)
{
    return name[pos];
}

int create_cities::nameSize()
{
    return name.size();
}

#endif
