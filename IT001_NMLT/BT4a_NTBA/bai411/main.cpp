/*
Xuất các giá trị chẵn giảm dần trong mảng 2 chiều
*/

#include <iostream>
#include <ctime>
#define M 100

using namespace std;

void changiam(int a[][M], int dong, int cot)
{
    cout << "--------------------------------------------------------------\n";
    int n(0);
    int b[100]; //lưu giá trị chẵn

    //* tách phần tử chẵn vào mảng 1 chiều
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

    //* xếp giảm dần
    for(int i(0); i<n-1; i++)
    {
        for(int j(i+1); j<n; j++)
        {
            if(b[i]<b[j])
                swap(b[i],b[j]);
        } 
    }

    for(int i(0); i<n; i++)
        cout << b[i] << "\t";
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
    
    changiam(a,dong,cot);
    return 0;
}