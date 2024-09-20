#pragma once

#include "Ve.h"

class CongVien
{
private:
    Ve** list;
    int n = 0;

public:
    CongVien();
    CongVien(const CongVien &a);
    ~CongVien();

    CongVien& operator = (const CongVien &a);

    void NhapDSVe();
    void XuatDSVe() const;
    int TongTienVe() const;
    int DemVeTungPhan() const;
};