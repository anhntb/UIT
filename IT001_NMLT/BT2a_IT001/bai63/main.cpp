#include <iostream>

using namespace std;

int ucln(int a, int b)
{
    if(b == 0) return a;
    return ucln(b, a%b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << (a*b) / ucln(a,b);
    return 0;
}
