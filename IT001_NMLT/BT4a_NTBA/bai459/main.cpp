/*
Kiểm tra ma trận có phải ma phương bậc n không.
//*Một ma trận được gọi là ma phương khi tổng các phần tử dòng, cột,
//*đường chéo chính (phụ) bằng nhau.
*/

#include <iostream>
#include <ctime>
#include <cmath>
#define M 100

using namespace std;

bool maphuong(int a[][M], int n)
{
    //*kiểm tra đường chéo chính phụ
    int tongc(0), tongp(0);
    for(int i(0); i<n; i++)
    {
        tongc += a[i][i];
        tongp += a[i][n-1-i];
    }
    if(tongc != tongp) return false;

    //*kiểm tra các dòng
    int tong;
    for(int i(0); i<n; i++)
    {
        tong=0;
        for(int j(0); j<n; j++)
        {
            tong += a[i][j];
        }
        if(tongc != tong) return false;
    }

    //*kiểm tra các cột
    for(int j(0); j<n; j++)
    {
        tong=0;
        for(int i(0); i<n; i++)
        {
            tong += a[i][j];
        }
        if(tongc != tong) return false;
    }

    return true;
}

void xuat(int a[][M], int n)
{
    for(int i(0); i<n; i++)
    {
        for(int j(0); j<n; j++)
        {
            cout << a[i][j] << "\t";
        } 
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    int a[M][M];
    int n;
    cout << "Tao ma tran vuong so nguyen\n";
    cout << "Nhap n: ";
    cin >> n;

    for(int i(0); i<n; i++)
    {
        for(int j(0); j<n; j++)
        {
            cout << "a[" << i << "][" << j << "]:";
            cin >> a[i][j];
        } 
    }
    xuat(a,n);

    cout << (maphuong(a,n) ? "La ma phuong" : "Khong phai ma phuong") << endl;
    return 0;
}