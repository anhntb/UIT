#include <iostream>

using namespace std;

int main()
{
    float a,b,c;
    cin >> a >> b >> c;
    float maxN = a;
    if(maxN < b) maxN = b;
    if(maxN < c) maxN = c;
    cout << "Max: " << maxN;
    return 0;
}
