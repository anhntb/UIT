#include <iostream>

using namespace std;

int main()
{
    int arr[4],t;
    for(int i=0; i<=3; i++) cin >> arr[i];
    for(int i=0; i<=2; i++)
        for(int j=i+1; j<=3; j++)
            if(arr[i]>arr[j])
            {
                t=arr[i];
                arr[i] = arr[j];
                arr[j] = t;
            }
    for(int i=0; i<=3; i++) cout << arr[i] << " ";
    return 0;
}
