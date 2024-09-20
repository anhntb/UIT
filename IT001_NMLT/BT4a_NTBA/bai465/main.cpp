/*
Đưa các giá trị chẵn về đầu ma trận vuông các số nguyên
*/

#include <iostream>
#include <ctime>
#include <cmath>
#define M 100

using namespace std;

void chanvedau(int a[][M], int n)
{
    for(int i(0); i<n; i++)
    {
        for(int j(0); j<n; j++)
        {
            if(i==j && i==(n-1)) goto xuat;
            if(a[i][j]%2 != 0)
            {
                int y(j+1);
                for(int x(i); x<n; x++)
                {
                    for(y; y<n; y++)
                    {
                        if(a[x][y]%2 == 0)
                        {
                            swap(a[i][j], a[x][y]);
                            if(x==y && x==(n-1)) goto xuat;
                            goto next;
                        }
                    }
                    y=0;
                }
            }
            next:; //! phải kết thúc lệnh trước dấu "}"
        } 
    }

    xuat:
        //*Xuất mảng
        cout << "------------------------------------------------------\n";
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
            a[i][j]= -30 + rand()%61; //random số nguyên [-30;30]
            cout << a[i][j] << "\t";
        } 
        cout << endl;
    }

    chanvedau(a,n);
    return 0;
}