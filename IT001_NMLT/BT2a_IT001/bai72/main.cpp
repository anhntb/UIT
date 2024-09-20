#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float x,n,s(0),gt(1);
    cin >> x >> n;
    for(int i=1; i<=n; i++)
    {
        gt*=i;
        s += pow(-1,i) * pow(x,i) / gt;
    }
    cout << s;
    return 0;
}
