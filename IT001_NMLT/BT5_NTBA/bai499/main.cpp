/*
Tính đạo hàm cấp k của đa thức
*/

#include <iostream>
#define M 100

using namespace std;

struct dathuc
{
    float heso[M];
    int somu;
};

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

dathuc dhcapk_dt(dathuc a, dathuc dh, int k)
{
    if(k>a.somu)
    {
        dh.heso[0] = 0;
        dh.somu = 0;
        return dh;
    }

    for(int i(k); i<=a.somu; i++)
    {
        if(a.heso[i]!=0)
        {
            dh.heso[i-k] = a.heso[i];
            for(int j(i); j>(i-k); j--)
            {
                dh.heso[i-k] *= j;
            }
        }
        else
            dh.heso[i-k]=0;
    }
    dh.somu = a.somu - k;
    return dh;
}

int main()
{
    dathuc a, kq;
    int k;
    cout << "Tao da thuc" << endl;
    nhapdt(a);
    xuatdt(a);

    cout << "\nNhap bac dao ham:";
    cin >> k;
    xuatdt(dhcapk_dt(a,kq,k));
    return 0;
}