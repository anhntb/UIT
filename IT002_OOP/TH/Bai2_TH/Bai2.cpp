#include <iostream>
#include <cmath>

using namespace std;

class SoPhuc
{
private:
    int iThuc;
    int iAo;

public:
    SoPhuc(int a=0, int b=0) : iThuc(a), iAo(b) {}

    double giaTriSP()
    {
        return sqrt(iThuc*iThuc + iAo*iAo);
    }

    friend SoPhuc operator + (SoPhuc a, SoPhuc b)
    {
        SoPhuc kq(a.iThuc+b.iThuc, a.iAo+b.iAo);
        return kq;
    }

    friend SoPhuc operator - (SoPhuc a, SoPhuc b)
    {
        SoPhuc kq(a.iThuc-b.iThuc, a.iAo-b.iAo);
        return kq;
    }

    friend SoPhuc operator * (SoPhuc a, SoPhuc b)
    {
        SoPhuc kq(a.iThuc*b.iThuc - a.iAo*b.iAo, a.iThuc*b.iAo+a.iAo*b.iThuc);
        return kq;
    }

    friend SoPhuc operator / (SoPhuc a, SoPhuc b)
    {
        SoPhuc kq;
        kq.iThuc = (a.iThuc*b.iThuc + a.iAo*b.iAo) / (b.iThuc*b.iThuc + b.iAo*b.iAo);
        kq.iAo = (a.iThuc*b.iThuc - a.iAo*b.iAo) / (b.iThuc*b.iThuc + b.iAo*b.iAo);
        return kq;
    }

    friend istream& operator >> (istream &inp, SoPhuc &a)
    {
        inp >> a.iThuc >> a.iAo;
        return inp;
    }

    friend ostream& operator << (ostream &out, const SoPhuc &a)
    {
        out << "(" << a.iThuc << ", " << a.iAo << ")";
        return out;
    }
};

istream& operator >> (istream &, SoPhuc &);
ostream& operator << (ostream &, const SoPhuc &);
SoPhuc operator + (SoPhuc, SoPhuc);
SoPhuc operator - (SoPhuc, SoPhuc);
SoPhuc operator * (SoPhuc, SoPhuc);
SoPhuc operator / (SoPhuc, SoPhuc);

SoPhuc* PhepToan2SP(SoPhuc a, SoPhuc b)
{
    SoPhuc* kq = new SoPhuc[4];
    kq[0] = a+b;
    kq[1] = a-b;
    kq[2] = a*b;
    kq[3] = a/b;
    return kq;
}

int main()
{
    SoPhuc a, b;
    cout << "So phuc a: ";
    cin >> a;
    cout << "Gia tri a: " << a.giaTriSP() << endl;

    cout << "So phuc b: ";
    cin >> b;
    cout << "Gia tri b: " << b.giaTriSP() << endl;

    cout << "\nPhep toan 2 so phuc" << endl;
    SoPhuc* kq = PhepToan2SP(a,b);
    cout << "Tong: " << kq[0] << endl;
    cout << "Hieu: " << kq[1] << endl;
    cout << "Tich: " << kq[2] << endl;
    cout << "Thuong: " << kq[3] << endl;

    return 0;
}