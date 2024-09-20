#include <iostream>

using namespace std;

int chuvi_hcn(int d, int r)
{
    return 2*d*r;
}

int dientich_hcn(int d, int r)
{
    return d*r;
}

void ve_hcn(int d, int r)
{
    for(int i(1); i<=r; i++)
    {
        for(int j(1); j<=d; j++)
            cout << "*";
        cout << endl;
    }
}

int main()
{
    int d,r;
    cout << "Nhap chieu dai (hcn): ";
    cin >> d;
    cout << "Nhap chieu rong (hcn): ";
    cin >> r;

    cout << "\nChu vi hinh chu nhat = " << chuvi_hcn(d,r);
    cout << "\nDien tich hinh chu nhat = " << dientich_hcn(d,r);
    cout << "\nVe hinh chu nhat\n";
    ve_hcn(d,r);

    return 0;
}
