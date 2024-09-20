//#include <bits/stdc++.h>
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

class NhanVien
{
private:
	string strName;
	string strDOB;

protected:
	int iLuongCoBan;
	int iType = -1; // 0: Nhân viên văn phòng
			   		// 1: Nhân viên sản xuất
			   		// 2: Nhân viên quản lý

public:
	NhanVien(string name = "", string dob = "1/1/1", int coBan = 0) : strName(name), strDOB(dob), iLuongCoBan(coBan) {}

	string getStrName() const
	{
		return strName;
	}

	void setStrName(string name)
	{
		strName = name;
	}

	string getDOB() const
	{
		return strDOB;
	}

	void setDOB(string dob)
	{
		strDOB = dob;
	}

	int getiLuongCoBan() const
	{
		return iLuongCoBan;
	}

	void setiLuongCoBan(int n)
	{
		iLuongCoBan = n;
	}

	int getiType() const
	{
		return iType;
	}

	virtual void inputInfor()
	{
		fflush(stdin);
		cout << "Ho ten: ";
		getline(cin, strName);

		cout << "Ngay sinh: ";
		getline(cin, strDOB);

		cout << "Luong co ban: ";
		cin >> iLuongCoBan;
	}

	virtual void display() const
	{
		cout << "Ho ten: " << strName << endl;
		cout << "Ngay sinh: " << strDOB << endl;
		cout << "Luong co ban: " << iLuongCoBan << endl;
	}

	virtual int salary() const = 0;
};

class NVVanPhong : public NhanVien
{
private:
	int iNumOWDay; // Number of work days
	int iAllo; // Allowances

public:
	NVVanPhong(int workDay = 0, int troCap = 0) : NhanVien()
	{
		iType = 0;
		iNumOWDay = workDay;
		iAllo = troCap;
	}

	int getiNumOwDay() const
	{
		return iNumOWDay;
	}

	void setiNumOWDay(int n)
	{
		iNumOWDay = n;
	}

	int getiAllo() const
	{
		return iAllo;
	}

	void setiAllo(int n)
	{
		iAllo = n;
	}

	int salary() const
	{
		return iLuongCoBan + iNumOWDay*200000 + iAllo;
	}

	void inputInfor()
	{
		NhanVien::inputInfor();
		cout << "So ngay lam viec: ";
		cin >> iNumOWDay;
		cout << "Tro cap: ";
		cin >> iAllo;
	}

	void display() const
	{
		NhanVien::display();
		cout << "So ngay lam viec: " << iNumOWDay << endl;
		cout << "Tro cap: " << iAllo << endl;
		cout << "Luong: " << salary() << endl;
	}
};

class NVSanXuat : public NhanVien
{
private:
	int iSoSanPham;

public:
	NVSanXuat(int sanPham = 0) : NhanVien()
	{
		iType = 1;
		iSoSanPham = sanPham;
	}

	int getiSoSanPham() const
	{
		return iSoSanPham;
	}

	void setiSoSanPham(int n)
	{
		iSoSanPham = n;
	}
	
	int salary() const
	{
		return iLuongCoBan + iSoSanPham*2000;
	}

	void inputInfor()
	{
		NhanVien::inputInfor();
		cout << "So san pham: ";
		cin >> iSoSanPham;
	}

	void display() const
	{
		NhanVien::display();
		cout << "So san pham: " << iSoSanPham << endl;
		cout << "Luong: " << salary() << endl;
	}
};

class NVQuanLy : public NhanVien
{
private:
	int iHeSo;
	int iThuong;

public:
	NVQuanLy(int heSo = 0, int thuong = 0) : NhanVien()
	{
		iType = 2;
		iHeSo = heSo;
		iThuong = thuong;
	}

	int getiHeSo() const
	{
		return iHeSo;
	}

	void setiHeSo(int n)
	{
		iHeSo = n;
	}
	
	int getiThuong() const
	{
		return iThuong;
	}

	void setiThuong(int n)
	{
		iThuong = n;
	}

	int salary() const
	{
		return iLuongCoBan*iHeSo + iThuong;
	}

	void inputInfor()
	{
		NhanVien::inputInfor();
		cout << "He so chuc vu: ";
		cin >> iHeSo;
		cout << "Thuong: ";
		cin >> iThuong;
	}

	void display() const
	{
		NhanVien::display();
		cout << "He so chuc vu: " << iHeSo << endl;
		cout << "Thuong: " << iThuong << endl;
		cout << "Luong: " << salary() << endl;
	}
};

class CongTy
{
private:
	int iSoNhanVien = 0;
	NhanVien** List;

public:
	CongTy(){}

	CongTy(const CongTy &a) //copy constructor
	{
		*this = a;
	}

	~CongTy() //destructor
	{
		for(int i = 0; i<iSoNhanVien; i++)
			delete[] List[i];
		
		delete[] List;
	}

	//! phải tham chiếu argument(đối số) thì không cần viết lại toàn bộ ở copy constructor
	CongTy& operator = (const CongTy &a) 
	{
		iSoNhanVien = a.iSoNhanVien;
		List = new NhanVien*[iSoNhanVien];
		for(int i = 0; i<iSoNhanVien; i++)
		{
			switch (a.List[i]->getiType())
			{
				case 0:
					List[i] = new NVVanPhong;
					//! cả 2 phải cùng ép về kiểu lớp con
					//! tránh mất những dữ liệu chỉ có ở con mà không có ở cha
					*(NVVanPhong*)List[i] = *(NVVanPhong*)a.List[i];
				break;

				case 1:
					List[i] = new NVSanXuat;
					*(NVSanXuat*)List[i] = *(NVSanXuat*)a.List[i];
				break;

				case 2:
					List[i] = new NVQuanLy;
					*(NVQuanLy*)List[i] = *(NVQuanLy*)a.List[i];
			}
		}
		return *this;
	}

	int getiSoNhanVien()
	{
		return iSoNhanVien;
	}

	long int sumSalary() const
	{
		long int s = 0;

		for(int i = 0; i<iSoNhanVien; i++)
			s += List[i]->salary();
		return s;
	}

	bool findEmployee(string name)
	{
		for(int i = 0; i<iSoNhanVien; i++)
			if(List[i]->getStrName() == name)
			{
				List[i]->display();
				return true;
			}
		return false;
	}

	void inputInfor()
	{
		cout << "So luong nhan vien: ";
		cin >> iSoNhanVien;
		List = new NhanVien*[iSoNhanVien];

		cout << "\nNhap thong tin tung nhan vien" << endl;
		int iT;
		for(int i = 0; i<iSoNhanVien; i++)
		{
			cout << "+Loai(0, 1, 2): ";
			cin >> iT;
			switch (iT)
			{
				case 0:
					List[i] = new NVVanPhong;
				break;

				case 1:
					List[i] = new NVSanXuat;
				break;

				case 2:
					List[i] = new NVQuanLy;
			}
			List[i]->inputInfor();
			cout << endl;
		}
	}

	void display() const
	{
		for(int i = 0; i<iSoNhanVien; i++)
		{
			List[i]->display();
			cout << endl;
		}
	}
};

int main()
{
	// CongTy tmp;

	// cout << "-----Nhap thong tin nhan vien-----" << endl;
	// tmp.inputInfor();

	// cout << "\n-----Thong tin tung nhan vien-----" << endl;
	// tmp.display();

	// cout << "Tong luong cua cong ty: " << tmp.sumSalary() << endl;

	// cout << "\nTim nhan vien theo ho ten" << endl;
	// cout << "Nhap ho ten: ";
	// string name;
	// fflush(stdin);
	// getline(cin, name);
	// cout << (tmp.findEmployee(name) ? "" : "Khong tim thay nhan vien!") << endl; 

	return 0;
}