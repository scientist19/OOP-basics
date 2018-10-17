#include <Dice.h>
#include <DiceSet.h>
#include <Graph.h>

#include <iostream>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;
using std::map;

void intGraphSample(){

    cout << "\n----intGraphSample----" << endl;

    //To create an empty Graph object
    Graph<int> g1;

    //To create an empty Graph object with n vertices
    std::size_t n = 10;
    Graph<int> g2(n);

    //To create random Graph object
    Graph<int> gr(5, 10, 30);

    //To add a new vertix to the Graph object with value val
    int val = 1;
    g1.addv(&val);

    //To initialize Graph object with vector of pointers to the vertices
    vector<int*> vert = {new int(1), new int(2), new int(3), new int(4), new int(5), new int(6), new int(7), new int(8), new int(9), new int(10)};
    g2.set_vertix(vert);

    //To add an edge with weight w between vertices v and u
    std::size_t v = 0, u = 1, w = 20;
    g2.adde(v, u, w);

    g2.adde(0,2,15);
    g2.adde(0,5,10);
    g2.adde(0,7,23);
    g2.adde(1,2,28);
    g2.adde(1,3,30);
    g2.adde(1,4,29);
    g2.adde(2,4,40);
    g2.adde(2,8,12);
    g2.adde(6,9,40);
    g2.adde(7,9,13);

    //To replace in Graph object the vertix with index i by vertex with value val
    std::size_t i = 9;
    val = 11;
    g2.replacev(i, &val);   //will return true

    //To delete the edge between vertices v and u in an object Graph
    v = 1;
    u = 4;
    g2.deletee(v, u);   //will return true

    //To get number of vertices in the Graph
    g2.getn();  //will return 10

    //To get number of edges in the Graph
    g2.getm();  //will return 10

    //To get pointer to the vertex with index i
    i = 9;
    g2.getv(i);     //will return pointer to 11

    //To get weight of the edge between vertices v and u
    v = 0;
    u = 7;
    g2.gete(v, u);  //will return 23

    //To get minimal spanning tree
    Graph<int> g3 = g2.minSpanningTree();
    Graph<int> str = gr.minSpanningTree();


    /*--PRINTING--*/

    //To print object Graph
    cout << "Graph1:" << endl;
    cout << g2.data();

    cout << endl << "Spanning tree:" << endl;
    cout << g3.data() << endl;

    cout << "Graph2 (random):" << endl;
    cout << gr.data();

    cout << endl << "Spanning tree:" << endl;
    cout << str.data() << endl;
}


void doubleGraphSample(){}
void stringGrpahSample(){}
void vectorGraphSample(){}

void DiceSetSample(){

    cout << "\n----DiceSetSample----" << endl;

    //To create Dice with 2 edges with equal (0.5) probability of choosing
    Dice d1();

    //To create Dice with n edges and equal probability for each of them
    std::size_t n = 6;
    Dice d2(n);

    //To create a random Dice object
    Dice dr = Dice(3,10);

    //To set an array of probabilities for Dice object
    vector <double> p = {1./2, 1./4, 1./8, 1./16, 1./32, 1./32};
    d2.set_p(p);     //will return true

    //To get number of edges
    d2.get_n();     //will return 6

    //To get the array of probabilities
    d2.get_p();     //will return {1/2, 1/4, 1/8, 1/16, 1/32, 1/32}

    //To check the correctness of array of probabilities
    Dice().check(p);  //will return true;

    //To cerate DiceSet object with one standart Dice
    DiceSet ds1();

    //To create DiceSet object with vector of dices set_
    vector <Dice*> set_ = {new Dice(), new Dice(6), new Dice(10)};
    DiceSet ds2(set_);

    //To create a random DiceSet with number of dices from l1 to r1 and number of edges from l2 to r2
    std::size_t l1 = 5, r1 = 10,
                l2 = 3, r2 = 6;
    DiceSet ds3(l1, r1, l2, r2);

    //To get an array (map) of probabilities of choosing each sum of points
    map <int, double> pp = ds2.calc_p();


    /*--PRINTING--*/

    //To print object DiceSet
    cout << ds2.data() << endl;
    cout << ds3.data() << endl;
}


void DiceSetGraphSample(){}

int main()
{
    srand(time(0));
    intGraphSample();
    DiceSetSample();
    return 0;
}
