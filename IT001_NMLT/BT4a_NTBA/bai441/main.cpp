/*
Tính tổng các phần tử trên đường chép phụ
*/

#include <iostream>
#include <ctime>
#define M 100

using namespace std;

int tongphu(int a[][M], int dong, int cot)
{
    int s(0);
    for(int i(0); i<dong; i++)
    {
        s += a[i][cot-1-i];
    }
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

    if(dong!=cot) 
        cout << "Khong la MT vuong, khong co duong cheo phu";
    else 
        cout << "Tong phan tu duong cheo phu = " << tongphu(a,dong,cot);
    return 0;
}