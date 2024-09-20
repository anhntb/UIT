#include <iostream>

using namespace std;

void vt_am(float arr[], int n)
{
    bool flag=false;
    for(int i(0); i<n; i++)
        if(arr[i]<0)
        {
            cout << i << "   ";
            flag=true;
        }
    if(not flag) cout << "Khong tim thay";
    cout << endl;
}
