// iostream
#include <iostream>

using namespace std;

void print_binary(int n)
{
    if (n == 0 || n == 1)
        cout << n;
    else
    {
        print_binary(n / 2);
        cout << n % 2;
    }
}

int main()
{
    print_binary(43);
    cout << endl;
    return 0;
}