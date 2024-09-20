/*
Tính tích các giá trị lẻ trong mảng nguyên
*/

#include <iostream>
#define M 100

using namespace std;

int tichle(int a[][M], int dong, int cot)
{
    int p = 1;
    for(int i(0); i<dong; i++)
        for(int j(0); j<dong; j++)
            if(a[i][j]%2!=0)
                p*=a[i][j];
    return p;
}

int main()
{
    int a[M][M];
    int dong, cot;
    cout << "Nhap dong:";
    cin >> dong;
    cout << "Nhap cot:";
    cin >> cot;
    for(int i(0); i<dong; i++)
    {
        cout << "Nhap lan luot cac phan tu dong " << i << ": ";
        for(int j(0); j<cot; j++)
            cin >> a[i][j];
        cout << endl;
    }

    cout << "Tich cac gia tri le = " << tichle(a,dong,cot) << endl;
    return 0;
}
