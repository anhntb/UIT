#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

struct SINHVIEN
{
    int mssv;
    string ten;
    float dtb;
    string xeploai;
};

//Bài 3.1: Nhập thủ công n SV (chỉ nhập mã sinh viên, họ tên, điểm trung bình)
void nhap(SINHVIEN sv[], int &n)
{
    cout << "Nhap so luong sinh vien: ";
    cin >> n;

    for(int i(0); i<n; i++)
    {
        cout << "\nSinh vien " << i+1 << endl;
        cin >> sv[i].mssv;
        fflush(stdin);
        getline(cin, sv[i].ten);
        cin >> sv[i].dtb;
    }
}

//Bài 3.2: Khởi tạo ngẫu nhiên các sinh viên (mã sinh viên, họ tên, điểm trung bình)
void tudong(SINHVIEN sv[], int &n)
{
    n = 1 + rand()%30;
    string ho[8] = {"Nguyen", "Tran", "Le", "Huynh", "Ngo", "Luong", "Vu", "Pham"};
    string tendem[10] = {"Thi", "Van", "Tuyet", "Bao", "Tran", "Dang", "Tran Bao", "Thi Hong", "Phi Long", ""};
    string ten[12] = {"Nam", "Han", "Nga", "Thu", "Nhu", "Khang", "Long", "Phuc", "Anh", "An", "Tuan", "Quoc"};

    for(int i(0); i<n; i++)
    {
        sv[i].mssv = 1000 + rand()%9000; //[1000; 9999];
        sv[i].ten = ho[rand()%8] + " " + tendem[rand()%10] + " " + ten[rand()%12];
        sv[i].dtb = (rand()%101) / 10.;
    }
}

//Bài 3.3: Xuất(in) thông tin sinh viên ra màn hình
void xuat(SINHVIEN sv[], int n)
{
    for(int i(0); i<n; i++)
    {
        cout << "+ Sinh vien " << i+1 << endl;
        cout << "Mssv: " << sv[i].mssv << endl;
        cout << "Ho va ten: " << sv[i].ten << endl;
        cout << "Diem trung binh: " << sv[i].dtb << endl;
        if(sv[i].xeploai.length()!=0)
            cout << "Xep loai: " << sv[i].xeploai << endl;
        cout << endl;
    }
}

//Bài 3.4: Xuất(in) thông tin sinh viên có điểm trung bình lớn nhất
void xuat_dtbMax(SINHVIEN sv[], int n)
{
    float m = sv[0].dtb;
    int vt = 0;
    for(int i(1); i<n; i++)
    {
        if(m<sv[i].dtb)
        {
            m = sv[i].dtb;
            vt = i;
        }
    }

    cout << "Mssv: " << sv[vt].mssv << endl;
    cout << "Ho va ten: " << sv[vt].ten << endl;
    cout << "Diem trung binh: " << sv[vt].dtb << endl;
}

//Bài 3.5: Cập nhật xếp loại học lực sinh viên
void XepLoai(SINHVIEN sv[], int n)
{
    for(int i(0); i<n; i++)
    {
        if(sv[i].dtb>=9)
        {
            sv[i].xeploai = "Xuat sac";
            continue;
        }

        if(sv[i].dtb>=8)
        {
            sv[i].xeploai = "Gioi";
            continue;
        }

        if(sv[i].dtb>=7)
        {
            sv[i].xeploai = "Kha";
            continue;
        }

        if(sv[i].dtb>=5)
        {
            sv[i].xeploai = "Trung binh";
            continue;
        }

        if(sv[i].dtb>=3.5)
        {
            sv[i].xeploai = "Yeu";
            continue;
        }

        sv[i].xeploai = "Kem";
    }
}

//Bài 3.6: Tìm sinh viên theo mã sinh viên
SINHVIEN timSV_msv(SINHVIEN sv[], int n, int msv)
{
    for(int i(0); i<n; i++)
    {
        if(sv[i].mssv==msv)
            return sv[i];
    }
}

//Bài 3.7: Tìm các sinh viên có điểm trung bình cho trước
SINHVIEN timSV_dtb(SINHVIEN sv[], int n, float dtb)
{
    for(int i(0); i<n; i++)
    {
        if(sv[i].dtb==dtb)
            return sv[i];
    }
}

//Bài 3.8: Trả về 10 sinh viên có điểm trung bình cao nhất
void dtbTop10_max(SINHVIEN sv[], int n, SINHVIEN t10_max[])
{
    //tmp[] = sv[]
    SINHVIEN tmp[200];
    for(int i(0); i<n; i++)
    {
        tmp[i] = sv[i];
    }

    for(int i(0); i<n-1; i++)
    {
        for(int j(i+1); j<n; j++)
        {
            if(tmp[i].dtb<tmp[j].dtb)
                swap(tmp[i], tmp[j]);
        }
    }

    for(int i(0); i<10; i++)
    {
        t10_max[i] = tmp[i];
    }
}

//Bài 3.9: Trả về 10 sinh viên có điểm trung bình thấp nhất
void dtbTop10_min(SINHVIEN sv[], int n, SINHVIEN t10_min[])
{
    //tmp[] = sv[]
    SINHVIEN tmp[200];
    for(int i(0); i<n; i++)
    {
        tmp[i] = sv[i];
    }

    for(int i(0); i<n-1; i++)
    {
        for(int j(i+1); j<n; j++)
        {
            if(tmp[i].dtb>tmp[j].dtb)
                swap(tmp[i], tmp[j]);
        }
    }

    for(int i(0); i<10; i++)
    {
        t10_min[i] = tmp[i];
    }
}

int main()
{
    srand(time(0));
    SINHVIEN sv[200];
    int n;

    cout << "-------------------------------------------Bai 3.1----------------------------------------------" << endl;
    nhap(sv,n);
    xuat(sv,n);

    cout << "-------------------------------------------Bai 3.2----------------------------------------------" << endl;
    tudong(sv,n);

    cout << "-------------------------------------------Bai 3.3----------------------------------------------" << endl;
    xuat(sv,n);

    cout << "-------------------------------------------Bai 3.4----------------------------------------------" << endl;
    xuat_dtbMax(sv,n);

    cout << "-------------------------------------------Bai 3.5----------------------------------------------" << endl;
    XepLoai(sv,n);
    xuat(sv,n);

    cout << "-------------------------------------------Bai 3.6----------------------------------------------" << endl;
    int mssv = sv[5].mssv;
    SINHVIEN sinhv1;
    cout << "Nhap MSSV: " << mssv << endl;
    sinhv1 = timSV_msv(sv,n,mssv);
    cout << "MSSV: " << sinhv1.mssv << endl;
    cout << "Ho va ten: " << sinhv1.ten << endl;
    cout << "Diem trung binh: " << sinhv1.dtb << endl;
    cout << "Xep loai: " << sinhv1.xeploai << endl;

    cout << "-------------------------------------------Bai 3.7----------------------------------------------" << endl;
    float dtb = sv[6].dtb;
    SINHVIEN sinhv2;
    cout << "Nhap DTB: " << dtb << endl;
    sinhv2 = timSV_dtb(sv,n,dtb);
    cout << "MSSV: " << sinhv2.mssv << endl;
    cout << "Ho va ten: " << sinhv2.ten << endl;
    cout << "Diem trung binh: " << sinhv2.dtb << endl;
    cout << "Xep loai: " << sinhv2.xeploai << endl;

    cout << "-------------------------------------------Bai 3.8----------------------------------------------" << endl;
    SINHVIEN t10_max[10];
    dtbTop10_max(sv,n,t10_max);
    xuat(t10_max,10);

    cout << "-------------------------------------------Bai 3.9----------------------------------------------" << endl;
    SINHVIEN t10_min[10];
    dtbTop10_min(sv,n,t10_min);
    xuat(t10_min,10);

    return 0;
}
