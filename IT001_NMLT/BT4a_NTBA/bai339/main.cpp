/*
Đếm số lượng số hoàn thiện trên 1 hàng trong ma trận các số nguyên
*/

#include <iostream>
#include <ctime>
#define M 100

using namespace std;

bool hoanthien(int n)
{
    if(n<1) return false;
    int s(0);
    for(int i(1); i<n; i++)
        if(n%i==0)
            s+=i;
    return s==n;
}

void demhtdong(int a[][M], int dong, int cot)
{
    int dem;
    for(int i(0); i<dong; i++)
    {
        dem=0;
        for(int j(0); j<cot; j++)
            if(hoanthien(a[i][j]))
                dem++;
        cout << "So luong so hoan thien dong " << i+1 << " = " << dem << endl;
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

    demhtdong(a,dong,cot);
    return 0;
}
