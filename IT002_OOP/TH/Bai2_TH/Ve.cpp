#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class Ve
{
private:
    string strMaVe;
    int iSoTroChoi;
    const int iGiaCong = 70;
    const int iGiaTroChoi = 20;

public:
    Ve(string Ma = "", int SoTC = 0) : strMaVe(Ma), iSoTroChoi(SoTC<0 ? 0 : SoTC) {}

    void Nhap()
    {
        fflush(stdin);
        cout << "Ma ve: ";
        getline(cin, strMaVe);

        cout << "So tro choi: ";
        cin >> iSoTroChoi;
        if(iSoTroChoi < 0)
            iSoTroChoi = 0;
    }

    void Xuat()
    {
        cout << "Ma ve: " << strMaVe << endl;
        cout << "So tro choi: " << iSoTroChoi << endl;
        cout << "Gia vao cong: " << iGiaCong << endl;
        cout << "Gia 1 tro choi them: " << iGiaTroChoi << endl;
        cout << "Tong tien: " << TinhTien() << " nghin dong" << endl;
    }

    int TinhTien()
    {
        return iGiaCong + iGiaTroChoi*iSoTroChoi;
    }
};

int main()
{
    int n;
    cout << "So ve: ";
    cin >> n;

    Ve* a = new Ve[n];
    int s = 0;
    for(int i=0; i<n; i++)
    {
        cout << "+ Ve" << i+1 << endl;
        a[i].Nhap();
        s += a[i].TinhTien();
    }

    cout << "\nTong tien: " << s << " nghin dong" << endl;
    
    return 0;
}