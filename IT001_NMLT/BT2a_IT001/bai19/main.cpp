#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float x,n,S(1),S1(1);
    cin >> x >> n;
    for(int i=1; i<=n; i++)
    {
        S1*=i;
        if(i%2==1) S+=pow(x,i)/S1;
    }
    cout << S;
    return 0;
}
