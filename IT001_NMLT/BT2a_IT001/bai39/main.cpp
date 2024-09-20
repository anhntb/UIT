#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n, T(1);
    float S(0);
    cin >> n;
    for(float i=1; i<=n; i++)
    {
        T*=i;
        S=pow(T+S,1/(i+1));
    }
    cout << S;
    return 0;
}
