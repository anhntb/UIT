#include <iostream>

using namespace std;

int main()
{
    int h,m,s;
    cout << "Gio: ";
    cin >> h;
    cout << "Phut: ";
    cin >> m;
    cout << "Giay: ";
    cin >> s;

    if( h<24 && h>=0 && m<60 && m>=0 && s<60 && s>=0 )
        cout << "Hop le";
    else cout << "Khong hop le";

    return 0;
}
