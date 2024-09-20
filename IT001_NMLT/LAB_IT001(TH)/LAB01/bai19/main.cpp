#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int h1,m1,s1,h2,m2,s2;
    cout << "Gio(1): ";
    cin >> h1;
    cout << "Phut(1): ";
    cin >> m1;
    cout << "Giay(1): ";
    cin >> s1;

    cout << "\nGio(2): ";
    cin >> h2;
    cout << "Phut(2): ";
    cin >> m2;
    cout << "Giay(2): ";
    cin >> s2;


    int t1 = h1*3600 + m1*60 + s1;
    int t2 = h2*3600 + m2*60 + s2;

    int hieu_t = abs(t1-t2);
    int tong_t = t1+t2;

    int s_tong = tong_t%60;
    tong_t /= 60;
    int m_tong = tong_t%60, h_tong = tong_t/60;

    int s_hieu = hieu_t%60;
    hieu_t /= 60;
    int m_hieu = hieu_t%60, h_hieu = hieu_t/60;

    cout << "\nTong thoi gian: " << h_tong << "h" << m_tong << "m" << s_tong << "s" << endl;
    cout << "Hieu thoi gian: " << h_hieu << "h" << m_hieu << "m" << s_hieu << "s" << endl;
    return 0;
}
