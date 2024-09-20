#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    double x = pow(32,0.2) - pow(1./64,-0.25) + pow(8./27,1./3);
    cout << "A = 32^0.2 - (1/64)^(-0.25) + (8/27)^(1/3) = " << x;
    return 0;
}
