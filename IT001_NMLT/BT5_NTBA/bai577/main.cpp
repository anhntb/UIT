/*
Tính diện tích xung quanh hình cầu
*/

#include <iostream>
#define PI 3.14

using namespace std;

struct hinhcau
{
    float x, y, z; //tọa độ tâm
    float r; //bán kính
};

void nhaphc(hinhcau &hc)
{
    cout << "Tao hinh cau co tam I = (x,y,z)" << endl;
    cout << "Nhap x:";
    cin >> hc.x;
    cout << "Nhap y:";
    cin >> hc.y;
    cout << "Nhap z:";
    cin >> hc.z;
    bankinh:
        cout << "Nhap ban kinh:";
        cin >> hc.r;
    if(hc.r < 0) 
    {
        cout << "Ban kinh phai lon hon 0" << endl;
        goto bankinh;
    }
}

float sxqhinhcau(hinhcau hc)
{
    return 4*PI*hc.r*hc.r;
}

int main()
{
    hinhcau hc;
    nhaphc(hc);
    cout << "Dien tich xung quanh hinh cau = " << sxqhinhcau(hc);
    return 0;
}