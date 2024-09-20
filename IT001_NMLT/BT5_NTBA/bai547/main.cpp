/*
Tìm tọa độ điểm đối xứng qua trục hoành
*/

#include <iostream>

using namespace std;

struct toado
{
    float x, y;
};

void nhaptoado(toado &A)
{
    cout << "Tao toa do co dang (x,y)" << endl;
    cout << "Nhap x:";
    cin >> A.x;
    cout << "Nhap y:";
    cin >> A.y;
}

void xuattoado(toado A)
{
    cout << "(" << A.x << "," << A.y << ")" << endl;
}

toado dxtruchoanh(toado A)
{
    toado dx;
    dx.x = (-1)*A.x;
    dx.y = A.y;
    return dx;
}

int main()
{
    toado A;
    nhaptoado(A);
    xuattoado(A);
    cout << "Diem doi xung qua truc hoanh: ";
    xuattoado(dxtruchoanh(A));
}