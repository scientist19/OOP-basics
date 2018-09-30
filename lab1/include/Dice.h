#ifndef DICE_H
#define DICE_H

#include <vector>
#include <string>

using namespace std;

class Dice
{
    private:
        int n = 2;  //number of edge
        vector <double> p = {0.5, 0.5};  //probability of choosing each edge


    public:
        Dice();
        Dice(int, vector <double>);

        string data();

        static bool check(int, vector <double>);
};

#endif // DICE_H
