#include <iostream>
#include <ctime>
#include <cmath>
#define M 100

using namespace std;

struct DOAN
{
    int x,y;
    float b[M];
    int nb;
};

//1.a
void mangtudong(float a[], int &n)
{
    srand(time(0));
    float r;
    n=10 + rand()%(20-10+1);
    for(int i(0); i<n; i++)
    {
        r=(float)rand()/RAND_MAX;
        a[i]=round((r*(339+268) + (-268))*100)/100.;
        if(a[i]==339)
            a[i]=339-0.01;
        if(a[i]==(-268))
            a[i]=(-268)+0.01;
    }
}

//1.b
void xuat(float a[], int n)
{
    for(int i(0); i<n; i++)
        cout << a[i] << "   ";
    cout << endl;
}

//1.c
void tongtich(float a[], int n, float &tong, float &tich)
{
    tong=0; tich=1;
    for(int i(0); i<n; i++)
    {
        tong+=a[i];
        tich*=a[i];
    }
}

//1.d
int count_x(float a[], int n, float x)
{
    int d(0);
    for(int i(0); i<n; i++)
        if(a[i]==x) d++;
    return d;
}

//1.e
void ptuchan(float a[], int n, float b[], int &nb)
{
    nb=0;
    for(int i(0); i<n; i++)
        if((int)a[i]%2==0)
        {
            b[nb]=a[i];
            nb++;
        }
}

//1.f
int vtmin(float a[], int n)
{
    float min_a=a[0];
    int vt=0;
    for(int i(1); i<n; i++)
        if(min_a>a[i])
        {
            min_a=a[i];
            vt=i;
        }
    return vt;
}

//1.g
void xuatnguoc(float a[], int n)
{
    for(int i(n-1); i>=0; i--)
        cout << a[i] << "   ";
    cout << endl;
}

//1.h
void ptuam(float a[], int n, float b[], int &nb)
{
    nb=0;
    for(int i(0); i<n; i++)
        if(a[i]<0)
        {
            b[nb]=a[i];
            nb++;
        }
}

//1.i
void ptudoan(float a[], int n, DOAN &doan)
{
    doan.nb=0;
    for(int i(0); i<n; i++)
        if(a[i]>=doan.x && a[i]<=doan.y)
        {
            doan.b[doan.nb]=a[i];
            doan.nb++;
        }
}

//1.j
int slptudoan(float a[], int n, DOAN doan)
{
    int sl=0;
    for(int i(0); i<n; i++)
        if(a[i]>=doan.x && a[i]<=doan.y)
            sl++;
    return sl;
}

int main()
{
    float a[M], b[M];
    int n,nb;
    float so;
    float tong,tich;
    DOAN doan;
    char ch;

    menu:
        cout << "-------------------------------MENU-------------------------------" << endl;
        cout << "a: Tao mang tu dong" << endl;
        cout << "b: Xuat mang" << endl;
        cout << "c: Tong, tich cac gia tri trong mang" << endl;
        cout << "d: Dem so lan xuat hien 1 phan tu x bat ky" << endl;
        cout << "e: Cac phan tu chan(chi xet phan nguyen cua phan tu)" << endl;
        cout << "f: Vi tri phan tu nho nhat" << endl;
        cout << "g: Xuat mang dao nguoc" << endl;
        cout << "h: Cac so am trong mang" << endl;
        cout << "i: Cac gia tri thuoc doan [x,y]" << endl;
        cout << "j: So luong gia tri thuoc doan [x,y]" << endl;
        cout << "0: Ket thuc" << endl << endl;

    cin >> ch;
    switch(ch)
    {
        case 'a':
            cout << "1.a: Tao mang tu dong" << endl;
            mangtudong(a,n);
            cout << endl << endl << endl;
            goto menu;
        case 'b':
            cout << "1.b: Xuat mang" << endl;
            xuat(a,n);
            cout << endl << endl << endl;
            goto menu;
        case 'c':
            cout << "1.c: Tong, tich cac gia tri trong mang" << endl;
            tongtich(a,n,tong,tich);
            cout << "Tong = " << tong << endl;
            cout << "Tich = " << tich << endl;
            cout << endl << endl << endl;
            goto menu;
        case 'd':
            cout << "1.d: Dem so lan xuat hien 1 phan tu x bat ky" << endl;
            cout << "Nhap so: ";
            cin >> so;
            cout << count_x(a,n,so) << endl;
            cout << endl << endl << endl;
            goto menu;
        case 'e':
            cout << "1.e: Cac phan tu chan(chi xet phan nguyen cua phan tu)" << endl;
            ptuchan(a,n,b,nb);
            xuat(b,nb);
            cout << endl << endl << endl;
            goto menu;
        case 'f':
            cout << "1.f: Vi tri phan tu nho nhat" << endl;
            cout << "Vi tri = " << vtmin(a,n) << endl;
            cout << endl << endl << endl;
            goto menu;
        case 'g':
            cout << "1.g: Xuat mang dao nguoc" << endl;
            xuatnguoc(a,n);
            cout << endl << endl << endl;
            goto menu;
        case 'h':
            cout << "1.h: Cac so am trong mang" << endl;
            ptuam(a,n,b,nb);
            xuat(b,nb);
            cout << endl << endl << endl;
            goto menu;
        case 'i':
            cout << "1.i: Cac gia tri thuoc doan [x,y]" << endl;
            cout << "Nhap [x,y]: ";
            cin >> doan.x >> doan.y;
            ptudoan(a,n,doan);
            xuat(doan.b,doan.nb);
            cout << endl << endl << endl;
            goto menu;
        case 'j':
            cout << "1.j: So luong gia tri thuoc doan [x,y]" << endl;
            cout << "Nhap [x,y]: ";
            cin >> doan.x >> doan.y;
            cout << "So luong = " << slptudoan(a,n,doan) << endl;
            cout << endl << endl << endl;
            goto menu;
        case '0':
            cout << "-------------------------------END-------------------------------" << endl;
    }

    return 0;
}
















