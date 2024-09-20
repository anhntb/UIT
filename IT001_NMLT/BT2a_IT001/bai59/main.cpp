#include <iostream>

using namespace std;

int main()
{
    int n,n1(0);
    cin >> n;
    int a=n;

    do
    {
        n1 = n1*10 + a%10;
        a /= 10;
    }while (a!=0);

    cout << ( n==n1 ? "yes" : "no" );

    return 0;
}
