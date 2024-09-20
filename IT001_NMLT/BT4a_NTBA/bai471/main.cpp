/*
Tính tích 2 ma trận
*/

#include <iostream>
#include <ctime>
#define M 100

struct mang2ch 
{
    int arr[M][M];
    int dong, cot;
};

using namespace std;

//todo tạo ma trận
void taomatran(mang2ch &a)
{
    cout << "Nhap dong: ";
    cin >> a.dong;
    cout << "Nhap cot: ";
    cin >> a.cot;

    for(int i(0); i<a.dong; i++)
    {
        for(int j(0); j<a.cot; j++)
        {
            a.arr[i][j]= -30 + rand()%61; //random số nguyên [-30;30]
        } 
    }
}

//todo xuất mảng
void xuat(mang2ch a)
{
    for(int i(0); i<a.dong; i++)
        {
            for(int j(0); j<a.cot; j++)
            {
                cout << a.arr[i][j] << "\t";
            } 
            cout << endl;
        }
}

//todo tích 2 ma trận
void tichmatran(mang2ch a, mang2ch b, mang2ch &kq)
{
    cout << "-----------------------------------------\n";
    if(a.cot != b.dong) 
    {
        cout << "Khong ton tai ma tran tich: ma tran 1 x ma tran 2";
        goto end;
    }
    
    cout << "Tich 2 ma tran\n";
    kq.dong = a.dong;
    kq.cot = b.cot;
    for(int i(0); i<kq.dong; i++)
    {
        for(int j(0); j<kq.cot; j++)
        {
            int tmp(0);
            while(tmp<a.cot)
            {
                kq.arr[i][j] += a.arr[i][tmp]*b.arr[tmp][j];
                tmp++;
            }
        }
    }
    xuat(kq);

    end:;
}


int main()
{
    srand(time(0));
    mang2ch a, b, kq;

    cout << "Tao ma tran 1" << endl;
    taomatran(a);
    xuat(a);

    cout << "\nTao ma tran 2" << endl;
    taomatran(b);
    xuat(b);

    tichmatran(a,b,kq);
    return 0;
}