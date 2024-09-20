/*
Định nghĩa toán tử hiệu (operator -) cho 2 phân số
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

phanso operator - (phanso ps1, phanso ps2)
{
    phanso kq;
    kq.tuso = ps1.tuso*ps2.mauso - ps2.tuso*ps1.mauso;
    kq.mauso = ps1.mauso*ps2.mauso;

    //*Tối giản phân số
    int Uchung = UCLN(kq.tuso, kq.mauso);
    kq.tuso /= Uchung;
    kq.mauso /= Uchung;
    return kq;
}

int main()
{
    phanso ps1, ps2;
    cout << "Tao phan so 1" << endl;
    cout << "Tu so: ";
    cin >> ps1.tuso;
    mauso1:
        cout << "Mau so: ";
        cin >> ps1.mauso;
    if(ps1.mauso==0)
    {
        cout << "Mau so phai khac 0" << endl;
        goto mauso1;
    }

    cout << "--------------------------" << endl;
    cout << "Tao phan so 2" << endl;
    cout << "Tu so: ";
    cin >> ps2.tuso;
    mauso2:
        cout << "Mau so: ";
        cin >> ps2.mauso;
    if(ps2.mauso==0)
    {
        cout << "Mau so phai khac 0" << endl;
        goto mauso2;
    }

    phanso psh = ps1 - ps2;
    cout << endl << ps1.tuso << "/" << ps1.mauso << " - " << ps2.tuso << "/" << ps2.mauso << " = ";
    cout << psh.tuso << "/" << psh.mauso << endl;
    return 0;
}