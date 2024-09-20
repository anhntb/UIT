#include <iostream>
#include <ctime>
#include <cmath>
#define M 100

using namespace std;

//2.a
void taomang(int a[][M], int dong, int cot)
{
    for(int i(0); i<dong; i++)
        for(int j(0); j<cot; j++)
            a[i][j]= -39 + rand()%(79+39+1);
}

//2.b
void xuat(int a[][M], int dong, int cot)
{
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
            cout << a[i][j] << "\t";
        cout << endl;
    }
}

//2.c
int maxarr(int a[][M], int dong, int cot)
{
    int max_a=a[0][0];
    for(int i(0); i<dong; i++)
        for(int j(0); j<cot; j++)
            if(max_a<a[i][j])
                max_a=a[i][j];
    return max_a;
}

//2.d
bool MTvuong(int a[][M], int dong, int cot)
{
    return dong==cot;
}

//2.e
void ptucheochinh(int a[][M], int dong, int cot)
{
    if(dong!=cot)
        cout << "Khong phai ma tran vuong, khong ton tai duong cheo chinh";
    else
        for(int i(0); i<dong; i++)
            cout << a[i][i] << "\t";
    cout << endl;
}

//2.f
void ptucheophu(int a[][M], int dong, int cot)
{
    if(dong!=cot)
        cout << "Khong phai ma tran vuong, khong ton tai duong cheo phu";
    else
        for(int i(0); i<dong; i++)
            cout << a[i][dong-1-i] << "\t";
    cout << endl;
}

//2.g
void mindong(int a[][M], int dong, int cot, int b[])
{
    int m;
    for(int i(0); i<dong; i++)
    {
        m=a[i][0];
        for(int j(1); j<cot; j++)
            if(m>a[i][j])
                m=a[i][j];
        b[i]=m;
    }
}

//2.h
void maxcot(int a[][M], int dong, int cot, int b[])
{
    int m;
    for(int j(0); j<cot; j++)
    {
        m=a[0][j];
        for(int i(1); i<dong; i++)
            if(m<a[i][j])
                m=a[i][j];
        b[j]=m;
    }
}

//2.i
bool toanchan(int a[][M], int dong, int cot)
{
    for(int i(0); i<dong; i++)
        for(int j(0); j<cot; j++)
            if(a[i][j]%2!=0)
                return false;
    return true;
}

//2.j
bool ngto(int n)
{
    if(n<2) return false;
    if(n==2) return true;
    for(int i(2); i<=sqrt(n); i++)
        if(n%i==0) return false;
    return true;
}
void prtngto(int a[][M], int dong, int cot)
{
    bool flag=false; //Kiểm tra tồn tại số nguyên tố
    for(int i(0); i<dong; i++)
        for(int j(0); j<cot; j++)
            if(ngto(a[i][j]))
            {
                cout << a[i][j] << "\t";
                flag=true;
            }
    if(not flag) cout << "Khong co so nguyen to";
    cout << endl;
}

//2.k
int count_n(int a[][M], int dong, int cot, int n)
{
    int cnt(0);
    for(int i(0); i<dong; i++)
        for(int j(0); j<cot; j++)
            if(a[i][j]==n)
                cnt++;
    return cnt;
}
void tansuat(int a[][M], int dong, int cot)
{
    for(int i(0); i<dong; i++)
    {
        for(int j(0); j<cot; j++)
            cout << count_n(a,dong,cot,a[i][j]) << "\t";
        cout << endl;
    }
}

int main()
{
    srand(time(0));
    int a[M][M];
    int b[M];
    char ch;

    menu:
        cout << "-------------------------------MENU-------------------------------" << endl;
        cout << "a: Tao mang tu dong" << endl;
        cout << "b: Xuat mang 2 chieu dang ma tran" << endl;
        cout << "c: Phan tu lon nhat trong mang" << endl;
        cout << "d: Kiem tra ma tran vuong" << endl;
        cout << "e: Cac phan tu nam tren duong cheo chinh" << endl;
        cout << "f: Cac phan tu nam tren duong cheo phu" << endl;
        cout << "g: Gia tri nho nhat tren tung dong" << endl;
        cout << "h: Gia tri lon nhat tren tung cot" << endl;
        cout << "i: Kiem tra mang toan gia tri chan" << endl;
        cout << "j: Liet ke cac so nguyen to" << endl;
        cout << "k: Liet ke tan suat cua cac gia tri xuat hien trong mang" << endl;
        cout << "0: Ket thuc" << endl << endl;

    cin >> ch;
    switch(ch)
    {
        case 'a':
            cout << "1.a: Tao mang tu dong" << endl;
            int dong,cot;
            cout << "Nhap dong:";
            cin >> dong;
            cout << "Nhap cot:";
            cin >> cot;
            taomang(a,dong,cot);
            cout << endl << endl << endl;
            goto menu;
        case 'b':
            cout << "1.b: Xuat mang 2 chieu dang ma tran" << endl;
            xuat(a,dong,cot);
            cout << endl << endl << endl;
            goto menu;
        case 'c':
            cout << "1.c: Phan tu lon nhat trong mang" << endl;
            cout << "Max = " << maxarr(a,dong,cot) << endl;
            cout << endl << endl << endl;
            goto menu;
        case 'd':
            cout << "1.d: Kiem tra ma tran vuong" << endl;
            cout << (MTvuong(a,dong,cot) ? "La ma tran vuong" : "Khong phai ma tran vuong") << endl;
            cout << endl << endl << endl;
            goto menu;
        case 'e':
            cout << "1.e: Cac phan tu nam tren duong cheo chinh" << endl;
            ptucheochinh(a,dong,cot);
            cout << endl << endl << endl;
            goto menu;
        case 'f':
            cout << "1.f: Cac phan tu nam tren duong cheo phu" << endl;
            ptucheophu(a,dong,cot);
            cout << endl << endl << endl;
            goto menu;
        case 'g':
            cout << "1.g: Gia tri nho nhat tren tung dong" << endl;
            mindong(a,dong,cot,b);
            for(int i(0); i<dong; i++)
                cout << b[i] << endl;
            cout << endl << endl << endl;
            goto menu;
        case 'h':
            cout << "1.h: Gia tri lon nhat tren tung cot" << endl;
            maxcot(a,dong,cot,b);
            for(int i(0); i<cot; i++)
                cout << b[i] << "\t";
            cout << endl << endl << endl;
            goto menu;
        case 'i':
            cout << "1.i: Kiem tra mang toan gia tri chan" << endl;
            cout << (toanchan(a,dong,cot) ? "Mang toan gia tri chan" : "Mang khong toan chan") << endl;
            cout << endl << endl << endl;
            goto menu;
        case 'j':
            cout << "1.j: Liet ke cac so nguyen to" << endl;
            prtngto(a,dong,cot);
            cout << endl << endl << endl;
            goto menu;
        case 'k':
            cout << "1.j: Liet ke tan suat cua cac gia tri xuat hien trong mang" << endl;
            tansuat(a,dong,cot);
            cout << endl << endl << endl;
            goto menu;
        case '0':
            cout << "-------------------------------END-------------------------------" << endl;
    }
    return 0;
}
