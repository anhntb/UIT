#include <iostream>

using namespace std;

int main()
{
    int n, S(1);
    cin >> n;
    for(int i=1; i<=n; i+=2) S *= i;
    cout << "S = " << S;
    return 0;
}
