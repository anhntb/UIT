#include <iostream>

using namespace std;

void mangcon()
{
    cout << "Tao mang 1" << endl;
    cout << "Nhap n1: ";
    int n1;
    cin >> n1;
    float a1[n1];
    for(int i(0); i<n1; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> a1[i];
    }
    cout << "\nTao mang 2" << endl;
    cout << "Nhap n2: ";
    int n2;
    cin >> n2;
    float a2[n2];
    for(int i(0); i<n2; i++)
    {
        cout << "a[" << i << "]: ";
        cin >> a2[i];
    }
    bool flag;
    if(n1>=n2)
    {
        for(int i(0); i<n1; i++)
        {
            flag=false;
            if(a2[0]==a1[i])
            {
                flag=true;
                for(int j(1); j<n2; j++)
                    if(a2[j]!=a1[i+j])
                    {
                        flag=false;
                        break;
                    }
                if(flag) break;
            }
        }
        if(flag) cout << "Mang 2 la con cua mang 1" << endl;
        else cout << "Mang 1 va 2 khong phai con cua nhau" << endl;
    }
    else
    {
        for(int i(0); i<n2; i++)
        {
            flag=false;
            if(a1[0]==a2[i])
            {
                flag=true;
                for(int j(1); j<n1; j++)
                    if(a1[j]!=a2[i+j])
                    {
                        flag=false;
                        break;
                    }
                if(flag) break;
            }
        }
        if(flag) cout << "Mang 1 la con cua mang 2" << endl;
        else cout << "Mang 1 va 2 khong phai con cua nhau" << endl;
    }
}

















