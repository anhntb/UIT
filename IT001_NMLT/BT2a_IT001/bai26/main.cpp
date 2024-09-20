#include <iostream>

using namespace std;

int main()
{
    int n, T(1);
    cin >> n;
    for(int i=1; i<=n; i++)
    if(n%i==0 && i%2==1) T*=i;
    cout << T;
    return 0;
}
