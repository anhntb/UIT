#include <iostream>

using namespace std;

int main()
{
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int minN = a;
    if(minN > b) minN = b;
    if(minN > c) minN = c;
    if(minN > d) minN = d;
    cout << "Min: " << minN;
    return 0;
}
