#include <iostream>

#include <Dice.h>

using namespace std;

int main()
{
    Dice dice(3, {1/3., 1/3., 1/3.});
    cout << dice.data();

    return 0;
}
