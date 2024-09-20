/*
Nhập tọa độ điểm trong mặt phẳng
*/

#include <iostream>

using namespace std;

struct toado
{
    int x, y;
};

void nhaptoado(toado &A)
{
    cout << "Tao diem co toa do dang (x,y)" << endl;
    cout << "Nhap x:";
    cin >> A.x;
    cout << "Nhap y:";
    cin >> A.y;
}

int main()
{
    toado A;
    nhaptoado(A);
    return 0;
}