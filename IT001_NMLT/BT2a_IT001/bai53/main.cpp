#include <iostream>

using namespace std;

int main()
{
    int n, d(1);
    cin >> n;
    int maxN = n%10;
    while(n>0)
    {
        n/=10;
        if(n%10 == maxN) d++;
        if(n%10 > maxN)
        {
            maxN = n%10;
            d=1;
        }
    }
    cout << d;
    return 0;
}
