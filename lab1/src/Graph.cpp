#include "Graph.h"
#include "Dice.h"

#include <algorithm>

using std::pair;
using std::vector;
using std::string;
using std::make_pair;

template <typename T>
void Graph<T>::fill_vertix(){
    for (size_t i = 0; i < n; i++)
        vertix.push_back(new T());
}

template <typename T>
Graph<T>::Graph(std::size_t n)
{
    this->n = n;
    fill_vertix();
}

template <typename T>
Graph<T>::Graph(std::size_t n, const vector <std::size_t> al[NMAX]){

    this->n = n;
    fill_vertix();

    std::size_t m = 0;
    for (std::size_t i = 0; i < n; i++){
        for (std::size_t j = 0; j < al[i].size(); j++)
            this->al[i].push_back(std::make_pair(al[i][j], 0));
        m++;
    }
    this->m = m;
}

template <typename T>
Graph<T>::Graph(std::size_t n, const vector <pair <std::size_t, int>> al[NMAX]){

    this->n = n;
    fill_vertix();

    std::size_t m = 0;
    for (std::size_t i = 0; i < n; i++){
        this->al[i] = al[i];
        m++;
    }
    this->m = m;
}

template <typename T>
Graph<T>::Graph(std::size_t l, std::size_t r, int weight){

    this->n = l + rand()%(r-l+1);
    std::size_t pm = n-1 + rand()%(n*(n-1)/2 - (n-1) + 1);

    for (size_t i = 0; i < pm; i++){

        size_t v, u;
        do{
            v = rand()%n;
            do u = rand()%n; while (v == u);
        }while (gete(v, u) >= 0);

        int w = 1 + rand()%weight;
        adde(v, u, w);
    }
    fill_vertix();
}

template <typename T>
void Graph<T>::set_vertix(const vector <T*> vertix){
    this->vertix = vertix;
}

template <typename T>
void Graph<T>::set_alist(const vector <std::size_t> al[NMAX]){
    for (std::size_t i = 0; i < n; i++)
        for (std::size_t j = 0; j < al[i].size(); j++)
            this->al[i].push_back(std::make_pair(al[i][j], 0));
}

template <typename T>
void Graph<T>::set_alist(const vector <pair <std::size_t,int>> al[NMAX]){
    for (std::size_t i = 0; i < n; i++)
        this->al[i] = al[i];
}

template <typename T>
T* Graph<T>::getv(std::size_t i){
    if (i < 0 || i >= n) return nullptr;
    return vertix[i];
}

template <typename T>
void Graph<T>::addv(T* v){

    n++;
    vertix.push_back(v);
}

template <typename T>
bool Graph<T>::replacev(std::size_t i, T* v){
    if (i < 0 || i >= n) return false;

    delete vertix[i];
    vertix[i] = v;
    return true;
}

template <typename T>
bool Graph<T>::adde(std::size_t v, std::size_t u, int w){

     if (v < 0 || v >= n || u < 0 || u >= n) return false;

    for (std::size_t i = 0; i < al[v].size(); i++)
        if (al[v][i].first == u) return false;

    al[v].push_back(std::make_pair(u,w));
    al[u].push_back(std::make_pair(v,w));
    m++;
    return true;
}

template <typename T>
int Graph<T>::gete(std::size_t v, std::size_t u){

    if (v >= n || v < 0) return -2;
    for (std::size_t i = 0; i < al[v].size(); i++)
        if (al[v][i].first == u) return al[v][i].second;
    return -1;
}

template <typename T>
bool Graph<T>::deletee(std::size_t v, std::size_t u){

    for (auto it = al[v].begin(); it != al[v].end(); it++)
        if (it->first == u){
            al[v].erase(it);
            break;
        };
    for (auto it = al[u].begin(); it != al[u].end(); it++)
        if (it->first == v){
            al[u].erase(it);
            m--;
            return true;
        };

    return false;
}

template <typename T>
string Graph<T>::data(){

    string s = "Number of vertix: " + std::to_string(n) + '\n'
            + "Number of edges: " + std::to_string(m) + '\n'
            + "Edges:\n";

    for (std::size_t i = 0; i < n; i++)
        for (std::size_t j = 0; j < al[i].size(); j++)
            if (i < al[i][j].first) s += std::to_string(i) + "--(" + std::to_string(al[i][j].second) +
                                   ")-->" + std::to_string(al[i][j].first) + '\n';
   return s;
}

template <typename T>
Graph<T> Graph<T>::minSpanningTree(){

    vector <pair <int, pair <std::size_t, std::size_t>>> g; // (weight, (vertix 1, vertix 2))

    for (std::size_t i = 0; i < n; i++)
        for (std::size_t j = 0; j < al[i].size(); j++)
            if (i < al[i][j].first) g.push_back(make_pair(al[i][j].second, make_pair(i, al[i][j].first)));

    Graph<T> res = Graph<T>(n);
    res.set_vertix(vertix);

    std::sort(g.begin(), g.end());

    vector<std::size_t> tree_id (n);

    for (std::size_t i = 0; i < n; i++)
        tree_id[i] = i;

    for (std::size_t i = 0; i < m; i++){

        std::size_t a = g[i].second.first,
                    b = g[i].second.second;
        int l = g[i].first;

        if (tree_id[a] != tree_id[b]){

            res.adde(a, b, l);
            std::size_t old_id = tree_id[b],
                        new_id = tree_id[a];

            for (std::size_t j = 0; j < n; j++)
                if (tree_id[j] == old_id) tree_id[j] = new_id;
        }
    }
    return res;
}

template class Graph<int>;
template class Graph<Dice>;
