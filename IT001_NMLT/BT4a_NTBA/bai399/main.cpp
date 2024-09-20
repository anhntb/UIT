/*
Dịch trái xoay vòng, các giá trị nằm trên biên của ma trận
*/

#include <iostream>
#include <ctime>
#define M 100

using namespace std;

void bienxoaytrai(int a[][M], int dong, int cot)
{
    cout << "Dich trai xoay vong phan tu bien\n";
    int tmp_d0, tmp_c0, tmp_de; //dòng đầu, cột đầu, dòng cuối

    //* chạy dòng trên
    tmp_d0=a[0][0];
    for(int j(0); j<cot-1; j++)
        a[0][j]=a[0][j+1];

    //* chạy bên trái
    tmp_c0=a[dong-1][0];
    for(int i(dong-1); i>=2; i--)
        a[i][0]=a[i-1][0];

    //* chạy dòng dưới
    tmp_de=a[dong-1][cot-1];
    for(int j(cot-1); j>=2; j--)
        a[dong-1][j]=a[dong-1][j-1];

    //* chạy bên phải
    for(int i(0); i<dong-2; i++)
        a[i][cot-1]=a[i+1][cot-1];

    //* lắp 3 vị trí trống
    a[1][0]=tmp_d0;
    a[dong-1][1]=tmp_c0;
    a[dong-2][cot-1]=tmp_de;

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
    
    bienxoaytrai(a,dong,cot);
    return 0;
}
