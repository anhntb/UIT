#include <iostream>

using namespace std;

int main()
{
    int n, T(1), S(0);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        T*=i;
        S+=T;
    }
    cout << S;
    return 0;
}
