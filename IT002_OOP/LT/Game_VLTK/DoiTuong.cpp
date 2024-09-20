#include <iostream>

using namespace std;

class DoiTuong
{
private:
    int capDo;

protected:
    int hanh; //0:Kim, 1:Moc, 2:Thuy, 3:Hoa, 4:Tho
    bool loai; //1:Nhan vat     0:Quai vat

public:
    DoiTuong(){}

    virtual void khoiTao()
    {
        cout << "Cap do: ";
        cin >> capDo;
    }

    virtual void thongTin() const
    {
        cout << "Loai(1:nhan vat / 0:quai vat): " << loai << endl; 
        cout << "Cap do: " << capDo << endl;
        cout << "Ngu hanh: " << getNguHanh() << endl;
    }

    string getNguHanh() const
    {
        switch(hanh)
        {
            case 0:
                return "Kim";
            case 1:
                return "Moc";
            case 2:
                return "Thuy";
            case 3:
                return "Hoa";
            case 4:
                return "Tho";
        }
    }

    void setCapDo(int n)
    {
        capDo = n;
    }

    int getCapDo() const
    {
        return capDo;
    }

    virtual double satThuongGoc() const = 0;

    double tgSinhTgKhac(const DoiTuong* dt) const
    {
        switch(hanh)
        {
            case 0: //Kim
                switch(dt->hanh)
                {
                    case 2:
                        return 0.1;
                    case 1:
                        return 0.2;
                    case 3:
                        return -0.2;
                    default:
                    return 0;
                }
            case 1: //Moc
                switch(dt->hanh)
                {
                    case 3:
                        return 0.1;
                    case 4:
                        return 0.2;
                    case 0:
                        return -0.2;
                    default:
                    return 0;
                }
            case 2: //Thuy
                switch(dt->hanh)
                {
                    case 1:
                        return 0.1;
                    case 3:
                        return 0.2;
                    case 4:
                        return -0.2;
                    default:
                    return 0;
                }
            case 3: //Hoa
                switch(dt->hanh)
                {
                    case 4:
                        return 0.1;
                    case 0:
                        return 0.2;
                    case 2:
                        return -0.2;
                    default:
                    return 0;
                }
            case 4: //Tho
                switch(dt->hanh)
                {
                    case 0:
                        return 0.1;
                    case 2:
                        return 0.2;
                    case 1:
                        return -0.2;
                    default:
                    return 0;
                }
        }
    }

    double satThuongGayRa(const DoiTuong* dt) const
    {
        return satThuongGoc()*(1 + tgSinhTgKhac(dt));
    }
};