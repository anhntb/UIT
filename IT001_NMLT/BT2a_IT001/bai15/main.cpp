#include <iostream>

using namespace std;

int main()
{
    float n,S(0),S1(0);
    cin >> n;
    for(int i=1; i<=n; i++)
    {
        S1+=i;
        S+=1/S1;
    }
    cout << S;
    return 0;
}
