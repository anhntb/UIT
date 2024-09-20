/*
Liệt kê các dòng có nhiều số chẵn nhất trong ma trận các số nguyên
*/

#include <iostream>
#include <ctime>
#define M 100

using namespace std;

//todo đếm số lượng chẵn trên 1 dòng
int slchan(int a[][M], int vtdong, int cot)
{
    int cnt(0);
    for(int j(0); j<cot; j++)
        if(a[vtdong][j]%2 == 0)
            cnt++;
    return cnt;
}

void dnhieuchan(int a[][M], int dong, int cot)
{
    cout << "\nCac dong nhieu chan nhat" << endl;

    int slmax = slchan(a,0,cot);
    for(int i(1); i<dong; i++)
        if(slmax < slchan(a,i,cot))
            slmax = slchan(a,i,cot);
    
    for(int i(0); i<dong; i++)
    {
        if(slmax == slchan(a,i,cot))
        {
            for(int j(0); j<cot; j++)
                cout << a[i][j] << "\t";
            cout << endl;
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

    dnhieuchan(a,dong,cot);
    return 0;
}
