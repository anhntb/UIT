#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for(int i=n; i>=1; i--)
    if(n%i==0 && i%2==1)
    {
        cout << i;
        break;
    }
    return 0;
}
