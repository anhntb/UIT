/*
Xuất tam giác theo định dạng: ((x1,y1);(x2,y2);(x3,y3))
*/

#include <iostream>

using namespace std;

struct tamgiac
{
    float x1, x2, x3;
    float y1, y2, y3;
};

void nhaptg(tamgiac &tg)
{
    cout << "Toa do diem 1 (x,y)" << endl;
    cout << "Nhap x:";
    cin >> tg.x1;
    cout << "Nhap y:";
    cin >> tg.y1;

    cout << "Toa do diem 2 (x,y)" << endl;
    cout << "Nhap x:";
    cin >> tg.x2;
    cout << "Nhap y:";
    cin >> tg.y2;

    cout << "Toa do diem 3 (x,y)" << endl;
    cout << "Nhap x:";
    cin >> tg.x3;
    cout << "Nhap y:";
    cin >> tg.y3;
}

void xuattg(tamgiac tg)
{
    cout << "((" << tg.x1 << "," << tg.y1 << ")";
    cout << ";(" << tg.x2 << "," << tg.y2 << ")";
    cout << ";(" << tg.x3 << "," << tg.y3 << "))" << endl;
}

int main()
{
    tamgiac tg;
    nhaptg(tg);
    xuattg(tg);
    return 0;
}