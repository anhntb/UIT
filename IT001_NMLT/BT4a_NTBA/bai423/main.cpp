/*
Sắp xếp các phần tử trong ma trận tăng dần theo hình xoắn ốc
*/

#include <iostream>
#include <ctime>
#define M 100

using namespace std;

void xoanphaitang(int a[][M], int dong, int cot)
{
    cout << "------------------------------------\n";
    cout << "Tang dan theo hinh xoan oc\n";
    int b[100], n(0);
    
    //*biến mảng 2 chiều thành 1 chiều
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
        {
            b[n]=a[i][j];
            n++;
        } 
    }

    //*xếp tăng dần mảng 1 chiều b[]
    for(int i(0); i<n-1; i++)
    {
        for(int j(i+1); j<n; j++)
        {
            if(b[i]>b[j])
                swap(b[i],b[j]);
        } 
    }

//todo đưa mảng 1 chiều vào 2 chiều theo dạng xoắn ốc phải
    int top(0), bot(dong-1);
    int left(0), right(cot-1);
    int t(0); //biến chạy mảng b[]

    while(true)
    {
        //*chạy dòng trên
        for(int j(left); j<=right; j++)
        {
            a[top][j]=b[t];
            t++;
        }
        top++;
        if(t==n) break;

        //*chạy bên phải
        for(int i(top); i<=bot; i++)
        {
            a[i][right]=b[t];
            t++;
        }
        right--;
        if(t==n) break;

        //*chạy dòng dưới
        for(int j(right); j>=left; j--)
        {
            a[bot][j]=b[t];
            t++;
        }
        bot--;
        if(t==n) break;

        //*chạy bên trái
        for(int i(bot); i>=top; i--)
        {
            a[i][left]=b[t];
            t++;
        }
        left++;
        if(t==n) break;
    }

    //*Xuất mảng
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
    
    xoanphaitang(a,dong,cot);    
    return 0;
}