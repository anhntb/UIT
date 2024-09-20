#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// Xây dựng mảng 1 chiều lưu trữ các số nguyên. Sau đó viết hàm thực hiện các chức năng sau:

/*
Bài 4.a: Tạo giá trị ngẫu nhiên thuộc khoảng (-26; 26). Số lượng thuộc đoạn [100;200]
*/
int* tudong(int &n)
{
    n = 10 + rand()%21;
    int* a = new int[n];

    for(int i(0); i<n; i++)
    {
        *(a + i) = -25 + rand()%51;
    }

    return a;
}

/*
Bài 4.b: Xuất(in) mảng vừa tạo
*/
void xuat(int* a, int n)
{
    for(int i(0); i<n; i++)
    {
        cout << *(a + i) << "\t";
    }
    cout << endl;
}

/*
Bài 4.c: Tính tổng, tích các giá trị có trong mảng (viết 1 hàm)
*/
struct TongTich
{
    int tong = 0;
    int tich = 1;
};
TongTich TinhTT(int* a, int n)
{
    TongTich kq;
    for(int i(0); i<n; i++)
    {
        kq.tong += *(a + i);
        kq.tich *= *(a + i);
    }

    return kq;
}

/*
Bài 4.d: Đếm số lần xuất hiện 1 phần tử x bất kỳ
*/
int demx(int* a, int n, int x)
{
    int dem(0);
    for(int i(0); i<n; i++)
    {
        if(x == *(a + i))
            dem++;
    }

    return dem;
}

/*
Bài 4.e: Tìm các phần tử chẵn nhỏ hơn x
*/
int* ChanNhoHonx(int* a, int n, int x, int &sl)
{
    int* b = new int[n];
    sl = 0;

    for(int i(0); i<n; i++)
    {
        if(*(a + i)%2==0 && *(a + i)<x)
        {
            *(b + sl) = *(a + i);
            sl++;
        }
    }

    return b;
}

/*
Bài 4.f: Tìm các số âm trong mảng
*/
int* SoAm(int* a, int n, int &sl)
{
    int* b = new int[n];
    sl = 0;

    for(int i(0); i<n; i++)
    {
        if(*(a + i)<0)
        {
            *(b + sl) = *(a + i);
            sl++;
        }
    }

    return b;
}

/*
Bài 4.g: Tìm các số âm trong mảng 1 chiều thuộc đoạn [x;y] cho trước
*/
int* SoAmdoan(int* a, int n, int &sl, int x, int y)
{
    int* b = new int[n];
    sl = 0;

    for(int i(0); i<n; i++)
    {
        if(*(a + i)<0 && x<=*(a + i) && *(a + i)<=y)
        {
            *(b + sl) = *(a + i);
            sl++;
        }
    }

    return b;
}

int main()
{
    srand(time(0));
    int *a, *b, n, sl;

    cout << "-------------------------------Bai 4.a-------------------------------" << endl;
    a = tudong(n);

    cout << "-------------------------------Bai 4.b-------------------------------" << endl;
    xuat(a,n);

    cout << "-------------------------------Bai 4.c-------------------------------" << endl;
    TongTich kq = TinhTT(a,n);
    cout << "Tong = " << kq.tong << "\nTich = " << kq.tich << endl;

    cout << "-------------------------------Bai 4.d-------------------------------" << endl;
    int x = 5;
    cout << "So lan xuat hien " << x << " trong mang: " << demx(a,n,x) << endl;

    cout << "-------------------------------Bai 4.e-------------------------------" << endl;
    x = 9;
    b = ChanNhoHonx(a,n,x,sl);
    xuat(b,sl);

    cout << "-------------------------------Bai 4.f-------------------------------" << endl;
    b = SoAm(a,n,sl);
    xuat(b,sl);

    cout << "-------------------------------Bai 4.g-------------------------------" << endl;
    x = -10;
    int y = 10;
    b = SoAmdoan(a,n,sl,x,y);
    xuat(b,sl);

    return 0;
}
