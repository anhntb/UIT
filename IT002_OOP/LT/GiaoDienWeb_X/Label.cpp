#include "ThanhPhan.cpp"

class Label : public ThanhPhan
{
private:
    string sMauChu;
    string sMauNen;

public:
    Label(){}

    void Nhap()
    {
        ThanhPhan::Nhap();
        cout << "Mau chu: ";
        cin >> sMauChu;
        cout << "Mau nen: ";
        cin >> sMauNen;
    }

    void Xuat() const
    {
        ThanhPhan::Xuat();
        cout << "Mau chu: " << sMauChu << endl;
        cout << "Mau nen: " << sMauNen << endl;
    }

    int countColor(string sMauSac) const
    {
        int cnt = 1;
        for(int i=0; i<sMauSac.length(); i++)
            if(sMauSac[i] == '-')
                cnt++;

        return cnt;
    }

    bool phoiMauDonSac(string sMauSac) const
    {
        return countColor(sMauSac) == 1;
    }

    bool phoiMauBoTucTrucTiep(string sMauSac) const
    {
        if(countColor(sMauSac) == 2)
        {
            string 
            int index = sMauSac.find("-");
            int m1 = stoi(sMauSac.)
            int m2 = 
        }

        return false;
    }


};