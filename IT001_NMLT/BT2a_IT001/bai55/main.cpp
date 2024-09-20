/*
vd: 1234121
chữ số đầu tiên: 1
số chữ số đầu tiên: 3
*/
#include <iostream>

using namespace std;

int main()
{
    int n, d(0);
    cin >> n;
    int a=n;
    while(a>9) a/=10;
    while(n>0)
    {
        if(n%10 == a) d++;
        n/=10;
    }
    cout << d;
    return 0;
}
