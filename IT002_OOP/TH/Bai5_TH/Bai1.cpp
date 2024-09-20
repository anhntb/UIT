#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using namespace std;

class NhanVien
{
protected:
    string sHoTen;
    string sNgaySinh;
    int iLuong;
    bool Loai; //0:NVVP     1:NVSX

public:
    void Nhap()
    {
        cout << "Ho ten: ";
        fflush(stdin);
        getline(cin, sHoTen);

        cout << "Ngay sinh: ";
        cin >> sNgaySinh;
    }

    void Xuat() const
    {
        cout << "Ho ten: " << sHoTen << endl;
        cout << "Ngay sinh: " << sNgaySinh << endl;
        cout << "Luong: " << iLuong << endl;
    }

    bool getLoai() const
    {
        return Loai;
    }

    int getLuong() const
    {
        return iLuong;
    }
};

class NVSX : public NhanVien
{
private:
    int iLuongCB;
    int iSanPham;

public:
    NVSX()
    {
        Loai = 1;
    }

    void Nhap()
    {
        NhanVien::Nhap();
        cout << "Luong can ban: ";
        cin >> iLuongCB;

        cout << "So san pham: ";
        cin >> iSanPham;

        Luong();
    }

    void Xuat() const
    {
        cout << "Loai: Nhan vien san xuat" << endl;
        NhanVien::Xuat();
        cout << "Luong can ban: " << iLuongCB << endl;
        cout << "So san pham: " << iSanPham << endl;
    }

    void Luong()
    {
        iLuong = iLuongCB + iSanPham*5000;
    }
};

class NVVP : public NhanVien
{
private:
    int iNgayLam;

public:
    NVVP()
    {
        Loai = 0;
    }

    void Nhap()
    {
        NhanVien::Nhap();
        cout << "So ngay lam viec: ";
        cin >> iNgayLam;

        Luong();
    }

    void Xuat() const
    {
        cout << "Loai: Nhan vien san xuat" << endl;
        NhanVien::Xuat();
        cout << "So ngay lam viec: " << iNgayLam << endl;
    }

    void Luong()
    {
        iLuong = iNgayLam*100000;
    }
};

class CongTy
{
private:
    int iSoNV;
    NhanVien** list;

public:
    void Nhap()
    {
        cout << "So luong nhan vien: ";
        cin >> iSoNV;
        list = new NhanVien*[iSoNV];

        bool tmp;
        for(int i=0; i<iSoNV; i++)
        {
            cout << "Loai(0:NVVP / 1:NVSX): ";
            cin >> tmp;
            if(tmp)
            {
                list[i] = new NVSX;
                ((NVSX*)list[i])->Nhap();
                ((NVSX*)list[i])->Luong();
            }
            else
            {
                list[i] = new NVVP;
                ((NVVP*)list[i])->Nhap();
                ((NVVP*)list[i])->Luong();
            }
        }
    }

    void Xuat() const
    {
        for(int i=0; i<iSoNV; i++)
        {
            cout << "+Nhan vien " << i+1 << endl;
            if(list[i]->getLoai())
                ((NVSX*)list[i])->Xuat();
            else
                ((NVVP*)list[i])->Xuat();
            cout << endl;
        }
    }

    int tongLuong() const
    {
        int s = 0;
        for(int i=0; i<iSoNV; i++)
            s += list[i]->getLuong();
        return s;
    }

    void NVLuongCaoNhat() const
    {
        int m = list[0]->getLuong();
        int index = 0;
        for(int i=1; i<iSoNV; i++)
            if(m < list[i]->getLuong())
            {
                index = i;
                m = list[i]->getLuong();
            }

        if(list[index]->getLoai())
            ((NVSX*)list[index])->Xuat();
        else
            ((NVVP*)list[index])->Xuat();
    }

    void NVLuongThapNhat() const
    {
        int m = list[0]->getLuong();
        int index = 0;
        for(int i=1; i<iSoNV; i++)
            if(m > list[i]->getLuong())
            {
                index = i;
                m = list[i]->getLuong();
            }

        if(list[index]->getLoai())
            ((NVSX*)list[index])->Xuat();
        else
            ((NVVP*)list[index])->Xuat();
    }

    void sortDecrease() 
    {
        NhanVien* tmp;
        for(int i=1; i<iSoNV; i++)
        {
            tmp = list[i];
            int j = i-1;
            while(j>=0 && tmp->getLuong() > list[j]->getLuong())
            {
                list[j+1] = list[j];
                j--;
            }
            list[j+1] = tmp;
        }
    }
};

int main()
{
    CongTy a;
    a.Nhap();

    cout << "\n--------------------------------------------" << endl;
    a.Xuat();

    cout << "\n+TONG LUONG: " << a.tongLuong() << endl;

    cout << "+Nhan vien luong cao nhat" << endl;
    a.NVLuongCaoNhat();
    cout << "\n+Nhan vien luong thap nhat" << endl;
    a.NVLuongThapNhat();

    cout << "\n-----------------DANH SACH NHAN VIEN THEO LUONG GIAM DAN-----------------\n";
    a.sortDecrease();
    a.Xuat();
    
    return 0;
}