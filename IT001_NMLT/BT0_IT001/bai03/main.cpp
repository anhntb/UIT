#include <iostream>
#include <math.h>

using namespace std;

//Cau a
bool doixung(int n)
{
    int n1(0), a=n;
    while(a!=0)
    {
        n1 = n1*10 + a%10;
        a /= 10;
    }
    if(n==n1) return true;
    else return false;
}

//Cau b
bool chinhphuong(int n)
{
    int a = sqrt(n);
    if(n==a*a) return true;
    else return false;
}

//Cau c
bool so_ngto(int n)
{
    if(n==1) return false;
    if(n==2) return true;
    int a = sqrt(n);
    for(int i=2; i<=a; i++)
        if(n%i==0) return false;
    return true;
}

//Cau d
void maxN_minN(int n)
{
    int maxN(0), minN(9);
    do
    {
        if(maxN < n%10) maxN = n%10;
        if(minN > n%10) minN = n%10;
        n /= 10;
    }while(n!=0);
    cout << "Max: " << maxN << "       Min: " << minN << endl;
}

//Cau e
bool tangdan(int n)
{
    while(n>9)
        if(n%10 < (n%100)/10) return false;
        else n/=10;
    return true;
}
bool giamdan(int n)
{
    while(n>9)
        if(n%10 > (n%100)/10) return false;
        else n/=10;
    return true;
}

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    //Cau a: so doi xung
    cout << "a) " << n << ( doixung(n) ? " la so doi xung" : " khong phai so doi xung" ) << endl;

    //Cau b: so chinh phuong
    cout << "b) " << n << (chinhphuong(n) ? " la so chinh phuong" : " khong phai so chinh phuong") << endl;

    //Cau c: so nguyen to
    cout << "c) " << n << (so_ngto(n) ? " la so nguyen to" : " khong phai so nguyen to") << endl;

    //Cau d: chu so max va min
    cout << "d) ";
    maxN_minN(n);

    //Cau e: cac chu so tang dan hay giam dan khong
    cout << "e) ";
    cout << ( (tangdan(n) || giamdan(n)) ? "Yes" : "No" );

    return 0;
}
