/*
Sắp xếp các phần tử chẵn trong ma trận các số nguyên giảm dần
bằng 2 phương pháp:
+ Sử dụng mảng phụ
+ Không dùng mảng phụ
*/

#include <iostream>
#include <ctime>
#define M 100

using namespace std;

//todo có dùng mảng phụ
void ychangiam(int a[][M], int dong, int cot)
{
    cout << "-----------------------------------------\n";
    cout << "Dung mang phu\n";
    int b[100], n(0);
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
        {
            if(a[i][j]%2 == 0)
            {
                b[n]=a[i][j];
                n++;
            }
        } 
    }

    //*Xếp mảng phụ giảm dần
    for(int i(0); i<n-1; i++)
    {
        for(int j(i+1); j<n; j++)
        {
            if(b[i]<b[j])
                swap(b[i],b[j]);
        }
    }

    //*Trả giá trị chẵn về ma trận
    n=0;
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
        {
            if(a[i][j]%2 == 0)
            {
                a[i][j]=b[n];
                n++;
            }
        } 
    }

    //*Xuất mảng
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
        {
            cout << a[i][j] << "\t";
        } 
        cout << endl;
    }
}

//todo không dùng mảng phụ
void nchangiam(int a[][M], int dong, int cot)
{
    cout << "-----------------------------------------\n";
    cout << "Khong dung mang phu\n";

    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot-1; j++)
        {
            if(a[i][j]%2 == 0) 
                //*chạy phần tử kế tiếp
                for(int x(i); x<dong; x++)
                {
                    for(int y(j+1); y<cot; y++)
                    {
                        if(a[x][y]%2 == 0 && a[i][j]<a[x][y])
                            swap(a[i][j],a[x][y]);
                    } 
                }
        } 
    }

    //*Xuất mảng
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
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
    int dong, cot;
    cout << "Nhap dong:";
    cin >> dong;
    cout << "Nhap cot:";
    cin >> cot;
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
        {
            a[i][j]= -20 + rand()%41;
            cout << a[i][j] << "\t";
        } 
        cout << endl;
    }
    
    ychangiam(a,dong,cot);
    nchangiam(a,dong,cot);

    return 0;
}