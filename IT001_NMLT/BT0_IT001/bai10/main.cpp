#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;

    int f_n, f_n2(1), f_n1(1); //f_n: fn , f_n2: f(n-2) , f_n1: f(n-1)
    if(n==1)
    {
        cout << "f1 = " << f_n2 << "     ";
        exit(0);
    }
    if(n==2)
    {
        cout << "f1 = " << f_n2 << "     ";
        cout << "f2 = " << f_n1 << "     ";
        exit(0);
    }
    cout << "f1 = " << f_n2 << "     ";
    cout << "f2 = " << f_n1 << "     ";

    for(int i=3; i<=n; i++)
    {
        f_n = f_n2 + f_n1;
        cout << "f" << i << " = " << f_n << "     ";

        f_n2 = f_n1;
        f_n1 = f_n;
    }

    return 0;
}
