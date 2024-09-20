#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float x,n,s(1),gt(1);
    cin >> x >> n;
    for(int i=0; i<=n; i++)
    {
        gt*=2*i*(2*i+1);
        if(gt==0) gt=1;
        s += pow(-1,i+1) * pow(x,2*i+1) / gt;
    }
    cout << s;
    return 0;
}
