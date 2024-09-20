/*
Xét vị trí tương đối giữa 2 đường tròn
(không cắt nhau, tiếp xúc, cắt nhau)
//* ( 1, 0, -1)
*/

#include <iostream>
#include <cmath>

using namespace std;

struct duongtron
{
    float x, y; //Tọa độ tâm
    float r; //Bán kính
};

void nhapdt(duongtron &A)
{
    cout << "Nhap toa do tam I = (x,y)" << endl;
    cout << "Nhap x:";
    cin >> A.x;
    cout << "Nhap y:";
    cin >> A.y;
    bankinh:
        cout << "Nhap ban kinh:";
        cin >> A.r;
    if(A.r<=0)
    {
        cout << "Ban kinh phai lon hon 0" << endl;
        goto bankinh;
    }
}

int vttuongdoi(duongtron A, duongtron B)
{
    float kctam = sqrt(pow((A.x-B.x),2) + pow((A.y-B.y),2));

    //*Cắt
    if(abs(kctam-A.r)<B.r && B.r<(A.r+kctam))
        return -1;

    //*Tiếp xúc
    if(B.r==abs(kctam-A.r) || B.r==(A.r+kctam))
        return 0;

    //*Không cắt nhau
    return 1;
}

int main()
{
    duongtron dt1, dt2;
    cout << "Tao duong tron 1" << endl;
    nhapdt(dt1);
    cout << "Tao duong tron 2" << endl;
    nhapdt(dt2);

    int index = vttuongdoi(dt1,dt2);
    if(index==(-1)) cout << "2 duong tron cat nhau";
    if(index==0) cout << "2 duong tron tiep xuc nhau";
    if(index==1) cout << "2 duong tron khong cat nhau";
    return 0;
}