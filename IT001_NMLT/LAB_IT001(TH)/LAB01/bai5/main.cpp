#include <iostream>

using namespace std;

int main()
{
    int h,m,s;
    cout << "Hours: ";
    cin >> h;
    cout << "Minutes: ";
    cin >> m;
    cout << "Seconds: ";
    cin >> s;
    cout << h*60*60 + m*60 + s << "s";
    return 0;
}
