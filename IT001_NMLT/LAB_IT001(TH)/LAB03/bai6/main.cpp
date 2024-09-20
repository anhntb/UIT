#include <iostream>

using namespace std;

int fibonacy(int n)
{
    if(n==1 || n==2) return 1;
    return fibonacy(n-1) + fibonacy(n-2);
}

int main()
{
    cout << "Nhap n: ";
    int n;
    cin >> n;

    cout << "\n" << n << " phan tu dau tien cua Fibonacy" << endl;
    for(int i(1); i<=n; i++)
        cout << "f[" << i << "]: " << fibonacy(i) << endl;

    return 0;
}
