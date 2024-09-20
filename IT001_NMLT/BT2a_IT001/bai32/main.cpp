#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = sqrt(n);
    a = a*a;
    if(n==a) cout << n << " la so chinh phuong";
    else cout << n << " khong phai so chinh phuong";
    return 0;
}
