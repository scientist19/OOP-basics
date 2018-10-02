#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph
{
    public:
        static const int NMAX = 100;

    protected:
        int n = 0;
        int m = 0;
        std::vector <int> al[NMAX];
        int* table[NMAX];

    public:
        Graph(){};
        Graph(int);
        Graph(int, std::vector <int> []);
        void set_table(int* table[]);
        void set_alist(std::vector <int> []);
        int getn(){return n;};
        int getm(){return m;};
        int* getv(int);
        void addv(int*);
        bool replacev(int, int*);
        bool adde(int, int, bool);
};

#endif // GRAPH_H
