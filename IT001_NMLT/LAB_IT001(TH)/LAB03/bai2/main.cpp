#include <iostream>

using namespace std;
int check(int n)
{
    return (n<0 && n%2==(-1)) ? -1 : (n>0 && n%2==0);
}
int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << check(n);
    return 0;
}
