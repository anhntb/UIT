/*
Tìm 1 đỉnh trong tam giác có tung độ nhỏ nhất
*/

#include <iostream>
#include <cmath>

using namespace std;

struct tamgiac
{
    float x1, x2, x3;
    float y1, y2, y3;
};

struct toado
{
    float x, y;
};

void nhaptg(tamgiac &tg)
{
    nhaplai:
        cout << "Toa do diem 1 (x,y)" << endl;
        cout << "Nhap x:";
        cin >> tg.x1;
        cout << "Nhap y:";
        cin >> tg.y1;

        cout << "Toa do diem 2 (x,y)" << endl;
        diem2:
            cout << "Nhap x:";
            cin >> tg.x2;
            cout << "Nhap y:";
            cin >> tg.y2;
        if(tg.x2==tg.x1 && tg.y2==tg.y1)
        {
            cout << "Toa do diem 2 phai khac diem 1" << endl;
            goto diem2;
        }

        cout << "Toa do diem 3 (x,y)" << endl;
        diem3:
            cout << "Nhap x:";
            cin >> tg.x3;
            cout << "Nhap y:";
            cin >> tg.y3;
        if((tg.x3==tg.x1 && tg.y3==tg.y1) || (tg.x3==tg.x2 && tg.y3==tg.y2))
        {
            cout << "Toa do diem 3 phai khac diem 1 va 2" << endl;
            goto diem3;
        }

    //*Kiểm tra có nằm trên 1 đường thẳng
    float kc12 = sqrt(pow((tg.x1 - tg.x2),2) + pow((tg.y1 - tg.y2),2));
    float kc13 = sqrt(pow((tg.x1 - tg.x3),2) + pow((tg.y1 - tg.y3),2));
    float kc23 = sqrt(pow((tg.x2 - tg.x3),2) + pow((tg.y2 - tg.y3),2));
    if(kc12==kc13+kc23 || kc13==kc12+kc23 || kc23==kc12+kc13)
    {
        cout << "3 diem nam tren 1 duong thang!\nNhap lai!!!" << endl;
        cout << "-------------------------------------" << endl;
        goto nhaplai;
    }
}

void xuattg(tamgiac tg)
{
    cout << "((" << tg.x1 << "," << tg.y1 << ")";
    cout << ";(" << tg.x2 << "," << tg.y2 << ")";
    cout << ";(" << tg.x3 << "," << tg.y3 << "))" << endl;
}

toado tungdomin(tamgiac tg)
{
    toado min;
    min.y = tg.y1;
    min.x = tg.x1;
    if(min.y > tg.y2)
    {
        min.x = tg.x2;
        min.y = tg.y2;
    }
    if(min.y > tg.y3)
    {
        min.x = tg.x3;
        min.y = tg.y3;
    }
    return min;
}

int main()
{
    tamgiac tg;
    nhaptg(tg);
    xuattg(tg);
    toado min = tungdomin(tg);
    cout << "Dinh co tung do nho nhat:" << "(" << min.x << "," << min.y << ")";

    return 0;
}