/*
Tính tổng 2 số phức
//*z = a + bi
*/

#include <iostream>

using namespace std;

struct sophuc
{
    int phanthuc, phanao;
};

void nhapsp(sophuc &sp)
{
    cout << "Nhap phan thuc:";
    cin >> sp.phanthuc;
    cout << "Nhap phan ao:";
    cin >> sp.phanao;
}

void xuatsp(sophuc sp)
{
    cout << sp.phanthuc << " + " << sp.phanao << "i" << endl;
}

sophuc tongsp(sophuc sp1, sophuc sp2)
{
    sophuc kq;
    kq.phanthuc = sp1.phanthuc + sp2.phanthuc;
    kq.phanao = sp1.phanao + sp2.phanao;
    return kq;
}

int main()
{
    sophuc sp1, sp2;
    cout << "Tao so phuc 1\n";
    nhapsp(sp1);
    xuatsp(sp1);
    cout << "Tao so phuc 2\n";
    nhapsp(sp2);
    xuatsp(sp2);
    cout << "Tong = ";
    xuatsp(tongsp(sp1,sp2));
    return 0;
}