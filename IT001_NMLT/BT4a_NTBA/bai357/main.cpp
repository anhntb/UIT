/*
Liệt kê các dòng có chứa số nguyên tố trong ma trận các số nguyên
*/
#include <iostream>
#include <ctime>
#include <cmath>
#define M 100

using namespace std;

bool ngto(int n)
{
    if(n<2) return false;
    if(n==2) return true;
    for(int i(2); i<=sqrt(n); i++) //! i phải chạy từ 2
        if(n%i==0) return false;
    return true;
}
void dongngto(int a[][M], int dong, int cot)
{
    cout << "Cac dong co so nguyen to" << endl;
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
        {
            if(ngto(a[i][j]))
            {
                for(int k(0); k<cot; k++)
                    cout << a[i][k] << "\t";
                cout << endl;
                break;
            }     
        }
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

    dongngto(a,dong,cot);
    return 0;
}
