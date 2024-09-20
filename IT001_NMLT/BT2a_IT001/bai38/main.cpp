#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    float S(0);
    cin >> n;
    for(float i=1; i<=n; i++) S=pow(i+S,1/(i+1));
    cout << S;
    return 0;
}
