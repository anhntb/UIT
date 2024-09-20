#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    bool so_ngto = true;
    for(int i=2; i<=sqrt(n); i++)
        if(n%i==0)
        {
            so_ngto = false;
            break;
        }
    if(n==1) so_ngto = false;
    if(n==2) so_ngto = true;

    cout << n << ( so_ngto ? " la so nguyen to" : " khong phai so nguyen to" );

    return 0;
}
