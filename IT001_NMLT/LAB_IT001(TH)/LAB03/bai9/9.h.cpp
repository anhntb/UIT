#include <iostream>

using namespace std;

int vitrinhonhat(float arr[], int n)
{
    float min_a=arr[0];
    int vt_min(0);
    for(int i(1); i<n; i++)
        if(min_a>arr[i])
        {
            min_a=arr[i];
            vt_min=i;
        }
    return vt_min;
}
