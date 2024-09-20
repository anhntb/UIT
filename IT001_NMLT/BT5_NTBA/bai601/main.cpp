/*
Tìm ngày kế tiếp
*/

#include <iostream>

using namespace std;

struct ngay
{
    int d, m, y;
};

void nhapng(ngay &date)
{
    cout << "Nhap ngay:";
    cin >> date.d;
    cout << "Nhap thang:";
    cin >> date.m;
    cout << "Nhap nam:";
    cin >> date.y;
}

void xuatng(ngay date)
{
    cout << date.d << "/" << date.m << "/" << date.y << endl;
}

bool namnhuan(int n)
{
    return n%400==0 || (n%4==0 && n%100!=0);
}

ngay ngayke(ngay date)
{
    ngay ketiep;
    if(date.d==31 && date.m!=12)
    {
        ketiep.d = 1;
        ketiep.m = ++date.m;
        ketiep.y = date.y;
        return ketiep;
    }
    if(date.d==31 && date.m==12)
    {
        ketiep.d = 1;
        ketiep.m = 1;
        ketiep.y = ++date.y;
        return ketiep;
    }
    if(date.d==30)
        switch(date.m)
        {
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                ketiep.d = 31;
                ketiep.m = date.m;
                ketiep.y = date.y;
                return ketiep;
            default:
                ketiep.d = 1;
                ketiep.m = ++date.m;
                ketiep.y = date.y;
                return ketiep;
        }
    if(date.m==2 && date.d==28)
        if(namnhuan(date.y))
        {
            ketiep.d = 29;
            ketiep.m = date.m;
            ketiep.y = date.y;
            return ketiep;
        }
        else
        {
            ketiep.d = 1;
            ketiep.m = ++date.m;
            ketiep.y = date.y;
            return ketiep;
        }
    if(date.m==2 && date.d==29)
    {
        ketiep.d = 1;
        ketiep.m = ++date.m;
        ketiep.y = date.y;
        return ketiep;
    }
    ketiep.d = ++date.d;
    ketiep.m = date.m;
    ketiep.y = date.y;
    return ketiep;
}

int main()
{
    ngay date;
    nhapng(date);
    xuatng(date);

    ngay ketiep = ngayke(date);
    xuatng(ketiep);
    return 0;
}