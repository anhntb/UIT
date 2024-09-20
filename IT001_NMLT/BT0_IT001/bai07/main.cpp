#include <iostream>

using namespace std;

int main()
{
    int n, n1(0);
    cin >> n;

    while(n!=0)
    {
        n1 = n1*10 + n%10;
        n/=10;
    }
    cout << n1;

    return 0;
}
