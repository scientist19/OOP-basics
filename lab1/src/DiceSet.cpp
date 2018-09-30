#include "DiceSet.h"

#include <iostream>

DiceSet::DiceSet(vector <Dice*> set_){

    if (set_.size() > 0) this->set_ = set_;
}

DiceSet::DiceSet(int l1, int r1, int l2, int r2){

    int n = l1 + rand() % (r1-l1+1);
    set_.resize(n);
    for (int i = 0; i < n; i++)
        set_[i] = new Dice(l2, r2);
}

map <int, double> DiceSet::calc_p(){

    int n = set_.size();
    double d[NMAX+1][20*NMAX+1] = {0};

    d[0][0] = 1;
    for(int i = 1; i <= n; i++)
        for(int k = 1; k <= 20*n; k++)
            for(int j = 1; j <= set_[i-1]->get_n(); j++)
                d[i][k] += (k - j < 0) ? 0 : d[i-1][k-j]*set_[i-1]->get_p(j-1);

    map <int, double> res;
    for (int i = n; i <= n*20; i++){
        if (d[n][i] == 0) break;
        res[i] = d[n][i];
    }
    return res;
}

string DiceSet::data(){

    int n = set_.size();
    string s = "Statistics about DiceSet (with " + std::to_string(n) + " dice):\n";
    for (int i = 0; i < n; i++){

        s += "Dice # " + std::to_string(i+1) + '\n';
        s += set_[i]->data(4);
    }
    return s;
}
