#include <iostream>

using namespace std;

bool arr_dxung(int arr[], int n)
{
    int a=n/2;
    bool flag=true;
    for(int i(0); i<a; i++)
        if(arr[i]!=arr[n-1-i])
        {
            flag=false;
            break;
        }
    return flag;
}
