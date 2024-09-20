#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if(n==sqrt(n)*sqrt(n)) cout << n << " la so chinh phuong";
    else cout << n << " khong phai so chinh phuong";

    return 0;
}
