#include <iostream>
#include <cmath>

using namespace std;

struct PhanSo
{
    int iTuSo;
    int iMauSo;
};

void NhapPS(PhanSo& a)
{
    cout << "Nhap tu so: ";
    cin >> a.iTuSo;

    NhapMauSo:
        cout << "Nhap mau so(khac 0): ";
        cin >> a.iMauSo;

    if(a.iMauSo == 0)
        goto NhapMauSo;

    if(a.iTuSo*a.iMauSo < 0)
    {
        a.iTuSo = -abs(a.iTuSo);
        a.iMauSo = abs(a.iMauSo);
    }

    if(a.iTuSo < 0 && a.iMauSo < 0)
    {
        a.iTuSo = -a.iTuSo;
        a.iMauSo = -a.iMauSo;
    }
}

void XuatPS(PhanSo a)
{
    cout << a.iTuSo << "/" << a.iMauSo << endl;
}

/*
Bài 1: Viết chương trình nhập vào một phân số, rút gọn phân số và xuất kết quả.
+Input: 1 phân số
+Output: 1 phân số đã được rút gọn
*/
void RutGonPS(PhanSo& ps)
{
    int a = abs(ps.iTuSo);
    int b = ps.iMauSo;

    while(b!=0)
    {
        int tmp = a;
        a = b;
        b = tmp%b;
    }

    ps.iTuSo /= a;
    ps.iMauSo /= a;
}

/*
Bài 2: Viết chương trình nhập vào hai phân số, tìm phân số lớn nhất và xuất kết quả.
+Input: 2 phân số
+Output: phân số lớn nhất
*/
PhanSo TimPSLonNhat(PhanSo a, PhanSo b)
{
    double ps_a = (double)a.iTuSo / a.iMauSo;
    double ps_b = (double)b.iTuSo / b.iMauSo;
    return (ps_a > ps_b ? a : b);
}

/*
Bài 3: Viết chương trình nhập vào hai phân số. Tính tổng, hiệu, tích, thương giữa chúng và xuất
kết quả.
+Input: 2 phân số
+Output: + tổng 
         + hiệu
         + tích
         + thương
*/
PhanSo* PhepToan2PS(PhanSo a, PhanSo b)
{
    PhanSo* kq = new PhanSo[4];

    //tổng
    kq->iTuSo = a.iTuSo*b.iMauSo + a.iMauSo*b.iTuSo;
    kq->iMauSo = a.iMauSo*b.iMauSo;

    //hiệu
    kq[1].iTuSo = a.iTuSo*b.iMauSo - a.iMauSo*b.iTuSo;
    kq[1].iMauSo = kq[0].iMauSo;

    //tích
    kq[2].iTuSo = a.iTuSo*b.iTuSo;
    kq[2].iMauSo = kq[0].iMauSo;

    //thương
    kq[3].iTuSo = a.iTuSo*b.iMauSo;
    kq[3].iMauSo = a.iMauSo*b.iTuSo;

    RutGonPS(kq[0]);
    RutGonPS(kq[1]);
    RutGonPS(kq[2]);
    RutGonPS(kq[3]);

    return kq;
}

int main()
{
    PhanSo a;
    PhanSo b;

//Bài 1: Rút gọn phân số.
    cout << "----------Bai 1----------" << endl;

    NhapPS(a);
    RutGonPS(a);
    XuatPS(a); 

//Bài 2: Tìm phần số lớn nhất.
    cout << "\n----------Bai 2----------" << endl;

    cout << "+ Phan so thu 1" << endl;
    NhapPS(a);
    cout << "+ Phan so thu 2" << endl;
    NhapPS(b);

    cout << "Phan so lon nhat: ";
    XuatPS(TimPSLonNhat(a, b));

//Bài 3: Tổng, hiệu, tích, thương 2 phân số.
    cout << "\n----------Bai 3----------" << endl;

    cout << "+ Phan so thu 1" << endl;
    NhapPS(a);
    cout << "+ Phan so thu 2" << endl;
    NhapPS(b);

    PhanSo* c = PhepToan2PS(a, b);

    cout << "Tong: ";
    XuatPS(c[0]);

    cout << "Hieu: ";
    XuatPS(c[1]);

    cout << "Tich: ";
    XuatPS(c[2]);

    cout << "Thuong: ";
    XuatPS(c[3]);

    return 0;
}