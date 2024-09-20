#include <iostream>

using namespace std;

void arr_tudong(float arr[], int &n); //9.a
void xuat(float arr[], int n); //9.b
void vt_am(float arr[], int n); //9.c
void timchan(float arr[], int n); //9.d
float lonnhat(float arr[], int n); //9.e
float duongdau(float arr[], int n); //9.f
float chancuoi(float arr[], int n); //9.g
int vitrinhonhat(float arr[], int n); //9.h
int vitrichandau(float arr[], int n); //9.i

int main()
{
    int n;
    char ch;
    float arr[1000];

    menu:
    cout << endl << endl;
    cout << "----------------------------------MENU----------------------------------" << endl;
    cout << "a: Nhap mang so thuc tu dong" << endl;
    cout << "b: Xuat mang" << endl;
    cout << "c: Liet ke vi tri phan tu co gia tri am" << endl;
    cout << "d: Cac gia tri chan trong mang" << endl;
    cout << "e: Tim gia tri lon nhat trong mang" << endl;
    cout << "f: Gia tri duong dau tien trong mang" << endl;
    cout << "g: So chan cuoi cung trong mang" << endl;
    cout << "h: Tim vi tri phan tu nho nhat" << endl;
    cout << "i: Tim vi tri gia tri chan dau tien" << endl;
    cout << "0: Ket thuc" << endl << endl;
    cout << "Choose: ";
    cin >> ch;
    cout << endl;

    switch(ch)
    {
        case 'a':
            cout << "9.a: Nhap mang so thuc tu dong" << endl;
            arr_tudong(arr,n);
            goto menu;
        case 'b':
            cout << "9.b: Xuat mang" << endl;
            xuat(arr,n);
            goto menu;
        case 'c':
            cout << "9.c: Liet ke vi tri phan tu co gia tri am" << endl;
            vt_am(arr,n);
            goto menu;
        case 'd':
            cout << "9.d: Cac gia tri chan trong mang" << endl;
            timchan(arr,n);
            goto menu;
        case 'e':
            cout << "9.e: Tim gia tri lon nhat trong mang" << endl;
            cout << lonnhat(arr,n) << endl;
            goto menu;
        case 'f':
            cout << "9.f: Gia tri duong dau tien trong mang" << endl;
            cout << duongdau(arr,n) << endl;
            goto menu;
        case 'g':
            cout << "9.g: So chan cuoi cung trong mang" << endl;
            cout << chancuoi(arr,n) << endl;
            goto menu;
        case 'h':
            cout << "9.h: Vi tri phan tu nho nhat" << endl;
            cout << vitrinhonhat(arr,n) << endl;
            goto menu;
        case 'i':
            cout << "9.i: Vi tri gia tri chan dau tien" << endl;
            cout << vitrichandau(arr,n) << endl;
            goto menu;
        case '0':
            cout << "----------------------------------END----------------------------------";
    }

    return 0;
}
