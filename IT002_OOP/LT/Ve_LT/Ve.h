#pragma once

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Ve
{
private:
    string sMaVe;
    string sChuVe;
    int iNamSinh;

protected:
    bool bLoaiVe; //true: trọn gói         false: từng phần

public:
    Ve();

    void setMaVe(string mave);
    void setChuVe(string chuve);
    void setNamSinh(int namsinh);

    string getMaVe();
    string getChuVe();
    int getNamSinh();

    virtual void inpVe();
    virtual void outVe() const;

    virtual bool getLoaiVe() const = 0;
    virtual int iThanhTien() const = 0;
};

class VeTronGoi : public Ve
{
private:
    int iGiaTG = 200000;

public:
    VeTronGoi();

    int iThanhTien() const;
    bool getLoaiVe() const;
    void outVe() const;
};

class VeTungPhan : public Ve
{
private:
    int iSoTC;
    int iThemTC = 20000;
    int iVaoCong = 70000;

public:
    VeTungPhan();

    int iThanhTien() const;
    bool getLoaiVe() const;
    void inpVe();
    void outVe() const;
};


