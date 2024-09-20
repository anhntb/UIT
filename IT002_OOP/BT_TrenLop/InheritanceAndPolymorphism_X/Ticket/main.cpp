#include "CongVien.h"

int main()
{
    CongVien* a = new CongVien;
    a->NhapDSVe();
    cout << "---------------------------------------------" << endl;

    CongVien b(*a);
    b.XuatDSVe();
    
    return 0;
}