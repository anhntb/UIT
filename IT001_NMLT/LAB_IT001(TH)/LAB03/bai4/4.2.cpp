#include <iostream>

using namespace std;

int sodao(int n)
{
    int t(0);
    while(n>0)
    {
        t = t*10 + n%10;
        n/=10;
    }
    return t;
}
