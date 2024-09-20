/*
Nhập hỗn số
//*Hỗn số được hình thành từ phân số lớn hơn 1
*/

#include <iostream>

using namespace std;

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

int main()
{
    honso hs;
    nhaphs(hs);
    return 0;
}