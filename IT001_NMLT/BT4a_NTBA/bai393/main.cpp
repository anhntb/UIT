/*
Hoán vị 2 cột trên ma trận
*/

#include <iostream>
#include <ctime>
#define M 100

using namespace std;

void hoanvi2cot(int a[][M], int dong, int cot, int vtcot1, int vtcot2)
{
    for(int i(0); i<dong; i++)
        swap(a[i][vtcot1-1], a[i][vtcot2-1]);

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

    int vtcot1, vtcot2;
    cout << "Nhap lan luot 2 cot muon hoan vi: ";
    cin >> vtcot1 >> vtcot2;
    hoanvi2cot(a,dong,cot,vtcot1,vtcot2);
    return 0;
}
