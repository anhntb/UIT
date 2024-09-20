#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float s,x,n;
    cin >> x >> n;
    for(int i=0; i<=n; i++) s += pow(x,2*i+1) * pow(-1,i);
    cout << s;
    return 0;
}
