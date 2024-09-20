#include <iostream>

using namespace std;

typedef struct PhanSo
{
    int tu, mau;
}PHANSO, PS;

/*
Tối giản phân số
Input:
+1 phân số

Output:
+1 phân số tối giản
*/
int UCLN(int a, int b)
{
    if(b==0) return a;
    return UCLN(b,a%b);
}

PHANSO toiGian(PS p)
{
    int U = UCLN(p.tu,p.mau);
    p.tu /= U;
    p.mau /= U;

    return p;
}

/*
1.1/ Nhập phân số
Input:
+Tử số
+Mẫu số

Output:
+1 phân số
*/
PHANSO nhap()
{
    PhanSo p;
    cout << "Nhap tu so:";
    cin >> p.tu;
    cout << "Nhap mau so:";
    cin >> p.mau;

    return p;
}

/*
1.2/ Xuất phân số
Input:
+1 phân số

Output:
+1 phân số viết dạng: tử/mẫu
*/
void xuat(PS p)
{
    cout << p.tu << "/" << p.mau << endl;
}

/*
1.3/ Cộng 2 phân số
Input:
+2 phân số

Output:
+Tổng 2 phân số
*/
PHANSO tong(PS ps1, PS ps2)
{
    PhanSo kq;
    kq.tu = ps1.tu*ps2.mau + ps2.tu*ps1.mau;
    kq.mau = ps1.mau*ps2.mau;

    kq = toiGian(kq);

    return kq;
}

/*
1.4/ Trừ 2 phân số
Input:
+2 phân số

Output:
+Hiệu 2 phân số
*/
PHANSO hieu(PS ps1, PS ps2)
{
    PhanSo kq;
    kq.tu = ps1.tu*ps2.mau - ps2.tu*ps1.mau;
    kq.mau = ps1.mau*ps2.mau;

    kq = toiGian(kq);

    return kq;
}

/*
1.5/ Nhân 2 phân số
Input:
+2 phân số

Output:
+Tích 2 phân số
*/
PHANSO tich(PS ps1, PS ps2)
{
    PhanSo kq;
    kq.tu = ps1.tu*ps2.tu;
    kq.mau = ps1.mau*ps2.mau;

    kq = toiGian(kq);

    return kq;
}

/*
1.6/ Chia 2 phân số
Input:
+2 phân số

Output:
+Thương 2 phân số
*/
PHANSO thuong(PS ps1, PS ps2)
{
    PhanSo kq;
    kq.tu = ps1.tu*ps2.mau;
    kq.mau = ps1.mau*ps2.tu;

    kq = toiGian(kq);

    return kq;
}

int main()
{
    PhanSo ps1 = {4,5};
    PhanSo ps2 = {5,10};

    cout << "+ Bai 1.2" << endl;
    xuat(ps1);
    xuat(ps2);

    cout << "\n+ Bai 1.3" << endl;
    cout << "Tong = ";
    xuat(tong(ps1,ps2));

    cout << "\n+ Bai 1.4" << endl;
    cout << "Hieu = ";
    xuat(hieu(ps1,ps2));

    cout << "\n+ Bai 1.5" << endl;
    cout << "Tich = ";
    xuat(tich(ps1,ps2));

    cout << "\n+ Bai 1.6" << endl;
    cout << "Thuong = ";
    xuat(thuong(ps1,ps2));

    return 0;
}
