#include <iostream>

using namespace std;

int main()
{
    int n, S(1);
    cin >> n;
    for(int i=1; i<=n; i++)
    if(n%i==0) S*=i;
    cout << S;
    return 0;
}
