/*
Khai báo kiểu dữ liệu biểu diễn thông tin của 1 sổ tiết kiệm (SOTIETKIEM)
và viết hàm nhập xuất
+Mã sổ: char[5]
+Loại tiết kiệm: char[10]
+Họ tên khách hàng: char[30]
+Chứng minh nhân dân: int
+Ngày mở sổ: kiểu dữ liệu ngày
+Số tiền gửi: double
*/

#include <iostream>

using namespace std;

struct date
{
    int d, m, y;
};

struct SOTIETKIEM
{
    char maso[6]; //kí tự cuối là \0, để kết thúc chuỗi
    char loaitk[11];
    char tenkh[30];
    int cmnd;
    date dmoso;
    double tien;
};

void nhap(SOTIETKIEM &a)
{
    cout << "Nhap ma so (<=5 ki tu):";
    cin.getline(a.maso, 6); //dừng lại khi gặp kí tự enter (\n)
    cout << "Nhap loai tiet kiem:";
    cin.getline(a.loaitk, 11);
    cout << "Nhap ten khach hang:";
    cin.getline(a.tenkh, 30);
    cout << "Nhap so chung minh nhan dan:";
    cin >> a.cmnd;
    
    cout << "Ngay mo so dd/mm/yyy" << endl;
    cout << "Nhap ngay:";
    cin >> a.dmoso.d;
    cout << "Nhap thang:";
    cin >> a.dmoso.m;
    cout << "Nhap nam:";
    cin >> a.dmoso.y;

    cout << "So tien tiet kiem:";
    cin >> a.tien;
}

void xuat(SOTIETKIEM a)
{
    cout << "\nTHONG TIN CUA SO TIET KIEM" << endl;
    cout << "Ma so: " << a.maso << endl;
    cout << "Loai tiet kiem: " << a.loaitk << endl;
    cout << "Ten khach hang: " << a.tenkh << endl;
    cout << "Chung minh nhan dan: " << a.cmnd << endl;
    cout << "Ngay mo so: " << a.dmoso.d << "/" << a.dmoso.m << "/" << a.dmoso.y << endl;
    cout << "So tien tiet kiem: " << a.tien << endl;
}   

int main()
{
    SOTIETKIEM so;
    nhap(so);
    xuat(so);
    return 0;
}