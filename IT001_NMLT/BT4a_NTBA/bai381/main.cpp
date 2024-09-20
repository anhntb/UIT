/*
Tìm giá trị xuất hiện nhiều nhất trong ma trận số thực
*/
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cmath>
#define M 100

using namespace std;

float xh_nhieunhat(float a[][M], int dong, int cot)
{
    int maxd(1);
    float xh_max=a[0][0];
    int b[dong][cot] = {0}; //mảng đánh dấu phần tử đã đếm

//! dòng 1 khởi tạo mặc định != 0   
    for(int j(0); j<cot; j++)
            b[0][j] = 0;

    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
            if(b[i][j] == 0)
            {
                b[i][j]=1; //đánh dấu đã đếm

                //todo đếm a[i][j]
                int x=i;
                int y=j+1;
                int dem(1);
                for(x; x<dong; x++)
                {
                    for(y; y<cot; y++)
                        if(a[x][y]==a[i][j])
                        {
                            dem++;
                            b[x][y]=1; //đánh dấu đã đếm
                        }
                    y=0; //xét từ đầu khi qua dòng mới
                }

                if(dem>maxd) 
                {
                    maxd=dem;
                    xh_max=a[i][j];
                }            
            }
    }
    return xh_max;
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
            a[i][j] = round(a[i][j]*10)/10; //làm tròn 1 chữ số
            cout << setw(7) << a[i][j];
        }
        cout << endl;
    }

    float n = xh_nhieunhat(a,dong,cot);
    cout << "Phan tu xuat hien nhieu nhat: " << n;
    return 0;
}
