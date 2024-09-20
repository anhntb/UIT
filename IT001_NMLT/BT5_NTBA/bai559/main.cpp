/*
Tính khoảng cách giữa 2 điểm theo phương x                                     
*/

#include <iostream>
#include <cmath>

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

float kc(toado A, toado B)
{
    return abs(A.x - B.x);
}

int main()
{
    toado A, B;
    cout << "Tao diem A" << endl;
    nhaptoado(A);
    xuattoado(A);
    cout << "Tao diem B" << endl;
    nhaptoado(B);
    xuattoado(B);
    cout << "Khoang cach A, B theo phuong x = " << kc(A,B);
    return 0;
}