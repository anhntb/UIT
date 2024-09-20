#include <iostream>

using namespace std;

void nhap(int arr[], int &n); //8.1
void tao_tudong(int arr[], int &n); //8.2
void xuat(int arr[], int n); //8.3
bool lon2_nho2(int arr[], int n, int &lon2, int &nho2); //8.4
bool arr_dxung(int arr[], int n); //8.5
bool prt_dnguoc(int arr[], int n); //8.6
bool timx(int arr[], int n); //8.7
void mangcon(); //8.8
void arr_tang(int arr[], int n); //8.9

int main()
{
    int n, ch;
    int arr[1000];

    menu:
    cout << endl << endl;
    cout << "----------------------------------MENU----------------------------------" << endl;
    cout << "1: Nhap mang so nguyen" << endl;
    cout << "2: Tao mang doi xung tu dong" << endl;
    cout << "3: Xuat mang" << endl;
    cout << "4: Tim phan tu co gia tri lon thu 2 va nho thu 2 trong mang" << endl;
    cout << "5: Kiem tra mang doi xung" << endl;
    cout << "6: In ra cac cap phan tu co gia tri dao nguoc nhau" << endl;
    cout << "7: Tim x trong mang" << endl;
    cout << "8: Kiem tra mang con" << endl;
    cout << "9: Xep phan tu mang tang dan" << endl;
    cout << "0: Ket thuc" << endl << endl;
    cout << "Choose: ";
    cin >> ch;
    cout << endl;

    switch(ch)
    {
        case 1:
            cout << "8.1: Nhap mang so nguyen, cac phan tu khong trung nhau" << endl;
            cout << "     Cac phan tu thuoc [-379;3718]\n";
            nhap(arr,n);
            goto menu;
        case 2:
            cout << "8.2: Tao mang doi xung tu dong" << endl;
            tao_tudong(arr,n);
            goto menu;
        case 3:
            cout << "8.3: Xuat mang" << endl;
            xuat(arr,n);
            goto menu;
        case 4:
            cout << "8.4: Phan tu co gia tri lon thu 2 va nho thu 2 trong mang" << endl;
            int lon2,nho2;
            if(lon2_nho2(arr,n,lon2,nho2))
                cout << "Lon thu 2: " << lon2 << "\t\tNho thu 2: " << nho2 << endl;
            else
                cout << "Khong tim duoc" << endl;
            goto menu;
        case 5:
            cout << "8.5: Kiem tra mang doi xung" << endl;
            cout << (arr_dxung(arr,n) ? "True" : "False") << endl;
            goto menu;
        case 6:
            cout << "8.6: Cac cap phan tu co gia tri dao nguoc nhau" << endl;
            cout << (prt_dnguoc(arr,n) ? "" : "Khong tim duoc") << endl;
            goto menu;
        case 7:
            cout << "8.7: Tim x co trong mang" << endl;
            cout << (timx(arr,n) ? "True" : "False") << endl;
            goto menu;
        case 8:
            cout << "8.8: Kiem tra mang con" << endl;
            mangcon();
            goto menu;
        case 9:
            cout << "8.9: Xep phan tu mang tang dan" << endl;
            arr_tang(arr,n);
            xuat(arr,n);
            goto menu;
        case 0:
            cout << "----------------------------------END----------------------------------";
    }

    return 0;
}
