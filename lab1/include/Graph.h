#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <string>

template <typename T> class Graph
{
    public:
        //Maximal number of vertices in the graph
        static const int NMAX = 100;

    protected:
        //Number of vertices
        std::size_t n = 0;

        //Number of edges
        std::size_t m = 0;

        //Adjacency list
        std::vector <std::pair <std::size_t, int>> al[NMAX];

        //Vector of pointers to vertices
        std::vector <T*> vertix;

    public:

        //Create an empty graph with no vertices
        Graph(){};

        //Create an empty graph with n vertices
        Graph(std::size_t n);

        //Create a weighted graph with n vertices and adjacency list al
        Graph(std::size_t n, const std::vector <std::pair <std::size_t,int>> al[]);

        //Create an unweighted graph with n vertices and adjacency list al
        Graph(std::size_t n, const std::vector <std::size_t> al[]);

        //Create a random weighted graph with number of vertices from l to r and weights from 1 to w
        Graph(std::size_t l, std::size_t r, int weight);

        //Set a vector of pointers to vertices
        void set_vertix(const std::vector <T*> vertix);

        //Set an adjacency list for directed graph
        void set_alist(const std::vector <std::pair <std::size_t,int>> al[]);

        //Set an adjacency list for an undirected graph
        void set_alist(const std::vector <std::size_t> al[]);

        //Return vertex number
        int getn(){return n;};

        //Returns edge number
        int getm(){return m;};

        //Returns pointer to the vertex with an index i
        T* getv(std::size_t i);

        //Add the vertex, pointer for which is v, to the graph
        void addv(T* v);

        //Replace in vector of pointers vertex with index i by vertex, pointer for which is v
        //returns true if successfully
        bool replacev(std::size_t i, T* v);

        //Add an edge with weight w between vertices with indexes v and u
        //returns true if successfully
        bool adde(std::size_t v, std::size_t u, int w = 0);

        //Delete an edge between vertices with indexes v and u
        //returns true if successfully
        bool deletee(std::size_t v, std::size_t u);

        //Returns the weight of the edge between vertices with indexes v and u
        //returns -1 if there is no edge
        int gete(std::size_t v, std::size_t u);

        //Returns a string - representation of the graph
        std::string data();

        //Returns minimal spanning tree for the graph
        Graph<T> minSpanningTree();
};

#endif // GRAPH_H
