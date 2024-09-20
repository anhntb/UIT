#include <iostream>

using namespace std;

bool lon2_nho2(int arr[], int n, int &lon2, int &nho2)
{
    int max_a=arr[0], min_a=arr[0];
    for(int i(0); i<n; i++)
    {
        if(max_a<arr[i]) max_a=arr[i];
        if(min_a>arr[i]) min_a=arr[i];
    }
    int kc_max=max_a-min_a, kc_min=max_a-min_a;
    for(int i(0); i<n; i++)
    {
        if(kc_max>(max_a-arr[i]) && arr[i]!=max_a)
        {
            kc_max=max_a-arr[i];
            lon2=arr[i];
        }
        if(kc_min>(arr[i]-min_a) && arr[i]!=min_a)
        {
            kc_min=arr[i]-min_a;
            nho2=arr[i];
        }
    }
    return kc_max!=0;
}

