#include <iostream>
#include <cmath>

using namespace std;

class CTimeSpan
{
private:
    int iHour;
    int iMinu;
    int iSec;

    bool checkTime() const
    {
        if(iHour >= 0 && iMinu >= 0 && iSec >= 0)
            return true;
        return false;
    }

    int toSec() const
    {
        return iHour*60 + iMinu*60 + iSec;
    }

    void toCTimeSpan(int n)
    {
        iSec = n%60;
        n /= 60;
        iMinu = n%60;
        iHour = n/60;
    }

public:
    CTimeSpan(int iH=0, int iM=0, int iS=0) : iHour(iH), iMinu(iM), iSec(iS) 
    {
        if(!checkTime())
            exit(1);

        if(iM >= 60 || iS >= 60)
        {
            int tmp = toSec();
            iSec = tmp%60;
            tmp /= 60;
            iMinu = tmp%60;
            iHour = tmp/60;
        }
    }

    CTimeSpan operator + (const CTimeSpan &a) const
    {
        return CTimeSpan(iHour+a.iHour, iMinu+a.iMinu, iSec+a.iSec);
    }

    CTimeSpan operator - (const CTimeSpan &a) const
    {
        CTimeSpan tmp;
        tmp.toCTimeSpan(abs(toSec() - a.toSec()));
        return tmp;
    }

    friend ostream& operator << (ostream &os, const CTimeSpan &a);
    friend istream& operator >> (istream &is, CTimeSpan &a);
};

ostream& operator << (ostream &os, const CTimeSpan &a)
{
    os << a.iHour << "h : " << a.iMinu << "m : " << a.iSec << "s";
    return os; 
}

istream& operator >> (istream &is, CTimeSpan &a)
{
    int h, m, s;
    is >> h >> m >> s;
    a = CTimeSpan(h, m, s);
    return is;
}

int main()
{

    return 0;
}