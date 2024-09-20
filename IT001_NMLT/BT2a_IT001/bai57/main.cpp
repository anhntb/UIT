#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n>0)
        if((n%10)%2==0) n/=10;
        else
        {
            cout << "no";
            exit(0);
        }
    cout << "yes";
    return 0;
}
