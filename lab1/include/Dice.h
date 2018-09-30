#ifndef DICE_H
#define DICE_H

#include <vector>
#include <string>

using namespace std;

class Dice
{
    private:
        int n = 2;  //number of edges
        vector <double> p = {0.5, 0.5};  //probability of choosing each edge


    public:
        Dice();
        Dice(int);      //equal probability for each of n edge
        Dice(vector <double>);
        Dice(int, int);  // generate dice with random number of edges(from l to r) and random P

        string data(int);  // toString, argument - number of spaces (indent)
        bool set_p(vector <double>);    // set the array of probabilities, return 1 if successfully
        int get_n(){return n;};
        vector <double> get_p(){return p;};
        double get_p(int);

        static bool check(vector <double>);    //check the correctness of array of probabilities
};

#endif // DICE_H
