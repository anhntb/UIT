#include <iostream>

using namespace std;

float chancuoi(float arr[], int n)
{
    for(int i(n-1); i>=0; i--)
        if((int)arr[i]%2==0) return arr[i];
    return -1;
}
