#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    //rút gọn PT luôn bằng 1 với mọi a,b
    double a,b;
    cin >> a >> b;
    double c3_a = pow(a,1./3), c3_b = pow(b,1./3);
    cout << "PT = " << ((a+b)/(c3_a+c3_b) - c3_a*c3_b) / pow(c3_a-c3_b,2);
    return 0;
}
