/*
Chiếu gương ma trận theo trục dọc
*/

#include <iostream>
#include <ctime>
#define M 100

using namespace std;

void changiam(int a[][M], int dong, int cot)
{
    cout << "--------------------------------------------------------------\n";
    for(int j(0); j<cot/2; j++)
    {
        for(int i(0); i<dong; i++)
            swap(a[i][j], a[i][cot-1-j]);
    }

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
    
    changiam(a,dong,cot);
    return 0;
}