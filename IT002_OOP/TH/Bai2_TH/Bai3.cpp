#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Candidate
{
private:
    string strMa;
    string strHoTen;
    string strNgaySinh;
    int iToan;
    int iVan;

public:
    void NhapHS()
    {
        fflush(stdin);
        cout << "MSSV: ";
        getline(cin, strMa);

        fflush(stdin);
        cout << "Ho ten: ";
        getline(cin, strHoTen);

        fflush(stdin);
        cout << "Ngay sinh: ";
        getline(cin, strNgaySinh);

        cout << "Diem toan: ";
        cin >> iToan;

        cout << "Diem van: ";
        cin >> iVan;

        if(iToan<0) iToan=0;
        if(iToan>10) iToan=10;

        if(iVan<0) iVan=0;
        if(iVan>10) iVan=10;
    }

    void XuatHS()
    {
        cout << "MSSV: " << strMa << endl;
        cout << "Ho ten: " << strHoTen << endl;
        cout << "Ngay sinh: " << strNgaySinh << endl;
        cout << "Diem toan: " << iToan << endl;
        cout << "Diem van: " << iVan << endl;
    }

    int TongDiem()
    {
        return iToan + iVan;
    }
};

class TestCandidate
{
private:
    int iSoHocSinh;
    Candidate* danhSachHS;

public:
    void NhapLH()
    {
        cout << "Nhap so hoc sinh: ";
        cin >> iSoHocSinh;

        danhSachHS = new Candidate[iSoHocSinh];
        for(int i=0; i < iSoHocSinh; i++)
        {
            cout << "\n+ Hoc sinh " << i+1 << endl;
            danhSachHS[i].NhapHS();
        }
    }

    void DiemHon15()
    {
        cout << "\n-----Cac hoc sinh co tong diem lon hon 15-----" << endl;
        for(int i=0; i < iSoHocSinh; i++)
            if(danhSachHS[i].TongDiem() > 15)
            {
                danhSachHS[i].XuatHS();
                cout << endl;
            }
    }
};

int main()
{
    TestCandidate a;
    a.NhapLH();
    a.DiemHon15();

    return 0;
}