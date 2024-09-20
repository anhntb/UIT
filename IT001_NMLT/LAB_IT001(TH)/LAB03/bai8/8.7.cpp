#include <iostream>

using namespace std;

bool timx(int arr[], int n)
{
    cout << "Nhap x: ";
    int x;
    cin >> x;
    for(int i(0); i<n; i++)
        if(arr[i]==x) return true;
    return false;
}
