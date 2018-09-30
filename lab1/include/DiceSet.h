#ifndef DICESET_H
#define DICESET_H

#include <Dice.h>
#include <map>

class DiceSet
{
    private:
    vector <Dice*> set_ = {new Dice()};

    public:
        DiceSet(){};
        DiceSet(vector <Dice*>);
        DiceSet(int, int, int, int);    //generate random set of dice with number of dice from l1 to r1
                                        //and number of edges from l2 to r2

        map <int, double> calc_p();     //calculates probability of each sum
        string data();  // toString
        static const int NMAX = 100;
};

#endif // DICESET_H
