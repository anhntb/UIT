#include <iostream>

using namespace std;

float canbac_x(int n); //4.1
int sodao(int n); //4.2
bool doixung(int n); //4.3
bool chinhphuong(int n); //4.4
bool so_ngto(int n); //4.5
int tongchan(int n); //4.6
int tichle(int n); //4.7
int tong_ngto(int n); //4.8
int tong_chinhphuong(int n); //4.9
int tong_uocduong(int n); //4.10

int main()
{
    cout << "Nhap n: ";
    int n, a;
    cin >> n;

    menu:
    cout << endl << endl;
    cout << "----------------------------------MENU----------------------------------" << endl;
    cout << "1: Tinh can bac x cua so n" << endl;
    cout << "2: So nghich dao cua so n" << endl;
    cout << "3: Kiem tra n la so doi xung" << endl;
    cout << "4: Kiem tra n la so chinh phuong" << endl;
    cout << "5: Kiem tra n la so nguyen to" << endl;
    cout << "6: Tong cac chu so chan cua n" << endl;
    cout << "7: Tich cac chu so le cua n" << endl;
    cout << "8: Tong cac so nguyen to nho hon n" << endl;
    cout << "9: Tong cac so chinh phuong nho hon n" << endl;
    cout << "10: Tong cac uoc so duong cua n" << endl;
    cout << "11: Nhap lai n" << endl;
    cout << "0: Ket thuc" << endl << endl;
    cout << "Choose: ";
    cin >> a;
    cout << endl;

    switch(a)
    {
        case 1:
            cout << "4.1: Tinh can bac x cua so " << n << endl << canbac_x(n) << endl;
            goto menu;
        case 2:
            cout << "4.2: So nghich dao cua so " << n << endl << sodao(n) << endl;
            goto menu;
        case 3:
            cout << "4.3: Kiem tra " << n << " la so doi xung\n" << doixung(n) << endl;
            goto menu;
        case 4:
            cout << "4.4: Kiem tra " << n << " la so chinh phuong\n" << chinhphuong(n) << endl;
            goto menu;
        case 5:
            cout << "4.5: Kiem tra " << n << " la so nguyen to\n" << so_ngto(n) << endl;
            goto menu;
        case 6:
            cout << "4.6: Tong cac chu so chan cua " << n << endl << tongchan(n) << endl;
            goto menu;
        case 7:
            cout << "4.7: Tich cac chu so le cua " << n << endl << tichle(n) << endl;
            goto menu;
        case 8:
            cout << "4.8: Tong cac so nguyen to nho hon " << n << endl << tong_ngto(n) << endl;
            goto menu;
        case 9:
            cout << "4.9: Tong cac so chinh phuong nho hon " << n << endl << tong_chinhphuong(n) << endl;
            goto menu;
        case 10:
            cout << "4.10: Tong cac uoc so duong cua " << n << endl << tong_uocduong(n) << endl;
            goto menu;
        case 11:
            cout << "Nhap n: ";
            cin >> n;
            goto menu;
        case 0:
            cout << "----------------------------------END----------------------------------";
    }

    return 0;
}
