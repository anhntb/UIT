#include <iostream>

using namespace std;

int tichle(int n)
{
    int p(1);
    while(n>0)
    {
        if((n%10)%2==1) p *= n%10;
        n/=10;
    }
    return p;
}
