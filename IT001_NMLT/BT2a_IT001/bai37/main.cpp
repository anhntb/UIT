#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    float S(0);
    cin >> n;
    for(float i=2; i<=n; i++) S=pow(i+S,1/i);
    cout << S;
    return 0;
}
