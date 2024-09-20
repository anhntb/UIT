#include <iostream>

using namespace std;

int main()
{
    int d,m,y;
    cin >> d >> m >> y;
    cout << "a) " << d << "/" << m << "/" << y << endl;
    cout << "b) " << d << "/" << m << "/" << ( y%100 < 10 ? "0" : "" ) << y%100 << endl;
    cout << "c) " << y << "/" << m << "/" << d << endl;
    return 0;
}
