/*
                                                                |
Kiểm tra điểm có thuộc phần tư thứ III không?              II   |   I
                                                        ________|________
                                                                |
                                                          III   |   IV
                                                                |
//*Điểm (0,0) là điểm gốc                                       
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

bool goct3(toado A)
{
    return A.x<0 && A.y<0;
}

int main()
{
    toado A;
    nhaptoado(A);
    xuattoado(A);
    cout << (goct3(A) ? "Thuoc goc phan tu thu III" : "Khong thuoc goc phan tu thu III") << endl;
    return 0;
}