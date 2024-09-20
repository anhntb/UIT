#include "CongVien.h"

CongVien::CongVien(){}

CongVien::CongVien(const CongVien &a)
{
    *this = a;
}

CongVien::~CongVien()
{
    for(int i=0; i<n; i++)
        delete list[i];
    delete[] list;
}

CongVien& CongVien::operator = (const CongVien &a)
{
    n = a.n;
    list = new Ve*[n];

    for(int i=0; i<n; i++)
    {
        if(a.list[i]->getLoaiVe())
        {
            list[i] = new VeTronGoi;
            *list[i] = *a.list[i];
        }
        else
        {
            list[i] = new VeTungPhan;
            *(VeTungPhan*)list[i] = *(VeTungPhan*)a.list[i];
        }
    }

    return *this;
}

void CongVien::NhapDSVe()
{
    cout << "So ve: ";
    cin >> n;

    bool loaiVe;
    list = new Ve*[n];
    for(int i=0; i<n; i++)
    {
        cout << "+Ve " << i+1 << endl;
        cout << "Loai ve(1:Tron goi / 0:Tung phan): ";
        cin >> loaiVe;
        if(loaiVe)
        {
            list[i] = new VeTronGoi;
            list[i]->inpVe();
        }
        else
        {
            list[i] = new VeTungPhan;
            list[i]->inpVe();
        }
        cout << endl;
    }
}

void CongVien::XuatDSVe() const
{   
    for(int i=0; i<n; i++)
    {
        list[i]->outVe();
        cout << endl;
    }
}

int CongVien::TongTienVe() const
{
    int s = 0;
    for(int i=0; i<n; i++)
        s += list[i]->iThanhTien();
    return s;
}

int CongVien::DemVeTungPhan() const
{
    int d = 0;
    for(int i=0; i<n; i++)
        if(!list[i]->getLoaiVe())
            d++;
    return d;
}