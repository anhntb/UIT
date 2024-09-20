#include <iostream>

using namespace std;

void nhap(int a[], int &n)
{
    cout << "Nhap n: ";
    cin >> n;
    for(int i(0); i<n; i++)
    {
        cout << "a[" << i << "]: ";
        nhap_ai:
        cin >> a[i];
        for(int j(0); j<i; j++)
                if(a[j]==a[i])
                {
                    cout << "Error! ---> " << "Nhap lai a[" << i << "]: ";
                    goto nhap_ai;
                }
        if(a[i]<(-379) || a[i]>3718)
        {
            cout << "Error! ---> " << "Nhap lai a[" << i << "]: ";
            goto nhap_ai;
        }
    }
}
