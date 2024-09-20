#include "TroChoi.cpp"

int main()
{
    TroChoi* a = new TroChoi;

    a->inpInfor();
    cout << "------------------------------------" << endl;
    a->display();

    cout << "\nDoi tuong co muc sat thuong cao nhat" << endl;
    a->satThuongCaoNhat()->thongTin();

    DoiTuong *A, *B;
    bool isNhanVat;

    cout << "\nTao doi tuong A" << endl;
    cout << "Loai(1:nhanvat / 0:quaivat): ";
    cin >> isNhanVat;
    if(isNhanVat)
        A = new NhanVat;
    else
        A = new QuaiVat;
    A->khoiTao();

    cout << "\nTao doi tuong B" << endl;
    cout << "Loai(1:nhanvat / 0:quaivat): ";
    cin >> isNhanVat;
    if(isNhanVat)
        B = new NhanVat;
    else
        B = new QuaiVat;
    B->khoiTao();

    cout << "A sat thuong len B: " << A->satThuongGayRa(B) << endl;
    cout << "B sat thuong len A: " << B->satThuongGayRa(A) << endl;

    return 0;
}