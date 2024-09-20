#include <iostream>
#include <cstring>

using namespace std;
bool chanam(int n)
{
    return n%2==0 && n<0;
}
int main()
{
    int n;
    cout << "Nhap n: ";
    cin >> n;
    cout << chanam(n);
    return 0;

}
