#include <iostream>

using namespace std;

int main()
{
    int n, minN(9), d(0);
    cin >> n;
    while(n>0)
    {
        if(n%10 == minN) d++;
        if(n%10 < minN)
        {
            minN = n%10;
            d=1;
        }
        n/=10;
    }
    cout << d;
    return 0;
}
