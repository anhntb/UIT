#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class NhanVien
{
private:
    string sMaNV;
    string sHoTen;
    int iTuoi;
    string sPhoneNum;
    string sEmail;

public:
    virtual void Nhap()
    {
        cout << "Ma nhan vien: ";
        cin >> sMaNV;
        cout << "Ho ten: ";
        fflush(stdin);
        getline(cin, sHoTen);
        cout << "Tuoi: ";
        cin >> iTuoi;
        cout << "So dien thoai: ";
        cin >> sPhoneNum;
        cout << "Email: ";
        cin >> sEmail;
    }

    virtual void Xuat() const
    {
        cout << "Ma nhan vien: " << sMaNV << endl;
        cout << "Ho ten: " << sHoTen << endl;
        cout << "Tuoi: " << iTuoi << endl;
        cout << "So dien thoai: " << sPhoneNum << endl;
        cout << "Email: " << sEmail << endl;
    }

    virtual bool isNVHC() const
    {
        return false;
    }

    virtual int getOverTime() const
    {
        return 0;
    }

    virtual int getSanPham() const
    {
        return 0;
    }
};

class NVBH : public NhanVien
{
private:
    int iSanPham;

public:
    void Nhap()
    {
        NhanVien::Nhap();
        cout << "So san pham da ban: ";
        cin >> iSanPham;
    }

    void Xuat() const
    {
        NhanVien::Xuat();
        cout << "So san pham da ban: " << iSanPham << endl;
    }

    int getSanPham() const
    {
        return iSanPham;
    }
};

class NVHC : public NhanVien
{
private:
    int iOverTime;

public:
    void Nhap()
    {
        NhanVien::Nhap();
        cout << "Thoi gian lam thua: ";
        cin >> iOverTime;
    }

    void Xuat() const
    {
        NhanVien::Xuat();
        cout << "Thoi gian lam thua: " << iOverTime << endl;
    }

    bool isNVHC() const
    {
        return true;
    }

    int getOverTime() const
    {
        return iOverTime;
    }
};

class CongTy
{
private:
    int iSoNV;
    NhanVien** list;

public:
    ~CongTy()
    {
        for(int i=0; i<iSoNV; i++)
            delete list[i];
        delete list;
    }

    void Nhap()
    {
        cout << "So luong nhan vien: ";
        cin >> iSoNV;
        list = new NhanVien*[iSoNV];

        bool check;
        for(int i=0; i<iSoNV; i++)
        {
            cout << "\n+Nhan vien " << i+1 << endl;
            cout << "Loai nhan vien(0:NVBH / 1:NVHC): ";
            cin >> check;
            if(check)
                list[i] = new NVHC;
            else
                list[i] = new NVBH;
            list[i]->Nhap();
        }
    }

    void Xuat() const
    {
        for(int i=0; i<iSoNV; i++)
        {
            cout << "\n+Nhan vien " << i+1 << endl;
            cout << "Loai nhan vien: ";
            if(list[i]->isNVHC())
                cout << "NVHC" << endl;
            else
                cout << "NVBH" << endl;
            list[i]->Xuat();
        }
    }

    NhanVien* max_overTime() const
    {
        int m = 0;
        NhanVien* tmp;
        for(int i=0; i<iSoNV; i++)
            if(list[i]->isNVHC() && list[i]->getOverTime() >= m)
            {
                m = list[i]->getOverTime();
                tmp = list[i];
            }
        return tmp;
    }

    double trBinhSP() const
    {
        int s = 0;
        int cnt = 0;
        for(int i=0; i<iSoNV; i++)
            if(!list[i]->isNVHC())
            {
                s += list[i]->getSanPham();
                cnt++;
            }
        return (double)s/cnt;
    }

    void NVBH_tren_trB() const
    {
        double trb = trBinhSP();
        for(int i=0; i<iSoNV; i++)
            if(!list[i]->isNVHC() && list[i]->getSanPham()>trb)
            {
                list[i]->Xuat();
                cout << endl;
            }
    }
};

int main()
{
    CongTy a;
    a.Nhap();

    cout << "-----------------------------------" << endl;
    a.Xuat();

    cout << "\nNhan vien hanh chinh co thoi gian thua nhieu nhat" << endl;
    a.max_overTime()->Xuat();

    cout << "\nNhung nhan vien ban hang nhieu hon trung binh san pham ban duoc" << endl;
    a.NVBH_tren_trB();

    return 0;
}
