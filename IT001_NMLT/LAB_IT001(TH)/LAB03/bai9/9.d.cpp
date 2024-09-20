#include <iostream>

using namespace std;

void timchan(float arr[], int n)
{
    bool flag=false;
    for(int i(0); i<n; i++)
        if((int)arr[i]%2==0)
        {
            cout << arr[i] << "   ";
            flag=true;
        }
    if(not flag) cout << "Khong tim thay";
    cout << endl;
}
