#include <iostream>

using namespace std;

int main()
{
    int t,n;
    cout << "thang: ";
    cin >> t;
    cout << "nam: ";
    cin >> n;
    switch(t)
    {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            cout << "31 ngay";
            break;
        case 4: case 6: case 9: case 11:
            cout << "30 ngay";
            break;
        case 2:
        {
            if(n%400==0 || (n%4==0 && n%100!=0)) cout << "29 ngay";
            else cout << "28 ngay";
            break;
        }
    }
    return 0;
}
