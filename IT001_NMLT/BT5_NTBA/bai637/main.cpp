/*
Tìm phân số nhỏ nhất trong mảng
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

PHANSO PSmin(PHANSO ps[], int n)
{
    PHANSO m = {ps[0].tu, ps->mau};
    for(int i(1); i<n; i++)
    {
        if( ((float)m.tu/m.mau) > ((float)ps[i].tu/ps[i].mau) )
            m = {ps[i].tu, ps[i].mau};
    }
    return m;
}

int main()
{
    int n;
    PHANSO ps[M], kq;
    nhap(ps,n);
    xuat(ps,n);

    kq = PSmin(ps,n);
    cout << "Phan so nho nhat: " << kq.tu << "/" << kq.mau;
    return 0;
}