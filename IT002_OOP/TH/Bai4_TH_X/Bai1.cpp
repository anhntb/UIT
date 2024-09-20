#include <iostream>

using namespace std;

class SoPhuc
{
private:
    double iThuc;
    double iAo;

public:
    SoPhuc(double iT = 0, double iA = 0)
    {
        iThuc = iT;
        iAo = iA;
    }

    SoPhuc operator + (const SoPhuc &a) const
    {
        SoPhuc tmp;
        tmp.iThuc = iThuc + a.iThuc;
        tmp.iAo = iAo + a.iAo;
        return tmp;
    }

    SoPhuc operator - (const SoPhuc &a) const
    {
        SoPhuc tmp;
        tmp.iThuc = iThuc - a.iThuc;
        tmp.iAo = iAo - a.iAo;
        return tmp;
    }

    SoPhuc operator * (const SoPhuc &a) const
    {
        SoPhuc tmp;
        tmp.iThuc = iThuc*a.iThuc - iAo*a.iAo;
        tmp.iAo = iThuc*a.iAo + iAo*a.iThuc;
        return tmp;
    }

    SoPhuc operator / (const SoPhuc &a) const
    {
        if(a==0)
            exit(1);

        SoPhuc tmp;
        tmp.iThuc = (iThuc*a.iThuc + iAo*a.iAo) / (a.iThuc*a.iThuc + a.iAo*a.iAo);
        tmp.iAo = (iThuc*a.iAo + iAo*a.iThuc) / (a.iThuc*a.iThuc + a.iAo*a.iAo);
        return tmp;
    }

    bool operator == (const SoPhuc &a) const
    {
        if(iThuc == a.iThuc && iAo == a.iAo)
            return true;
        
        return false;
    }

    bool operator != (const SoPhuc &a) const
    {
        if(*this == a)
            return false;
        
        return true;
    }

    friend ostream& operator << (ostream& os, const SoPhuc &a);
    friend istream& operator >> (istream& is, SoPhuc &a);
};

ostream& operator << (ostream& os, const SoPhuc &a)
{
    os << a.iThuc << " + " << a.iAo << "i";
    return os;
}

istream& operator >> (istream& is, SoPhuc &a)
{
    double iT, iA;
    is >> iT >> iA;
    a.iThuc = iT;
    a.iAo = iA;
    return is;
}

int main()
{
    SoPhuc a(2), b(2);
    cout << a << endl << b;

    cout << "\na+b=" << a+b << endl;
    cout << "a-b=" << a-b << endl;
    cout << "a*b=" << a*b << endl;
    cout << "a/b=" << a/b << endl;

    cout << (a==b) << " " << (a!=b);

    return 0;
}