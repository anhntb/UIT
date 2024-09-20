#include <iostream>

using namespace std;

int main()
{
    int n, S(0);
    cin >> n;
    for(int i=1; i<n; i++)
    if(n%i==0) S+=i;
    if(n==S) cout << n << " la so hoan thien";
    else cout << n << " khong phai so hoan thien";
    return 0;
}
