#include <iostream>

using namespace std;

int vitrichandau(float arr[], int n)
{
    for(int i(0); i<n; i++)
        if((int)arr[i]%2==0) return i;
    return -1;
}
