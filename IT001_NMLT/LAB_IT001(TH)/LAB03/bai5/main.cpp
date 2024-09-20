#include <iostream>

using namespace std;

//5.1
int tong_n(int n)
{
    return n*(n+1)/2;
}

//5.2
int tong_n2(int n)
{
    return tong_n(n)*10+2*n;
}

//5.3
float tong_s(int n)
{
    float s(0);
    for(int i(1); i<=n; i++)
        s += 1./i;
    return s;
}

//5.4
int tong_gt(int n)
{
    int gt(1), s(0);
    for(int i(1); i<=n; i++)
    {
        gt *= i;
        s += gt;
    }
    return s;
}

//5.5
int gthua(int n)
{
    int gt(1);
    for(int i(1); i<=n; i++)
        gt *= i;
    return gt;
}

int main()
{
    cout << "Nhap n: ";
    int n, a;
    cin >> n;

    menu:
    cout << endl << endl;
    cout << "----------------------------------MENU----------------------------------" << endl;
    cout << "1: S = 1 + 2 + 3 + ... + n" << endl;
    cout << "2: S = 12 + 22 + 32 + ... + n2" << endl;
    cout << "3: S = 1 + 1/2 + 1/3 + ... + 1/n" << endl;
    cout << "4: S = 1! + 2! + 3! + ... + n!" << endl;
    cout << "5: S = 1 * 2 * 3 * ... * n" << endl;
    cout << "6: Nhap lai n" << endl;
    cout << "0: Ket thuc" << endl << endl;
    cout << "Choose: ";
    cin >> a;
    cout << endl;

    switch(a)
    {
        case 1:
            cout << "5.1: S = 1 + 2 + 3 + ... + n" << "\nS = " << tong_n(n) << endl;
            goto menu;
        case 2:
            cout << "5.2: S = 12 + 22 + 32 + ... + n2" << "\nS = " << tong_n2(n) << endl;
            goto menu;
        case 3:
            cout << "5.3: S = 1 + 1/2 + 1/3 + ... + 1/n" << "\nS = " << tong_s(n) << endl;
            goto menu;
        case 4:
            cout << "5.4: S = 1! + 2! + 3! + ... + n!" << "\nS = " << tong_gt(n) << endl;
            goto menu;
        case 5:
            cout << "5.5: S = 1 * 2 * 3 * ... * n" << "\nS = " << gthua(n) << endl;
            goto menu;
        case 6:
            cout << "Nhap n: ";
            cin >> n;
            goto menu;
        case 0:
            cout << "----------------------------------END----------------------------------";
    }

    return 0;
}
