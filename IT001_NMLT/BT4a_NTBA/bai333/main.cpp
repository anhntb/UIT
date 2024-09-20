/*
Tính tổng các số hoàn thiện trong ma trận các số nguyên
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

int tonghoanthien(int a[][M], int dong, int cot)
{
    int s(0);
    for(int i(0); i<dong; i++)
        for(int j(0); j<cot; j++)
            if(hoanthien(a[i][j]))
                s+=a[i][j];
    return s;
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

    cout << "Tong cac so hoan thien = " << tonghoanthien(a,dong,cot) << endl;
    return 0;
}
