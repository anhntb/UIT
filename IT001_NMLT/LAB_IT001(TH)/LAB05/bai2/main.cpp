#include <iostream>

using namespace std;

struct SINHVIEN
{
    int mssv;
    char ten[30];
    bool GioiTinh;
    char DiaChi[100];
    float toan, ly, hoa;
};

/*
Nhập thông tin 1 sinh viên
Input:
+Mã sinh viên
+Họ và tên
+Giới tính
+Địa chỉ
+Điểm: toán, lý hóa

Output:

*/
SINHVIEN nhap()
{
    SINHVIEN sv;
    cin >> sv.mssv;

    cin.ignore();
    gets(sv.ten);

    cin >> sv.GioiTinh; //0:nữ   1:nam

    cin.ignore();
    gets(sv.DiaChi);

    cin >> sv.toan >> sv.ly >> sv.hoa;

    return sv;
}

void xuat(SINHVIEN sv)
{
    cout << "MSSV: " << sv.mssv << endl;
    cout << "Ho va ten: " << sv.ten << endl;
    cout << "Gioi tinh (0:nu  1:nam): " << sv.GioiTinh << endl;
    cout << "Dia chi: " << sv.DiaChi << endl;

    cout << "Diem toan: " << sv.toan << endl;
    cout << "Diem ly: " << sv.ly << endl;
    cout << "Diem hoa: " << sv.hoa << endl;
}

int main()
{
    SINHVIEN sv = nhap();

    xuat(sv);

    return 0;
}
