#include <iostream>

using namespace std;

int main()
{
    cout << "Hinh vuong: v      Hinh chu nhat: n      Hinh tron: t" << endl;
    cout << "\nNhap hinh: ";
    char k;
    cin >> k;

    const float pi = 3.14;
    switch(k)
    {
        case 'v':
        {
            cout << "Tinh P va S cua hinh vuong" << endl;
            cout << "Nhap canh: ";
            float a;
            cin >> a;
            cout << "Ket qua: P = " << a*4 << "     S = " << a*a << endl;
            break;
        }
        case 'n':
        {
            cout << "Tinh P va S cua hinh chu nhat" << endl;
            cout << "Nhap chieu dai: ";
            float a;
            cin >> a;
            cout << "Nhap chieu rong: ";
            float b;
            cin >> b;
            cout << "Ket qua: P = " << (a+b)*2 << "     S = " << a*b << endl;
            break;
        }
        case 't':
        {
            cout << "Tinh P va S cua hinh tron" << endl;
            cout << "Nhap ban kinh: ";
            float r;
            cin >> r;
            cout << "Ket qua: P = " << 2*pi*r << "     S = " << pi*r*r << endl;
            break;
        }
    }
    return 0;
}
