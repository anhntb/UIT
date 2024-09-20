#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n>9) n/=10;
    cout << n;
    return 0;
}
