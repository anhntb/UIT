/*
Xuất ngày theo định dạng ng/th/nm
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

int main()
{
    ngay date;
    nhapng(date);
    xuatng(date);
    return 0;
}