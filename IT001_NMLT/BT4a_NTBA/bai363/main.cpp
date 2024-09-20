/*
liệt kê cột tăng dần trong ma trận số thực
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#define M 100

using namespace std;

bool cottang(float a[][M], int dong, int vtcot)
{
    for(int i(0); i<dong-1; i++)
        {
            if(a[i][vtcot] >= a[i+1][vtcot])
                return false;
        }
    return true;
}
void xuatcottang(float a[][M], int dong, int cot)
{
    cout << "\nCac cot tang dan" << endl;
    for(int j(0); j<cot; j++)
    {
        if(cottang(a,dong,j))
        {
            for(int i(0); i<dong; i++)
                cout << setprecision(2) << fixed << a[i][j] << endl;
            cout << endl << endl;
        }
    }
}

int main()
{
    srand(time(0));
    float a[M][M];
    int dong, cot;
    cout << "Nhap dong:";
    cin >> dong;
    cout << "Nhap cot:";
    cin >> cot;
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
        {
            a[i][j]= -20 + ((float)rand() / RAND_MAX) * 40;
            cout << setprecision(2) << fixed << a[i][j] << "   ";
        }
        cout << endl;
    }

    xuatcottang(a,dong,cot);
    return 0;
}
