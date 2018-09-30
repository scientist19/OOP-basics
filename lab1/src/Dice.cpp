#include "Dice.h"

#include <sstream>
#include <cmath>
#include <limits>
#include <algorithm>

Dice::Dice(){}

Dice::Dice(vector <double> p){
    set_p(p);
}

Dice::Dice(int n){

    if (n <= 0) return;
    this->n = n;
    p.resize(n);
    for (int i = 0; i < n; i++)
        p[i] = (double)1/n;
}

Dice::Dice(int l, int r){

    int n = l + rand()%(r-l+1);
    vector <double> points;

    for (int i = 0; i < n-1; i++)
        points.push_back((double)rand()/RAND_MAX);
    sort(points.begin(), points.end());
    points.push_back(1.);

    this->n = n;
    p.resize(n);
    p[0] = points[0];
    for(int i = 1; i < n; i++)
        p[i] = points[i] - points[i-1];
}

bool Dice::check(vector <double> p){

    double s = 0;
    for(int i = 0; i < (int)p.size(); i++)
        s += p[i];

    if (fabs(s - 1) < std::numeric_limits<double>::epsilon()) return true;
    return false;
}

string Dice::data(int t){

    string s;
    for (int i = 0; i < t; i++)
        s += " ";

    s += "Number of edges = " + std::to_string(this->n) + '\n';

    for (int i = 0; i < t; i++)
        s += " ";

    s += "P for each edge: ";

    for(int i = 0; i < (int)this->p.size(); i++)
        s += std::to_string(p[i]) + ' ';
    s += '\n';

    return s;
}

bool Dice::set_p(vector <double> p){

    if (p.size() == 0) return false;
    if (check(p) == true){

        this->n = p.size();
        this->p = p;

        return true;
    }
    return false;
}

double Dice::get_p(int j){

    if (j < 0 || j >= n) return 0;
    return p[j];
};
