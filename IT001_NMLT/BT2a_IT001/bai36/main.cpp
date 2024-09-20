#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, T(1);
    float S(0);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        T*=i;
        S=sqrt(T + S);
    }
    cout << S;
    return 0;
}
