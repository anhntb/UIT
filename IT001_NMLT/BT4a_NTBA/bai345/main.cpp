/*
Tính tổng các phần tử cực trị trong ma trận số thực,
phần tử được gọi là cực trị khi nó lớn hơn hoặc nhỏ hơn các phần tử xung quanh nó
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#define M 100

struct mang2ch
{
    float arr[M][M];
    int dong, cot;
};

using namespace std;

bool cuctri(mang2ch a, int vtd, int vtc)
{
    bool cucdai(true), cuctieu(true);
    for(int i(-1); i<=1; i++)
    {
        for(int j(-1); j<=1; j++)
        {
            if((vtd+i) >= 0 && (vtd+i) < a.dong && (vtc+j) >= 0 && (vtc+j) < a.cot && (i != 0 || j != 0))
            {
                if(a.arr[vtd][vtc] <= a.arr[vtd+i][vtc+j])
                    cucdai = false;
                if(a.arr[vtd][vtc] >= a.arr[vtd+i][vtc+j])
                    cuctieu = false;
            }
        }
    }
    return cucdai || cuctieu;
}

float tongcuctri(mang2ch a)
{
    float s(0);
    for(int i(0); i<a.dong; i++)
    {
        for(int j(0); j<a.cot; j++)
        {
            if(cuctri(a,i,j))
                s += a.arr[i][j];
        }
    }
    return s;
}

int main()
{
    srand(time(0));
    mang2ch a;
    cout << "Nhap dong:";
    cin >> a.dong;
    cout << "Nhap cot:";
    cin >> a.cot;
    for(int i(0); i<a.dong; i++)
    {
        for(int j(0); j<a.cot; j++)
        {
            a.arr[i][j]= -20 + ((float)rand() / RAND_MAX) * 40; //rand số thực [-20;20]
            cout << setprecision(2) << fixed << a.arr[i][j] << "   ";
        }
        cout << endl;
    }

    cout << "Tong cuc tri = " << tongcuctri(a);
    return 0;
}
