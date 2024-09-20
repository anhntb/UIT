#include <iostream>

using namespace std;

int main()
{
    int n;
    float x, S(0);
    cout << "Nhap n: ";
    cin >> n;
    cout << "Nhap x: ";
    cin >> x;

    float x_n(1), mau(0); // x_n = x^n
    for(int i=1; i<=n; i++)
    {
        x_n *= x;
        mau += i;
        S += x_n/mau;
    }

    cout << "S = " << S;

    return 0;
}
