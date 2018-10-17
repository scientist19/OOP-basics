#ifndef DICESET_H
#define DICESET_H

#include <Dice.h>
#include <map>

class DiceSet
{
    private:
        //Vector of dices
        vector <Dice*> set_ = {new Dice()};

    public:
        //Create DiceSet with one dice
        DiceSet(){};

        //Create DiceSet with vector of dices set_
        DiceSet(vector <Dice*> set_);

        //Create a random DiceSet with number of dices from l1 to r1 and number of edges from l2 to r2
        DiceSet(std::size_t l1, std::size_t r1, std::size_t l2, std::size_t r2);

        //Calculates a probability of each sum
        std::map <int, double> calc_p();

        //Returns string - representation of DiceSet
        string data();

        //Maximal number of dices in the DiceSet
        static const int NMAX = 100;
};

#endif // DICESET_H
