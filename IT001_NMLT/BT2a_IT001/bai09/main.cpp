#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int S(1);
    for(int i=2; i<=n; i++) S*=i;
    cout << S;
    return 0;
}
