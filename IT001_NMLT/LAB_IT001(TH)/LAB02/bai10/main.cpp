#include <iostream>

using namespace std;

int main()
{
    int n;
    do
    {
        cout << "Nhap n (n>0): ";
        cin >> n;
        if(n<=0) cout << "Error!!!" << endl;
    } while(n<=0);

    for(int i=1; i<=n; i++)
        if(n%i==0) cout << i << " ";
    return 0;
}
