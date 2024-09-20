#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float s,x,n;
    cin >> x >> n;
    for(int i=1; i<=n; i++) s += pow(x,2*i) * pow(-1,i);
    cout << s;
    return 0;
}
