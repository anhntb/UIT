#include <iostream>
#include <math.h>

using namespace std;

bool so_ngto(int n)
{
    if(n==1) return false;
    if(n==2) return true;
    int a = sqrt(n);
    for(int i=2; i<=a; i++)
        if(n%i==0) return false;
    return true;
}

int main()
{
    int n, S(0);
    cout << "Nhap n: ";
    cin >> n;

    for(int i=2; i<n; i++)
        if(so_ngto(i)) S += i;

    cout << "S = " << S;

    return 0;
}
