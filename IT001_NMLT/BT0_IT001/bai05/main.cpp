#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int a, b, n, S(0);
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap n: ";
    cin >> n;

    if(a==0 || b==0)
    {
        cout << "S = 0";
        exit(0);
    }

    a = abs(a);
    b = abs(b);

    for(int i=n-1; i>=a && i>0; i--)
        if(i%a==0 && i%b!=0) S += i;
    cout << "S = " << S;

    return 0;
}
