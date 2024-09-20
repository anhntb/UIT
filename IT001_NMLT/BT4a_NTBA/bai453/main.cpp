/*
Đếm số lượng giá trị dương trên đường chéo chính
trong ma trận vuông các số thực.
Không tìm thấy hoặc không phải ma trận vuông, trả về -1
*/

#include <iostream>
#include <ctime>
#include <cmath>
#define M 100

using namespace std;

int slduong(float a[][M], int dong, int cot)
{
    if(dong!=cot) return -1;
    bool flag = false; //kiểm tra có tồn tại số dương
    int cnt(0);
    for(int i(0); i<dong; i++)
    {
        if(a[i][i]>0)
        {
            cnt++;
            flag=true;
        }
    }
    if(not flag) return -1;
    return cnt;
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
            a[i][j]= -20 + ((float)rand()/RAND_MAX)*40; //random số thực [-20;20]
            a[i][j]= round(a[i][j]*10)/10; //làm tròn 1 chữ số thập thân
            cout << a[i][j] << "\t";
        } 
        cout << endl;
    }

    if(slduong(a,dong,cot) == -1) 
        cout << "Khong la MT vuong hoac khong co so duong";
    else 
        cout << "So luong so duong = " << slduong(a,dong,cot);
    return 0;
}