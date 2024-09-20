/*
Tìm giá trị dương đầu tiên
Không tìm thấy trả về -1
*/
#include <iostream>
#include <ctime>
#include <iomanip>
#define M 100

using namespace std;

float duongdau(float a[][M], int dong, int cot)
{
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
            if(a[i][j] > 0)
                return a[i][j];
    }
    return -1;
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

    float n = duongdau(a,dong,cot);
    if(n == -1) cout << "Khong tim thay";
    else cout << "Duong dau: " << n;
    return 0;
}
