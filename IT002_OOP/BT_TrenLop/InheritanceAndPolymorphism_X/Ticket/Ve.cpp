#include "Ve.h"

Ve::Ve(){}

void Ve::setMaVe(string mave)
{
    sMaVe = mave;
}

void Ve::setChuVe(string chuve)
{
    sChuVe = chuve;
}

void Ve::setNamSinh(int namsinh)
{
    iNamSinh = namsinh;
}

string Ve::getMaVe()
{
    return sMaVe;
}

string Ve::getChuVe()
{
    return sChuVe;
}

int Ve::getNamSinh()
{
    return iNamSinh;
}

void Ve::inpVe()
{
    fflush(stdin);
    cout << "Ma ve: ";
    getline(cin, sMaVe);

    cout << "Ho ten chu ve: ";
    getline(cin, sChuVe);

    cout << "Nam sinh: ";
    cin >> iNamSinh;
}

void Ve::outVe() const
{
    cout << "Ma ve: " << sMaVe << endl;
    cout << "Ho ten chu ve: " << sChuVe << endl;
    cout << "Nam sinh: " << iNamSinh << endl;
    cout << "Loai ve(1:Tron goi / 0:Tung phan): " << bLoaiVe << endl;
}


VeTronGoi::VeTronGoi()
{
    bLoaiVe = 1;
}

int VeTronGoi::iThanhTien() const
{
    return iGiaTG;
}

bool VeTronGoi::getLoaiVe() const
{
    return bLoaiVe;
}

void VeTronGoi::outVe() const
{
    Ve::outVe();
    cout << "Thanh tien: " << iThanhTien() << endl;
}


VeTungPhan::VeTungPhan()
{
    bLoaiVe = 0;
}

int VeTungPhan::iThanhTien() const
{
    return iVaoCong + iSoTC*iThemTC;
}

bool VeTungPhan::getLoaiVe() const
{
    return bLoaiVe;
}

void VeTungPhan::inpVe()
{
    Ve::inpVe();
    cout << "So tro choi tham gia: ";
    cin >> iSoTC;
}

void VeTungPhan::outVe() const
{
    Ve::outVe();
    cout << "So tro choi tham gia: " << iSoTC << endl;
    cout << "Thanh tien: " << iThanhTien() << endl;
}



