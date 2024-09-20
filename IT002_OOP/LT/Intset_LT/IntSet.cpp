#include <iostream>
#include <algorithm>

using namespace std;

class Intset
{
private:
    int* pValue;
    int iSize;

public:
    Intset() : iSize(0) {}

    Intset(const Intset &b) //* copy constructor
    {   
        iSize = b.iSize;
        pValue = new int[iSize];
        for(int i=0; i<iSize; i++)
            pValue[i] = b.pValue[i];
    }
    
    Intset(int n)
    {
        iSize = 1;
        pValue = new int[1];
        pValue[0] = n;
    }
    
    ~Intset()
    {
        delete[] pValue;
    }

    int getiSize()
    {
        return iSize;
    }

    // Intset operator = (const Intset &b)
    // {
    //     iSize = b.iSize;
    //     pValue = new int[iSize];
    //     for(int i=0; i<iSize; i++)
    //         pValue[i] = b.pValue[i];
    //     return b;
    // }
    Intset& operator = (const Intset &b)
    {
        iSize = b.iSize;
        pValue = new int[iSize];
        for(int i=0; i<iSize; i++)
            pValue[i] = b.pValue[i];
        return *this;
    }

    Intset operator [] (int n)
    {
        return pValue[n];
    }

    friend istream & operator >> (istream &, Intset &);
    friend ostream & operator << (ostream &, const Intset &);
    friend Intset operator + (const Intset &, const Intset &);
    friend Intset operator - (const Intset &, const Intset &);
};

//? không thể thực hiện c = a + (Intset)1 + (Intset)2 + 3 +...
//? từ dấu + thứ 3 sẽ bị lỗi chèn mất dữ liệu
Intset operator + (const Intset &a, const Intset &b)
{   
    Intset c;
    c.iSize = a.iSize;
    c.pValue = new int[a.iSize + b.iSize]; //! phải cấp phát ô nhớ, tránh lỗi chèn đè bộ nhớ
    for(int i=0; i<a.iSize; i++)
        c.pValue[i] = a.pValue[i];

    for(int i = 0; i < b.iSize; i++)
        if(!binary_search(a.pValue, a.pValue + a.iSize, b.pValue[i]))
        {
            c.pValue[c.iSize] = b.pValue[i];
            c.iSize++;
        }
    return c;
}

Intset operator - (const Intset &a, const Intset &b)
{   
    Intset c(a);
    for(int i = 0; i < b.iSize; i++)
    {
        int* tmp = find(c.pValue, c.pValue + c.iSize, b.pValue[i]);
        if(tmp != c.pValue + c.iSize)
        {
            int k = tmp - c.pValue;
            for(k; k < c.iSize-1; k++)
                c.pValue[k] = c.pValue[k+1];
            c.iSize--;
        }
    }
    return c;
}

istream & operator >> (istream &is, Intset &a)
{
    is >> a.iSize;
    delete[] a.pValue; //! phải xóa ô nhớ cũ, tránh bị chèn đè dữ liệu
    a.pValue = new int[a.iSize];

    for(int i=0; i<a.iSize; i++)
        do
        {
            is >> a.pValue[i];
        }while(find(a.pValue, a.pValue + i, a.pValue[i]) != a.pValue + i);

    sort(a.pValue, a.pValue + a.iSize);
    return is;
}

ostream & operator << (ostream &os, const Intset &a)
{
    if(a.iSize == 0)
    {
        os << "The set of integers is empty!" << endl;
        return os;
    }

    for(int i=0; i<a.iSize; i++)
        os << a.pValue[i] << " ";
    return os;
}

int main()
{
    Intset a(100);

    Intset b(a), c=a; //* copy constructor

    Intset d;
    d = a; //* operator =

    cout << a + (Intset)1 + (Intset)2 + (Intset)3 + (Intset)4 + (Intset)5 + (Intset)6 + (Intset)7 + (Intset)8;

    cout << "\nend";
    return 0;
}