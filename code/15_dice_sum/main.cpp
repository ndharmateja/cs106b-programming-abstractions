#include <iostream>
#include "vector.h"
using namespace std;

void diceSum(int n, int querySum, Vector<int> &v, int sum = 0)
{
    if (n == 0){
        if (sum == querySum)
            cout << v << endl;
        return;
    }
    for (int i = 1; i <= 6; i++)
    {
        v.add(i);
        diceSum(n - 1, querySum, v, sum + i);
        v.remove(v.size() - 1);
    }
}

void diceSum(int n, int querySum)
{
    Vector<int> v;
    diceSum(n, querySum, v);
}

int main()
{
    diceSum(3, 7);
    return 0;
}
