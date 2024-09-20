#include <iostream>

using namespace std;

int tongchan(int n)
{
    int s(0);
    while(n>0)
    {
        if((n%10)%2==0) s += n%10;
        n/=10;
    }
    return s;
}
