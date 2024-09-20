#include <iostream>

using namespace std;

int main()
{
    float b,c;
    cout << "Nhap b: ";
    cin >> b;
    cout << "Nhap c: ";
    cin >> c;
    if(b==0 && c==0) cout << "PT Vo so nghiem";
    if(b==0 && c!=0) cout << "PT Vo nghiem";
    if(b!=0) cout << "x = " << -c/b;

    return 0;
}
