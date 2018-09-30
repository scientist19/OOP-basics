#include "Dice.h"
#include <sstream>
#include <cmath>
#include <limits>

Dice::Dice(){}

Dice::Dice(int n, vector <double> p){

    this->n = max(n,2);
    if (check(this->n,p) == true){

        this->p.resize(this->n);
        for (int i = 0; i < (int)p.size(); i++)
            this->p[i] = p[i];
    }
}

bool Dice::check(int n, vector <double> p){

    double s = 0;
    for(int i = 0; i < min(n,(int)p.size()); i++)
        s += p[i];

    if (fabs(s - 1) < std::numeric_limits<double>::epsilon()) return true;
    return false;
}

string Dice::data(){

    string s = "Number of edge = " + std::to_string(this->n) + '\n'
                + "Probabilities for each edge: " + '\n';

    for(int i = 0; i < (int)this->p.size(); i++)
        s += std::to_string(p[i]) + ' ';
    s += '\n';

    return s;
}

