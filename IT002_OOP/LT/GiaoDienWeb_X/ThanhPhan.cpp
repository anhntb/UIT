#include <iostream>
#include "ToaDo.cpp"
#include "KichThuoc.cpp"

using namespace std;

class ThanhPhan
{
private:
    ToaDo td;
    KichThuoc kt;

public:
    ThanhPhan(){}

    virtual void Nhap()
    {
        cout << "Hoanh do: ";
        cin >> td.x;
        cout << "Tung do: ";
        cin >> td.y;

        cout << "Chieu dai: ";
        cin >> kt.iDai;
        cout << "Chieu rong: ";
        cin >> kt.iRong;
    }

    virtual void Xuat() const
    {
        cout << "Hoanh do: " << td.x << endl;
        cout << "Tung do: " << td.y << endl;
        cout << "Chieu dai: " << kt.iDai << endl;
        cout << "Chieu rong: " << kt.iRong << endl;
    }

    virtual bool phoiMauDonSac(string) const = 0;
    virtual bool phoiMauBoTucTrucTiep(string) const = 0;
    virtual bool phoiMauTuongDong(string) const = 0;
};