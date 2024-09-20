#include <iostream>

using namespace std;

int main()
{
    int n, T(1);
    cin >> n;
    while(n>0)
    {
        if((n%10)%2==1) T*=n%10;
        n/=10;
    }
    if(T==1)
    {
        cout << 0;
        exit(0);
    }
    cout << T;
    return 0;
}
