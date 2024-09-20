/*
Tìm tọa độ điểm đối xứng qua mặt phẳng Oyz
*/

#include <iostream>

using namespace std;

struct toado
{
    float x, y, z;
};

void nhaptoado(toado &A)
{
    cout << "Tao toa do co dang (x,y,z)" << endl;
    cout << "Nhap x:";
    cin >> A.x;
    cout << "Nhap y:";
    cin >> A.y;
    cout << "Nhap z:";
    cin >> A.z;
}

void xuattoado(toado A)
{
    cout << "(" << A.x << "," << A.y << "," << A.z << ")" << endl;
}

toado dxOyz(toado A)
{
    toado dx;
    dx.x = -A.x;
    dx.y = A.y;
    dx.z = A.z;
    return dx;
}

int main()
{
    toado A, dx;
    nhaptoado(A);
    xuattoado(A);
    cout << "Diem doi xung qua Oyz: ";
    xuattoado(dxOyz(A));
    return 0;
}