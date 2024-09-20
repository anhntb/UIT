#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    float x,n,S(0);
    cin >> x >> n;
    for(int i=2; i<=n; i+=2) S+=pow(x,i);
    cout << S;
    return 0;
}
