/*
Khai báo kiểu dữ liệu biểu diễn thông tin của 1 đội bóng (DOIBONG)
và viết hàm nhập xuất
+Mã đội bóng: char[5]
+Tên đội bóng: char[30]
+Danh sách các cầu thủ: char[30][30]
*/

#include <iostream>

using namespace std;

struct SOTIETKIEM
{
    char madb[6]; //kí tự cuối là \0, để kết thúc chuỗi
    char tendb[30];
    int slct;
    char danhsachct[30][30];
};

void nhap(SOTIETKIEM &a)
{
    cout << "Nhap ma doi bong (<=5 ki tu):";
    gets(a.madb); //dừng lại khi gặp kí tự enter (\n)
    cout << "Nhap ten doi bong:";
    cin.getline(a.tendb, 30);
    slct:
        cout << "Nhap so luong cau thu (<=30):";
        cin >> a.slct;
    if(a.slct>30)
    {
        cout << "Nhap lai!!!" << endl;
        goto slct;
    }
    cin.ignore(); //bỏ qua 1 kí tự +++++ fflush(stdin); xóa toàn bộ, bộ nhớ đệm
    //! nên dùng fflush(stdin), cin.ignore(): khó kiểm soát
    for(int i(0); i<a.slct; i++)
    {
        cout << "+ Ten cau thu " << i+1 << ":";
        cin.getline(a.danhsachct[i], 30);
    }
}

void xuat(SOTIETKIEM a)
{
    cout << "\nTHONG TIN CUA DOI BONG" << endl;
    cout << "Ma doi bong: " << a.madb << endl;
    cout << "Ten doi bong: " << a.tendb << endl;
    cout << "Danh sach cac cau thu:" << endl;
    for(int i(0); i<a.slct; i++)
    {
        cout << "+ Cau thu " << i+1 << ":";
        cout << a.danhsachct[i] << endl;
    }
}

int main()
{
    SOTIETKIEM db;
    nhap(db);
    xuat(db);
    return 0;
}