#include <iostream>

#include <Dice.h>
#include <DiceSet.h>

using namespace std;

int main()
{
    Dice* d1 = new Dice({0.5, 0.3, 0.2});
    Dice* d2 = new Dice({0.5,0.25,0.15,0.1});

 //   DiceSet ds = DiceSet({d1, d2});
 //   cout << ds.data();
//    map <int, double> m = ds.calc_p();

 //   for (auto it = m.begin(); it != m.end(); it++)
 //       cout << it->first << "   " << it->second << endl;

//    cout << dice.data();

    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    DiceSet ds = DiceSet(l1,r1,l2,r2);
    cout << ds.data();

    map <int, double> m = ds.calc_p();

    for (auto it = m.begin(); it != m.end(); it++)
        cout << it->first << "   " << it->second << endl;

    return 0;
}
