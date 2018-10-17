#include "DiceSet.h"

#include <iostream>

DiceSet::DiceSet(vector <Dice*> set_){

    if (set_.size() > 0) this->set_ = set_;
}

DiceSet::DiceSet(std::size_t l1, std::size_t r1, std::size_t l2, std::size_t r2){

    std::size_t n = l1 + rand() % (r1-l1+1);
    set_.resize(n);
    for (std::size_t i = 0; i < n; i++)
        set_[i] = new Dice(l2, r2);
}

std::map <int, double> DiceSet::calc_p(){

    std::size_t n = set_.size();
    double d[NMAX+1][20*NMAX+1] = {0};

    d[0][0] = 1;
    for(std::size_t i = 1; i <= n; i++)
        for(std::size_t k = 1; k <= 20*n; k++)
            for(std::size_t j = 1; j <= set_[i-1]->get_n(); j++)
                d[i][k] += (k - j < 0) ? 0 : d[i-1][k-j]*set_[i-1]->get_p(j-1);

    std::map <int, double> res;
    for (std::size_t i = n; i <= n*20; i++){
        if (d[n][i] == 0) break;
        res[i] = d[n][i];
    }
    return res;
}

string DiceSet::data(){

    std::size_t n = set_.size();
    string s = "Statistics about DiceSet (with " + std::to_string(n) + " dice):\n";
    for (std::size_t i = 0; i < n; i++){

        s += "Dice # " + std::to_string(i+1) + '\n';
        s += set_[i]->data(4);
    }
    return s;
}
