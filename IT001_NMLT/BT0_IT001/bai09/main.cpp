#include <iostream>

using namespace std;

int UCLN(int a, int b)
{
    if(b==0) return a;
    else return UCLN(b, a%b);
}
int main()
{
    int a, b;
    cout << "Nhap a: ";
    cin >> a;
    cout << "Nhap b: ";
    cin >> b;

    cout << "UCLN(" << a << "," << b << ") = " << UCLN(a,b);

    return 0;
}
