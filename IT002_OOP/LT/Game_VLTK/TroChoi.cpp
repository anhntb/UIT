#include <vector>
#include "DoiTuong.cpp"
#include "NhanVat.cpp"
#include "QuaiVat.cpp"

class TroChoi
{
public:
private:
    vector<DoiTuong*> list;

public:
    TroChoi(){}

    void inpInfor()
    {
        int n;
        cout << "So luong: ";
        cin >> n;
        for(int i=0; i<n; i++)
        {
            bool isPlayer;
            cout << "Loai(1:Nhan vat / 0:Quai vat): ";
            cin >> isPlayer;

            DoiTuong* tmp;
            if(isPlayer)
                tmp = new NhanVat;
            else
                tmp = new QuaiVat;

            tmp->khoiTao();
            list.push_back(tmp);
        }
    }

    void display() const
    {
        for(auto i : list)
        {
            i->thongTin();
            cout << endl;
        }
    }

    DoiTuong* satThuongCaoNhat() 
    {
        DoiTuong* tmp = list[0];
        int m = list[0]->satThuongGoc();
        for(vector<DoiTuong*>::iterator i = list.begin() + 1; i < list.end(); i++)
            if((*i)->satThuongGoc() > m)
            {
                m = (*i)->satThuongGoc();
                tmp = *i;
            }
        return tmp;
    }
};