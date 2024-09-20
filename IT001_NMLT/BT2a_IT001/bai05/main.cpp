#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    float S(0);
    for(float i=0; i<=n; i++) S += 1/(2*i+1);
    cout << S;
    return 0;
}
