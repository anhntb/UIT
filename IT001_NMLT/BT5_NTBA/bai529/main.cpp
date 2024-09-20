/*
Tính thương của 2 hỗn số
//*Hỗn số được hình thành từ phân số lớn hơn 1
*/

#include <iostream>

using namespace std;
struct phanso
{
    int tuso, mauso;
};

struct honso
{
    int pnguyen;
    int tuso, mauso;
};

void nhaphs(honso &hs)
{
    phannguyen:
        cout << "Nhap phan nguyen:";
        cin >> hs.pnguyen;
    if (hs.pnguyen<1)
    {
        cout << "Phan nguyen phai lon hon 0" << endl;
        goto phannguyen;
    }
    
    tuso:
        cout << "Nhap tu so:";
        cin >> hs.tuso;
    if(hs.tuso<=0)
    {
        cout << "Tu so phai lon hon 0" << endl;
        goto tuso;
    }

    mauso:
        cout << "Nhap mau so:";
        cin >> hs.mauso;
    if(hs.mauso<=hs.tuso)
    {
        cout << "Mau so phai lon hon tu so" << endl;
        goto mauso;
    }
}

void xuaths(honso hs)
{
    cout << hs.pnguyen << "(" << hs.tuso << "/" << hs.mauso << ")" << endl;
}

int UCLN(int a, int b)
{
    if(b==0) return a;
    return UCLN(b, a%b);
}

phanso thuonghs(honso hs1, honso hs2)
{
    phanso kq;
    kq.tuso = (hs1.pnguyen*hs1.mauso + hs1.tuso) * hs2.mauso;
    kq.mauso = (hs2.pnguyen*hs2.mauso + hs2.tuso) * hs1.mauso;

    //*Rút gọn về dạng hỗn số
    int Uchung = UCLN(kq.tuso, kq.mauso);
    kq.tuso /= Uchung;
    kq.mauso /= Uchung;
    return kq;
}

int main()
{
    honso hs1, hs2;
    cout << "Nhap hon so 1" << endl;
    nhaphs(hs1);
    xuaths(hs1);
    cout << "Nhap hon so 2" << endl;
    nhaphs(hs2);
    xuaths(hs2);

    cout << "-------------------" << endl;
    phanso kq = thuonghs(hs1,hs2);
    cout << hs1.pnguyen << "(" << hs1.tuso << "/" << hs1.mauso << ") / ";
    cout << hs2.pnguyen << "(" << hs2.tuso << "/" << hs2.mauso << ") = ";
    cout << kq.tuso << "/" << kq.mauso;

    return 0;
}