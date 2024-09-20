#include <iostream>
#include <cmath>

using namespace std;

class PhanSo
{
private:
    int tu;
    int mau;

public:
    PhanSo(int tu = 0, int mau = 1)
    {
        this->tu = tu;
        this->mau = mau;
    }

    void setTu(int tu)
    {
        this->tu = tu;
    }

    int getTu()
    {
        return tu;
    }

    void setMau(int mau)
    {
        this->mau = mau;
    }

    int getMau()
    {
        return mau;
    }

    void rutGonPS()
    {
        int n1 = abs(tu);
        int n2 = abs(mau);

        while(n2!=0) //Tìm UCLN
        {
            int tmp = n1;
            n1 = n2;
            n2 = tmp%n2;
        }

        tu = tu/n1;
        mau = mau/n1;
    }

    PhanSo Cong(PhanSo a) const
    { 
        PhanSo kq(tu*a.getMau()+mau*a.getTu(), mau*a.getMau());
        kq.rutGonPS();
        return kq;
    }

    PhanSo Tru(PhanSo a) const
    {
        PhanSo kq(tu*a.getMau()-mau*a.getTu(), mau*a.getMau());
        kq.rutGonPS();
        return kq;
    }

    PhanSo Nhan(PhanSo a) const
    {
        PhanSo kq(tu*a.getTu(), mau*a.getMau());
        kq.rutGonPS();
        return kq;
    }

    PhanSo Chia(PhanSo a) const
    {
        PhanSo kq(tu*a.getMau(), mau*a.getTu());
        kq.rutGonPS();
        return kq;
    }

    void display()
    {
        cout << tu << "/" << mau << endl;
    }
};

int main()
{
    PhanSo f; // 0/1
    f.display();

    PhanSo a(2); // 2/1
    a.display();

    PhanSo b(3,2); // 3/2
    b.display();

    PhanSo d(b), e = b;
    d.display();
    e.display();

    PhanSo c = a.Cong(b);
    c.display();

    c = a.Tru(b);
    c.display();

    c = a.Nhan(b);
    c.display();

    c = a.Chia(b);
    c.display();  

    return 0;
}