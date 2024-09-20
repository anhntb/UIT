#include <iostream>

using namespace std;

int main()
{
    int n;
    float S(0);
    cin >> n;
    for(int i=1; i<=n; i++) S += 1./i;
    cout << "S = " << S;
    return 0;
}
