#include <iostream>

using namespace std;

float lonnhat(float arr[], int n)
{
    float max_a=arr[0];
    for(int i(1); i<n; i++)
        if(max_a<arr[i])
            max_a=arr[i];
    return max_a;
}
