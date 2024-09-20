#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float x,n,S(0),S1(0);
    cin >> x >> n;
    for(int i=1; i<=n; i++)
    {
        S1+=i;
        S+=pow(x,i)/S1;
    }
    cout << S;
    return 0;
}
