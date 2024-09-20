#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int maxN = n%10;
    while(n>0)
    {
        n/=10;
        if(n%10 > maxN) maxN = n%10;
    }
    cout << maxN;
    return 0;
}
