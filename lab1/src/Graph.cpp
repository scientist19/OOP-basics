#include "Graph.h"

Graph::Graph(int n)
{
    this->n = n;
}

Graph::Graph(int n, std::vector <int> al[NMAX]){

    this->n = n;

    int m = 0;
    for (int i = 0; i < n; i++){
        this->al[i] = al[i];
        m++;
    }
    this->m = m;
}

void Graph::set_table(int* table[NMAX]){

    for (int i = 0; i < n; i++)
        this->table[i] = table[i];
}

void Graph::set_alist(std::vector <int> al[NMAX]){
    for (int i = 0; i < n; i++)
        this->al[i] = al[i];
}

int* Graph::getv(int i){
    if (i < 0 || i >= n) return nullptr;
    return table[i];
}

void Graph::addv(int* v){

    n++;
    table[n-1] = v;
}

bool Graph::replacev(int i, int* v){
    if (i < 0 || i >= n) return false;

    delete table[i];
    table[i] = v;
    return true;
}

bool Graph::adde(int v, int u, bool f){

     if (v < 0 || v >= n || u < 0 || u >= n) return false;
     if (f){

        for (int i = 0; i < (int)al[v].size(); i++)
            if (al[v][i] == u) return false;
        al[v].push_back(u);
        m++;
        return true;
     }

     return adde(v, u, true) || adde(v, u, true);
}
