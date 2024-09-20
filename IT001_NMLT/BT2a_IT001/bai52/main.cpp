#include <iostream>

using namespace std;

int main()
{
    int n, minN(9);
    cin >> n;
    while(n>0)
    {
        if(n%10 < minN) minN = n%10;
        n/=10;
    }
    cout << minN;
    return 0;
}
