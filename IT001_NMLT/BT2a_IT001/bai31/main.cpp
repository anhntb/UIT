#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = sqrt(n);
    if(n<2)
    {
        cout << n << " khong phai so nguyen to";
        exit(0);
    }
    for(int i=2; i<=a; i++)
    if(n%i==0)
    {
        cout << n << " khong phai so nguyen to";
        exit(0);
    }
    cout << n << " la so nguyen to";
    return 0;
}
