#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    float x,n,s(0);
    cin >> x >> n;
    for(int i=1; i<=n; i++) s += pow(-1,i) * pow(x,i) / (i*(i+1)/2);
    cout << s;
    return 0;
}
