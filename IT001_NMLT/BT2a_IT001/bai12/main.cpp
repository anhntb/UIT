#include <iostream>

using namespace std;

int main()
{
    float x,n, T(1), S(0);
    cin >> x >> n;
    for(int i=1; i<=n; i++)
    {
        T*=x;
        S+=T;
    }
    cout << S;
    return 0;
}
