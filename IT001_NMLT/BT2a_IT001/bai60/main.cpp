#include <iostream>

using namespace std;

int main()
{
    int n, so(10);
    cin >> n;
    while(n>0)
        if(n%10 < so)
        {
            so = n%10;
            n/=10;
        }
        else
        {
            cout << "no";
            exit(0);
        }
    cout << "yes";
    return 0;
}
