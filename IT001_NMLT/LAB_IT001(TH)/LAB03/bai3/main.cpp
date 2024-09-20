#include <iostream>

using namespace std;

void check(float &n)
{
    while(n<-89 || n>90)
    {
        cout << "\nError!\n" << "Nhap n: ";
        cin >> n;
    }
    cout << "\nn = " << n;
}
int main()
{
    float n;
    cout << "Nhap n thuoc [-89,90]" << endl;
    cout << "Nhap n: ";
    cin >> n;
    check(n);
    return 0;
}
