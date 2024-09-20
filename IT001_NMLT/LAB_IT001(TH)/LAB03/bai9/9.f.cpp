#include <iostream>

using namespace std;

float duongdau(float arr[], int n)
{
    for(int i(0); i<n; i++)
        if(arr[i]>0) return arr[i];
    return -1;
}
