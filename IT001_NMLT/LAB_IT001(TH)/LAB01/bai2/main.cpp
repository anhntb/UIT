#include <iostream>
#include <math.h> //round()

using namespace std;

int main()
{
    int a,b;
    cin >> a >> b;
    cout << "Tong: " << a+b << endl;
    cout << "Hieu: " << a-b << endl;
    cout << "Tich: " << a*b << endl;
    cout << "Thuong: ";
    cout << "+ Lam 2 so sau dau cham: " << (a*100/b)/100. << endl;
    cout << "        + Lam 3 so sau dau cham: " << (a*1000/b)/1000.;
    return 0;
}
