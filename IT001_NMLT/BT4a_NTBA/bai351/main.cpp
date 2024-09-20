/*
Kiểm tra ma trận có toàn dương hay không
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#define M 100

using namespace std;

bool MTduong(float a[][M], int dong, int cot)
{
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
            {
                if(a[i][j]<=0)
                    return false;
            }
    }
    return true;
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

    cout << (MTduong(a,dong,cot) ? "Ma tran toan duong" : "Ma tran khong toan duong") << endl;

    return 0;
}
