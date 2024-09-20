#include <iostream>

using namespace std;

int main()
{
    int n;
    float S(0);
    cin >> n;
    for(float i=1; i<=n; i++) S += i/(i+1);
    cout << "S = " << S;
    return 0;
}
