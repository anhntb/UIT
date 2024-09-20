#include <iostream>

using namespace std;

int main()
{
    float x,n, T(1);
    cin >> x >> n;
    for(int i=1; i<=n; i++) T*=x;
    cout << T;
    return 0;
}
