/*
Tìm giá trị nguyên tố lớn nhất trong ma trận vuông các số nguyên
Không tìm thấy hoặc không phải ma trận vuông, trả về -1
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
    for(int i(2); i<=sqrt(n); i++)
        if(n%i == 0) return false;
    return true;
}
int slduong(int a[][M], int dong, int cot)
{
    if(dong!=cot) return -1;
    int max_n(2);
    bool flag = false; //kiểm tra có tồn tại số nguyên tố
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
        {
            if(ngto(a[i][j]) && max_n<a[i][j])
            {
                max_n=a[i][j];
                flag=true;
            }
        }
    }
    if(not flag) return -1;
    return max_n;
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

    if(slduong(a,dong,cot) == -1) 
        cout << "Khong la MT vuong hoac khong co so nguyen to";
    else 
        cout << "So nguyen to max = " << slduong(a,dong,cot);
    return 0;
}