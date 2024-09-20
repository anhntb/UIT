#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*
Bài 5: Viết chương trình nhập họ tên, điểm toán, điểm văn của một học sinh. Tính điểm trung
bình và xuất kết quả.
+Input: Thông tin 1 học sinh (họ tên, điểm toán, điểm văn)
+Output: điểm trung bình
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

    double DTB()
    {
        return (iToan+iVan) / 2.;
    }
};

int main()
{
    HocSinh a;
    a.NhapHS();
    cout << "Diem trung binh: " << a.DTB() << endl;

    return 0;
}