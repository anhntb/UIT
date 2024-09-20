/*
Tìm số chẵn lớn nhất trong ma trận các số nguyên
*/

#include <iostream>
#include <ctime>
#define M 100

using namespace std;

int maxchan(int a[][M], int dong, int cot)
{
    int i(0), j(0);
    int maxchan(-1); //* không tồn tại chẵn -> hàm = -1

//todo tìm chẵn đầu
    do
    {
        for(j=0; j<cot; j++)
            if(a[i][j]%2 == 0)
            {
                maxchan = a[i][j];
                i--; //a[i][j] vị trí chẵn đầu
                break;
            }
        i++;
    }while(a[i][j]%2 != 0 && i<dong);

//todo tìm chẵn max
    j++; //j chạy phần tử kế tiếp
    for(i; i<dong; i++)
    {
        for(j; j<cot; j++)
        {
            if(a[i][j] > maxchan && a[i][j]%2 == 0)
                maxchan = a[i][j];
        }
        j=0; //j chạy từ đầu khi xét dòng kế tiếp
    }
    return maxchan;
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

    int maxc = maxchan(a,dong,cot);
    if(maxc==(-1))
        cout << "Khong ton tai chan";
    else 
        cout << "Max chan = " << maxc;
    return 0;
}
