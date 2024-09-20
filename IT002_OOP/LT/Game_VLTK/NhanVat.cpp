#include "DoiTuong.cpp"

class NhanVat : public DoiTuong
{
private:
    int monPhai;

    void setNguHanh()
    {
        switch(monPhai)
        {
            case 0: //Thieu Lam
            case 1: //Thien Vuong bang
                hanh = 0; //Kim
                break;
            
            case 2: //Ngu Doc giao
            case 3: //Duong Mon
                hanh = 1; //Moc
                break;

            case 4: //Nga My
            case 5: //Thuy Yen mon
                hanh = 2; //Thuy
                break;

            case 6: //Cai Bang
            case 7: //Thien Nhan giao
                hanh = 3; //Hoa
                break;

            case 8: //Con Lon
            case 9: //Vo Dang
                hanh = 4; //Tho
        }
    }

public:
    NhanVat()
    {
        loai = 1;
    }

    void khoiTao()
    {
        DoiTuong::khoiTao();
        cout << "Mon phai: ";
        cin >> monPhai;
        setNguHanh();        
    }

    void thongTin() const
    {
        DoiTuong::thongTin();
        cout << "Mon phai: " << getMonPhai() << endl;
        cout << "Sat thuong goc: " << satThuongGoc() << endl;
    }

    string getMonPhai() const
    {
        switch(monPhai)
        {
            case 0: 
                return "Thieu Lam";
            case 1: 
                return "Thien Vuong bang";
            case 2: 
                return "Ngu Doc giao";
            case 3: 
                return "Duong Mon";
            case 4: 
                return "Nga My";
            case 5: 
                return "Thuy Yen mon";
            case 6: 
                return "Cai Bang";
            case 7: 
                return "Thien Nhan giao";
            case 8: 
                return "Con Lon";
            case 9: 
                return "Vo Dang";
        }
    }

    double satThuongGoc() const
    {
        return getCapDo()*5;
    }
};