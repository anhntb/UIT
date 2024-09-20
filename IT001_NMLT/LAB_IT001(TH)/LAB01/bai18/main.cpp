#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    cin >> a >> b >> c;
    int maxN = a, minN = a;
    if(maxN < b) maxN = b;
    if(maxN < c) maxN = c;
    if(minN > b) minN = b;
    if(minN > c) minN = c;
    cout << "max: " << maxN << endl;
    cout << "min: " << minN << endl;
    return 0;
}
