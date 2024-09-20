/*
Sắp xếp mảng phân số tăng dần
*/

#include <iostream>
#define M 100

using namespace std;

struct PHANSO
{
    int tu, mau;
};

void nhap(PHANSO ps[], int &n)
{
    cout << "Nhap n:";
    cin >> n;

    for(int i(0); i<n; i++)
    {
        cout << "+ Phan so " << i+1 << endl;
        cout << "Nhap tu:";
        cin >> ps[i].tu;
        cout << "Nhap mau:";
        cin >> ps[i].mau;
        cout << endl;
    }
}

void xuat(PHANSO ps[], int n)
{
    cout << "---------------------------------" << endl;
    for(int i(0); i<n; i++)
    {
        cout << "Phan so " << i+1 << ": " << ps[i].tu << "/" << ps[i].mau << endl;
    }
    cout << endl;
}

void tangdan(PHANSO ps[], int n)
{
    for(int i(0); i<n-1; i++)
    {
        for(int j(i+1); j<n; j++)
        {
            if( ((float)ps[i].tu/ps[i].mau) > ((float)ps[j].tu/ps[j].mau) )
                swap(ps[i], ps[j]);
        }
    }
}

int main()
{
    int n;
    PHANSO ps[M], kq;
    nhap(ps,n);
    xuat(ps,n);

    tangdan(ps,n);
    cout << "Mang phan so tang dan" << endl;
    xuat(ps,n);
    return 0;
}