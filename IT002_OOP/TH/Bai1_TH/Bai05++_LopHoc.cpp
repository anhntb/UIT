#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*
Bài tập thêm:
Bài 5: Viết chương trình nhập vào n học sinh của lớp.
- Xuất ra các học sinh có điểm trung bình cao nhất lớp.
- Xuất ra các học sinh có điểm trung bình thấp hơn điểm trung bình chung của lớp.

+Input: n học sinh của lớp
+Output: + các học sinh có điểm trung bình cao nhất
         + các học sinh có điểm trung bình thấp hơn điểm trung bình của lớp
*/
struct HocSinh
{
    string strHoTen;
    int iToan;
    int iVan;

    void NhapHS()
    {
        fflush(stdin);
        cout << "Ho ten: ";
        getline(cin, strHoTen);

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
        cout << "Ho ten: " << strHoTen << endl;
        cout << "Diem toan: " << iToan << endl;
        cout << "Diem van: " << iVan << endl;
        cout << "Diem trung binh: " << DTB() << endl;
    }

    double DTB()
    {
        return (iToan+iVan) / 2.;
    }
};

struct LopHoc
{
    int iSoHocSinh;
    HocSinh* danhSachHS;

    void NhapLH()
    {
        cout << "Nhap so hoc sinh: ";
        cin >> iSoHocSinh;

        danhSachHS = new HocSinh[iSoHocSinh];
        for(int i=0; i < iSoHocSinh; i++)
        {
            cout << "\n+ Hoc sinh " << i+1 << endl;
            danhSachHS[i].NhapHS();
        }
    }

    double DTBCaoNhat()
    {
        double DTB_max = danhSachHS[0].DTB();

        for(int i=1; i < iSoHocSinh; i++)
            if(DTB_max < danhSachHS[i].DTB())
                DTB_max == danhSachHS[i].DTB();

        return DTB_max;
    }

    void HS_DTBCaoNhat()
    {
        cout << "\n-----Cac hoc sinh co diem trung binh cao nhat-----" << endl;
        for(int i=0; i < iSoHocSinh; i++)
            if(danhSachHS[i].DTB() == DTBCaoNhat())
            {
                danhSachHS[i].XuatHS();
                cout << endl;
            }
    }

    double DTBLopHoc()
    {
        double S = 0;
        for(int i=0; i < iSoHocSinh; i++)
        {
            S += danhSachHS[i].DTB();
        }
        return S / iSoHocSinh;
    }

    void HS_DuoiDTBLopHoc()
    {
        cout << "\n-----Cac hoc sinh co diem trung binh thap hon diem trung binh cua lop-----" << endl;
        for(int i=0; i < iSoHocSinh; i++)
            if(danhSachHS[i].DTB() < DTBLopHoc())
            {
                danhSachHS[i].XuatHS();
                cout << endl;
            }   
    }
};

int main()
{
    LopHoc a;
    a.NhapLH();
    a.HS_DTBCaoNhat();
    a.HS_DuoiDTBLopHoc();

    return 0;
}