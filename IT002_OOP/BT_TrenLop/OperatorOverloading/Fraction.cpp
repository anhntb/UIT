/*
Nạp chồng các toán tử cho class Fraction (+, -, *, /, +=, &, ...)
*/

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Fraction
{
private:
    int iNume; //*Numerator: Tử số
    int iDeno; //*Denominator: Mẫu số

public:
    Fraction(int iN=0, int iD=1) : iNume(iN), iDeno(iD)
    {
        if(!iD) //iD==0
        {
            iNume = 0;
            iDeno = 1;
        }

        if(iN*iD<0) 
        {
            iNume = -abs(iN);
            iDeno = abs(iD);
        }

        if(iN<0 && iD<0)
        {
            iNume = -iN;
            iDeno = -iD;
        }
    }

    int getiNume() const
    {
        return iNume;
    }

    int getiDeno() const
    {
        return iDeno;
    }

    void setiNume(int n)
    {
        iNume = n;
    }

    void setiDeno(int n)
    {
        iDeno = n;

        if(n<0)
        {
            iNume = -iNume;
            iDeno = -n;
        }

        if(!n) //n==0
        {
            iNume = 0;
            iDeno = 1;
        }
    }

    void ReduceFra()
    {
        int a = abs(iNume);
        int b = abs(iDeno);

        while(b) //b!=0
        {
            int tmp = a;
            a = b;
            b = tmp%b;
        }

        iNume /= a;
        iDeno /= a;
    }

/*Không cần viết 3 hàm cho 3 trường hợp: 
    Fraction a + Fraction b
    Fraction a + int n
    int n + Fraction 3
//*Dùng chuyển kiểu tự động của Constructor 

    Fraction operator + (Fraction a) const
    {
        Fraction kq;
        kq.iDeno = iDeno*a.iDeno;
        kq.iNume = iNume*a.iDeno + iDeno*a.iNume;

        kq.ReduceFra();
        return kq;
    }

    Fraction operator + (int n) const
    {
        Fraction a(iNume, iDeno);
        Fraction b(n);
        
        return a+b;
    }
*/

//*Ép kiểu Fraction -> string,...
    operator string() const
    {
        string s = to_string(iNume) + "/" + to_string(iDeno);
        return s;
    }

//!có thể gặp lỗi nhập nhằng
//* vd: Fraction a + 3
//* có 2 cách cộng, hoặc là cùng chuyển về kiểu Fraction, hoặc cùng kiểu double
//* compiler không biết chọn cách nào
//? cách giải quyết: khai báo kiểu rõ ràng -> (double)a + 3 || a + (Fraction)3
    operator double() const
    {
        return (double)iNume/iDeno;
    }

    Fraction operator = (const Fraction &b)
    {
        iDeno = b.iDeno;
        iNume = b.iNume;
        return b;
    }

};

//todo: nạp chồng toán tử nhập(>>), xuất(<<)
//! const Fraction& ps: không được phép thay đổi giá trị, chỉ được gọi hàm const của class
ostream & operator << (ostream &output, const Fraction &a) 
{
    output << a.getiNume() << "/" << a.getiDeno();
    return output;
}

istream & operator >> (istream &input, Fraction &a)
{
    int iN, iD;
    input >> iN >> iD;

    a.setiNume(iN);
    a.setiDeno(iD);
    return input;
}

Fraction operator + (Fraction a, Fraction b)
{
    Fraction sum;
    sum.setiDeno(a.getiDeno()*b.getiDeno());
    sum.setiNume(a.getiNume()*b.getiDeno() + a.getiDeno()*b.getiNume());

    sum.ReduceFra();
    return sum;
}

Fraction operator - (Fraction a, Fraction b)
{
    Fraction difference;
    difference.setiDeno(a.getiDeno()*b.getiDeno());
    difference.setiNume(a.getiNume()*b.getiDeno() - a.getiDeno()*b.getiNume());

    difference.ReduceFra();
    return difference;
}

Fraction operator * (Fraction a, Fraction b)
{
    Fraction product;
    product.setiDeno(a.getiDeno()*b.getiDeno());
    product.setiNume(a.getiNume()*b.getiNume());

    product.ReduceFra();
    return product;
}

Fraction operator / (Fraction a, Fraction b)
{
    Fraction quotient;
    quotient.setiDeno(a.getiDeno()*b.getiDeno());
    quotient.setiNume(a.getiNume()*b.getiNume());

    quotient.ReduceFra();
    return quotient;
}

int main()
{
    Fraction a(1,3), b(7,3), d(10,2);
    d = b = a;
    cout << "d: " << d << endl;
    cout << "a: " << a << endl;
    cout << "b: ";
    cin >> b;

    cout << "----------SUM----------" << endl;
    cout << a << " + " << b << " = " << a+b << endl;
    cout << a << " + (Fraction)3" << " = " << a + (Fraction)3 << endl;
    cout << "(Fraction)3 + " << a << " = " << (Fraction)3 + a << endl;

    cout << "\n----------DIFFERENCE----------" << endl;
    cout << a << " - " << b << " = " << a-b << endl;
    cout << a << " - (Fraction)3" << " = " << a - (Fraction)3 << endl;
    cout << "(Fraction)3 - " << a << " = " << (Fraction)3 - a << endl;

    cout << "\n----------PRODUCT----------" << endl;
    cout << a << " * " << b << " = " << a*b << endl;
    cout << a << " * (Fraction)3" << " = " << a * (Fraction)3 << endl;
    cout << "(Fraction)3 * " << a << " = " << (Fraction)3 * a << endl;

    cout << "\n----------QUOTIENT----------" << endl;
    cout << a << " / " << b << " = " << a/b << endl;
    cout << a << " / (Fraction)3" << " = " << a / (Fraction)3 << endl;
    cout << "(Fraction)3 / " << a << " = " << (Fraction)3 / a << endl;

    return 0;
}