#include <iostream>
#include <cstring>

using namespace std;

class SinhVien
{
private:
    string mssv;
    string hoten;
    int toan;
    int van;

public:
    SinhVien(string mssv="", string hoten=" ", int toan=0, int van=0)
    {
        this->mssv = mssv;
        this->hoten = hoten;
        this->toan = toan;
        this->van = van;
    }

    void setMssv(string mssv)
    {
        this->mssv = mssv;
    }

    void setHoten(string hoten)
    {
        this->hoten = hoten;
    }

    void setToan(int toan)
    {
        this->toan = toan;
    }

    void setVan(int van)
    {
        this->van = van;
    }

    string getMssv()
    {
        return mssv;
    }
    
    string getHoten()
    {
        return hoten;
    }

    int getToan()
    {
        return toan;
    }

    int getVan()
    {
        return van;
    }

    double DTB()
    {
        return (toan+van)/2.;
    }

    void Nhap()
    {
        string s;
        cout << "MSSV: ";
        cin >> s;
        setMssv(s);

        cout << "Ho ten: ";
        cin.ignore(1);
        getline(cin,s);
        setHoten(s);

        int n;
        cout << "Diem toan: ";
        cin >> n;
        setToan(n);

        cout << "Diem van: ";
        cin >> n;
        setVan(n);
    }

    void Xuat()
    {
        cout << "-----Thong tin sinh vien-----" << endl;
        cout << "MSSV: " << mssv << endl;
        cout << "Ho ten: " << hoten << endl;
        cout << "Diem toan: " << toan << endl;
        cout << "Diem van: " << van << endl;
        cout << "Diem trung binh: " << DTB() << endl;
    }
};

int main()
{
    SinhVien a;
    a.Nhap();
    a.Xuat();

    return 0;
}