#include <iostream>

using namespace std;

int main()
{
    int n;
    float S(2);
    cin >> n;
    if(n<1)
    {
        cout << 0;
        exit(0);
    }
    for(float i=1; i<=n; i++) S=1+1/S;
    cout << S-1;
    return 0;
}
