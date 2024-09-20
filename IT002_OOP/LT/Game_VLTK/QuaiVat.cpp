#include "DoiTuong.cpp"

class QuaiVat : public DoiTuong
{
private:
    bool isBoss; //1:Dau linh       0:Thong thuong

public:
    QuaiVat()
    {
        loai = 0;
    }

    void khoiTao()
    {
        DoiTuong::khoiTao();
        cout << "Loai quai(1:dau linh / 0:thong thuong): ";
        cin >> isBoss;
        cout << "Ngu hanh: ";
        cin >> hanh;
    }

    void thongTin() const
    {
        DoiTuong::thongTin();
        cout << "Loai quai: " << (isBoss ? "Dau linh" : "Thong thuong") << endl;
        cout << "Sat thuong goc: " << satThuongGoc() << endl;
    }

    double satThuongGoc() const
    {
        return (isBoss ? 7 : 3)*getCapDo();
    }
};