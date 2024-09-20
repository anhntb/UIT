#include <iostream>
#include <math.h>

using namespace std;

float canbac_x(int n)
{
    int x;
    cout << "Nhap x: ";
    cin >> x;
    return pow(n, 1./x);
}
