#ifndef DICE_H
#define DICE_H

#include <vector>
#include <string>

using std::vector;
using std::string;

class Dice
{
    private:
        //Number of edges
        std::size_t n = 2;

        //Vector of probabilities of choosing each edge
        vector <double> p = {0.5, 0.5};


    public:

        //Create a dice with 2 edges and equal probability for them
        Dice();

        //Create a dice with n edges and equal probability for each of them
        Dice(std::size_t n);

        //Create a dice with the vector of probabilities p
        Dice(vector <double> p);

        //Create a dice with random number of edges(from l to r) and random P
        Dice(std::size_t l, std::size_t r);

        //Returns a string - representation of dice with t spaces (indent)
        string data(std::size_t t);

        //Set an array of probabilities p
        //returns true if successfully
        bool set_p(vector <double> p);

        //Returns number of edges
        int get_n(){return n;};

        //Returns vector of probabilities
        vector <double> get_p(){return p;};

        //Returns probability of choosing edge with number j+1 (and index j in vector P)
        double get_p(std::size_t j);

        //Check the correctness of array of probabilities
        //returns true if it's correct
        static bool check(vector <double> p);
};

#endif // DICE_H
