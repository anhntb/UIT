/*
Kiểm tra phân số tối giản
*/

#include <iostream>

using namespace std;

struct phanso
{
    int tuso;
    int mauso;
};

int UCLN(int a, int b)
{
    if(b==0) return a;
    return UCLN(b, a%b);
}

bool pstoigian(phanso ps)
{
    return UCLN(ps.tuso, ps.mauso) == 1;
}

int main()
{
    phanso ps;
    cout << "Nhap tu so:";
    cin >> ps.tuso;
    mauso:
        cout << "Nhap mau so:";
        cin >> ps.mauso;
    if(ps.mauso==0)
    {
        cout << "Mau so phai khac 0" << endl;
        goto mauso;
    }

    cout << "Phan so: " << ps.tuso << "/" << ps.mauso << endl;
    if(pstoigian(ps))
        cout << "La phan so toi gian";
    else
        cout << "Khong phai phan so toi gian";

    return 0;
}