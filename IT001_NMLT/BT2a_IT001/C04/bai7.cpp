#include <iostream>

using namespace std;

int main()
{
    int arr[4];
    for(int i=0; i<=3; i++)
    {
        cin >> arr[i];
        if(arr[0]>arr[i]) arr[0]=arr[i];
    }
    cout << "Min: " << arr[0];
    return 0;
}
