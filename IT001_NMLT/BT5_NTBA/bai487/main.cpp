/*
Tính đạo hàm cấp 1 của đơn thức
*/

#include <iostream>

using namespace std;

struct donthuc
{
    float heso;
    int somu;
};

void nhapdt(donthuc &a)
{
    cout << "Tao don thuc dang a(x^n)" << endl;
    cout << "Nhap he so a:";
    cin >> a.heso;
    cout << "Nhap so mu n:";
    cin >> a.somu;
}

void xuatdt(donthuc a)
{
    cout << a.heso << "x^" << a.somu << endl;
}

donthuc daohamc1(donthuc &a)
{
    a.heso *= a.somu;
    a.somu--;
}

int main()
{
    donthuc a;
    nhapdt(a);
    xuatdt(a);

    cout << "Dao ham cap 1 cua " << a.heso << "x^" << a.somu << " : ";
    daohamc1(a);
    xuatdt(a);
    return 0;
}