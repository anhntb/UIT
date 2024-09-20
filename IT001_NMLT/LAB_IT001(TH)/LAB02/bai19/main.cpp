#include <iostream>

using namespace std;

int main()
{
    int n, S(0);
    cin >> n;
    for(int i=2; i<=n; i+=2) S += i;
    cout << "S = " << S;
    return 0;
}
