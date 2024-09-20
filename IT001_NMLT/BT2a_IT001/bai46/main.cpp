#include <iostream>

using namespace std;

int main()
{
    int n, d(0);
    cin >> n;
    while(n>0)
    {
        if((n%10)%2==1) d++;
        n/=10;
    }
    cout << d;
    return 0;
}
