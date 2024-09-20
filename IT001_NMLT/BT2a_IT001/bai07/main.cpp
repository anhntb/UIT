#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    float S(0);
    for(float i=1; i<=n; i++) S += i/(i*(i+1));
    cout << S;
    return 0;
}
