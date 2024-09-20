#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, T(1);
    float x, S(0);
    cin >> x >> n;
    for(float i=1; i<=n; i++)
    {
        T*=x;
        S=sqrt(S+T);
    }
    cout << S;
    return 0;
}
