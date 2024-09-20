#include <iostream>
#include <math.h>
using namespace std;

void ptbac1(float a, float b)
{
    if(a==0) cout << ((b!=0) ? "Vo nghiem" : "Vo so nghiem");
    else cout << "x = " << (b==0 ? 0 : -b/a);
}

int main()
{
    float a,b,c;
    cin >> a >> b >> c;
    if(a==0) ptbac1(b,c);
    else
    {
        float delta = b*b - 4*a*c;
        if(delta<0) cout << "Vo nghiem";
        if(delta==0) cout << "x = " << -b/(2*a);
        if(delta>0) cout << "x1 = " << (-b+sqrt(delta))/(2*a) << "\nx2 = " << (-b-sqrt(delta))/(2*a);
    }
    return 0;
}

