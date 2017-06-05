#include <fstream>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

const int INF = 0x3f3f3f3f;

// mi-am creat clase pentru stringuri si vector salvate prin liste inlantuite, asemanatoare cu cele din stl
#include "myString.h"
#include "myVector.h"
#include "vector_template.h"
#include "get_cities_size.h"
#include "get_cities.h"
#include "region.h"
#include "line.h"
#include "tree.h"
#include "obliquely.h"
#include "simple_graph.h"
#include "complete_graph.h"
#include "myMap.h"

int main()
{
    get_cities C;
    Map M;

    char c, *str, *strA, *strB;
    str = new char[101];
    strA = new char[101];
    strB = new char[101];

    while (true)
    {
        cout << "Alegeti o optiune:\n";
        cout << "1 - Adauga regiune\n";
        cout << "2 - Adauga drum intre doua orase intr-o regiune\n";
        cout << "3 - Distanta minima intre doua orase dintr-o regiune\n";
        cout << "4 - Iesire!\n";

        cin >> c;
        cin.getline(str + 1, 101);

        try
        {
            if (strlen(str + 1) != 0)
                throw 2;
        }
        catch (int x)
        {
            cout << "Nu ati introdus corect, va rugam incercati din nou!\n";
            continue;
        }

        if (c == '1')
        {
            cout << "Nume regiune: ";
            cin.getline(str + 1, 101);

            M.add_region(str + 1);
        }
        else if (c == '2')
        {
            cout << "Nume oras A: ";
            cin.getline(strA + 1, 101);
            cout << "Nume oras B: ";
            cin.getline(strB + 1, 101);
            cout << "Nume regiune: ";
            cin.getline(str + 1, 101);

            try
            {
                if (!C.nr_city(strA + 1))
                    throw strA + 1;
            }
            catch (char *strS)
            {
                cout << "Orasul " << strS << " nu exista in baza de date!\n";
                continue;
            }

            try
            {
                if (!C.nr_city(strB + 1))
                    throw strB + 1;
            }
            catch (char *strS)
            {
                cout << "Orasul " << strS << " nu exista in baza de date!\n";
                continue;
            }

            M.add_cities(C.nr_city(strA + 1), C.nr_city(strB + 1), str + 1);
        }
        else if (c == '3')
        {
            cout << "Nume oras A: ";
            cin.getline(strA + 1, 101);
            cout << "Nume oras B: ";
            cin.getline(strB + 1, 101);
            cout << "Nume regiune: ";
            cin.getline(str + 1, 101);

            try
            {
                if (!C.nr_city(strA + 1))
                    throw strA + 1;
            }
            catch (char *strS)
            {
                cout << "Orasul " << strS << " nu exista in baza de date!\n";
                continue;
            }

            try
            {
                if (!C.nr_city(strB + 1))
                    throw strB + 1;
            }
            catch (char *strS)
            {
                cout << "Orasul " << strS << " nu exista in baza de date!\n";
                continue;
            }

            int d = M.get_min(C.nr_city(strA + 1), C.nr_city(strB + 1), str + 1);

            try
            {
                if (d == -1)
                    throw -1;
                else if (d == INF)
                    throw INF;
                else
                    throw d;
            }
            catch (int x)
            {
                if (x == -1)
                    cout << "Regiunea introdusa nu exista!\n";
                else if (x == INF)
                    cout << "Nu exista drum intre " << strA + 1 << " si " << strB + 1 << "!\n";
                else
                    cout << x << '\n';
            }
        }
        else if (c == '4')
            break;
    }

    delete[] str;
    delete[] strA;
    delete[] strB;

    return 0;
}
