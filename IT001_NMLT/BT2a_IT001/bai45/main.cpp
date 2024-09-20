#include <iostream>

using namespace std;

int main()
{
    int n, T(1);
    cin >> n;
    while(n>0)
    {
        T*=n%10;
        n/=10;
    }
    cout << T;
    return 0;
}
