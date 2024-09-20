/*
Khai báo kiểu dữ liệu biểu diễn thông tin của 1 tỉnh (TINH)
và viết hàm nhập xuất
+Mã tỉnh: short
+Tên tỉnh: char[30]
+Dân số: int
+Diện tích: double
*/

#include <iostream>

using namespace std;

struct SOTIETKIEM
{
    short matinh;
    char tentinh[30];
    int danso;
    double dientich;
};

void nhap(SOTIETKIEM &a)
{
    cout << "Nhap ma tinh:";
    cin >> a.matinh;
    cin.ignore(); //xóa bộ nhớ đệm (xóa Enter "\n")
    cout << "Nhap ten tinh:";
    cin.getline(a.tentinh, 30);
    cout << "Nhap dan so:";
    cin >> a.danso;
    cout << "Nhap dien tich:";
    cin >> a.dientich;
}

void xuat(SOTIETKIEM a)
{
    cout << "\nTHONG TIN CUA TINH" << endl;
    cout << "Ma tinh: " << a.matinh << endl;
    cout << "Ten tinh: " << a.tentinh << endl;
    cout << "Dan so: " << a.danso << " nguoi" << endl;
    cout << "Dien tich: " << a.dientich << " m^2" << endl;
}

int main()
{
    SOTIETKIEM T;
    nhap(T);
    xuat(T);
    return 0;
}