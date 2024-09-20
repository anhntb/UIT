/*
Tìm nghiệm của đa thức trong đoạn [a;b] cho trước
*/

#include <iostream>
#include <cmath>
#define M 100

using namespace std;

struct dathuc
{
    int somu;
    float heso[M];
};

struct mangf
{
    float arr[M];
    int n = 0;
};

void nhapdt(dathuc &dt)
{
    bacdt:
        cout << "Nhap bac da thuc:";
        cin >> dt.somu;
    if(dt.somu<1)
    {
        cout << "Bac da thuc phai >= 1\nNhap lai!!!" << endl;
        goto bacdt;
    }
    
    for(int i(0); i<dt.somu; i++)
    {
        cout << "Nhap he so cua x^" << i << ":";
        cin >> dt.heso[i];
    }
    hesocuoi:
        cout << "Nhap he so cua x^" << dt.somu << ":";
        cin >> dt.heso[dt.somu];
    if(dt.heso[dt.somu]==0)
    {
        cout << "He so cuoi phai != 0\nNhap lai!!!" << endl;
        goto hesocuoi;
    }
}

void xuatdt(dathuc dt)
{
    for(int i(0); i<dt.somu; i++)
    {
        if(dt.heso[i]!=0)
            cout << dt.heso[i] << "x^" << i << " + ";
    }
    cout << dt.heso[dt.somu] << "x^" << dt.somu << endl;
}

mangf nghiemdt(dathuc dt, int a, int b)
{
    mangf ng;

    //*Gán giá trị đầu cho min
    float x_mu(1);
    float gtmin(0);
    for(int j(0); j<=dt.somu; j++)
    {
        gtmin += dt.heso[j]*x_mu;
        x_mu *= a;
    }

    //*Tìm nghiệm (chính xác đến chữ số thập thân thứ 3)
    float s(0);    
    for(float i(a); i<=b; i += 0.001) //0.001 có dạng (double)(0.001000000000000000021)
    {
        i = round(i*1000)/1000; //round() loại bỏ sai số
        s=0;
        x_mu=1;
        for(int j(0); j<=dt.somu; j++)
        {
            s += dt.heso[j]*x_mu;
            x_mu *= i;
        }
        s = round(s*100)/100;
        if(s==0)
        {
            ng.arr[ng.n] = i;
            ng.n++;
        }
    }

    return ng;
}

int main()
{
    dathuc dt;

    nhapdt(dt);
    xuatdt(dt);

    int a, b;
    cout << "Nhap [a;b]\nNhap a:";
    cin >> a;
    cout << "Nhap b:";
    cin >> b;

    cout << "--------------------------" << endl;
    mangf ng = nghiemdt(dt,a,b);
    if(ng.n != 0)
    {
        cout << "Chinh xac den chu so thap phan thu 3" << endl;
        cout << "Nghiem: ";
        for(int i(0); i<ng.n; i++)
        {
            cout << ng.arr[i] << "   ";
        }
    }
    else
        cout << "Khong co nghiem";
    return 0;
}