#include <iostream>

using namespace std;

int main()
{
    int n;
    float S(0);
    cin >> n;
    for(int i=2; i<=2*n; i+=2) S += 1./i;
    cout << "S = " << S;
    return 0;
}
