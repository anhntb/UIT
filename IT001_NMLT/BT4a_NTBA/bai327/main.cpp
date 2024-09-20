/*
Tính tổng các giá trị nằm trên biên của ma trận
*/

#include <iostream>
#define M 100

using namespace std;

float tongbien(float a[][M], int dong, int cot)
{
    int s(0);
    for(int i(0); i<dong; i++)
        for(int j(0); j<cot; j++)
            if(i==0 || i==(dong-1) || j==0 || j==(cot-1))
                s+=a[i][j];
    return s;
}

int main()
{
    float a[M][M];
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

    cout << "Tong gia tri bien = " << tongbien(a,dong,cot) << endl;
    return 0;
}
