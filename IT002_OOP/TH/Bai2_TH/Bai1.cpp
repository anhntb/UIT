#include <iostream>
#include <cmath>

using namespace std;

class PhanSo
{
private:
    int iTuSo;
    int iMauSo;

public:
    PhanSo(int a=0, int b=1)
    {
        iTuSo = a;
        iMauSo = b;
        if(iMauSo < 0)
        {
            iTuSo = -iTuSo;
            iMauSo = -iMauSo;
        }
    }

    void NhapPS()
    {
        cout << "Nhap tu so: ";
        cin >> iTuSo;

        NhapMauSo:
            cout << "Nhap mau so(khac 0): ";
            cin >> iMauSo;

        if(iMauSo == 0)
            goto NhapMauSo;

        if(iMauSo < 0)
        {
            iTuSo = -iTuSo;
            iMauSo = -iMauSo;
        }
    }

    void rutGonPS()
    {
        int n1 = abs(iTuSo);
        int n2 = abs(iMauSo);

        while(n2!=0) //Tìm UCLN
        {
            int tmp = n1;
            n1 = n2;
            n2 = tmp%n2;
        }

        iTuSo = iTuSo/n1;
        iMauSo = iMauSo/n1;
    }

    PhanSo Cong(PhanSo a) const
    { 
        PhanSo kq(iTuSo*a.iMauSo+iMauSo*a.iTuSo, iMauSo*a.iMauSo);
        kq.rutGonPS();
        return kq;
    }

    PhanSo Tru(PhanSo a) const
    {
        PhanSo kq(iTuSo*a.iMauSo-iMauSo*a.iTuSo, iMauSo*a.iMauSo);
        kq.rutGonPS();
        return kq;
    }

    PhanSo Nhan(PhanSo a) const
    {
        PhanSo kq(iTuSo*a.iTuSo, iMauSo*a.iMauSo);
        kq.rutGonPS();
        return kq;
    }

    PhanSo Chia(PhanSo a) const
    {
        PhanSo kq(iTuSo*a.iMauSo, iMauSo*a.iTuSo);
        kq.rutGonPS();
        return kq;
    }

    double giaTriPS()
    {
        return double(iTuSo) / iMauSo;
    }

    void XuatPS()
    {
        cout << iTuSo << "/" << iMauSo << endl;
    }
};

PhanSo* PhepToan2PS(PhanSo a, PhanSo b)
{
    PhanSo* kq = new PhanSo[4];

    kq[0] = a.Cong(b);
    kq[1] = a.Tru(b);
    kq[2] = a.Nhan(b);
    kq[3] = a.Chia(b);

    return kq;
}

int main()
{
    PhanSo a, b;

    cout << "Phan so a" << endl;
    a.NhapPS();
    cout << "Gia tri a:" << a.giaTriPS() << endl << endl;

    cout << "Phan so b" << endl;
    b.NhapPS();
    cout << "Gia tri b:" << b.giaTriPS() << endl << endl;

    PhanSo* tmp = PhepToan2PS(a,b);
    cout << "Tong:";
    tmp[0].XuatPS();

    cout << "Thuong:";
    tmp[1].XuatPS();

    cout << "Tich:";
    tmp[2].XuatPS();

    cout << "Thuong:";
    tmp[3].XuatPS();

    return 0;
}