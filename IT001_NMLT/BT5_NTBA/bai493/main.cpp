/*
Tính hiệu của 2 đa thức
*/

#include <iostream>
#define M 100

using namespace std;

struct dathuc
{
    float heso[M];
    int somu;
};

dathuc operator - (dathuc a, dathuc b)
{
    dathuc kq;
    if(a.somu > b.somu) //kq.somu max
    {
        kq.somu = a.somu;
        for(int i(kq.somu); i>b.somu; i--)
        {
            b.heso[i]=0;
        }
    }
    else
    {
        kq.somu = b.somu;
        for(int i(kq.somu); i>a.somu; i--)
        {
            a.heso[i]=0;
        }
    }

    for(int i(0); i<=kq.somu; i++)
    {
        kq.heso[i] = a.heso[i] - b.heso[i];
    }

    return kq;
}

void nhapdt(dathuc &a)
{
    bacdathuc:
        cout << "Nhap bac da thuc:";
        cin >> a.somu;
    if(a.somu<1)
    {
        cout << "Bac da thuc phai lon hon 0!\nNhap lai!!!" << endl;
        goto bacdathuc;
    }

    for(int i(0); i<a.somu; i++)
    {
        cout << "He so x^" << i << ": ";
        cin >> a.heso[i];
    }

    hesocuoi:
        cout << "He so x^" << a.somu << ": ";
        cin >> a.heso[a.somu];
    if(a.heso[a.somu]==0)
    {
        cout << "He so cuoi phai khac 0\n";
        cout << "Nhap lai!!!" << endl;
        goto hesocuoi;
    }
}

void xuatdt(dathuc a)
{
    for(int i(0); i<a.somu; i++)
    {
        if(a.heso[i]!=0)
            cout << a.heso[i] << "x^" << i << " + ";
    }
    cout << a.heso[a.somu] << "x^" << a.somu << endl;
}

int main()
{
    dathuc a, b;
    cout << "Tao da thuc thu 1" << endl;
    nhapdt(a);
    xuatdt(a);

    cout << "\nTao da thuc thu 2" << endl;
    nhapdt(b);
    xuatdt(b);

    cout << "\nHieu 2 da thuc: ";
    xuatdt(a-b);
    return 0;
}