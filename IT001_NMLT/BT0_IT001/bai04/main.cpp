#include <iostream>

using namespace std;

int main()
{
    int n;
    float S_a(0), S_b(0), S_c(0), S_d(1), S_e(0);
    cout << "Nhap n: ";
    cin >> n;


    for(int i=1; i<=n; i++)
    {
//Cau a: S = 1+2+...+n
        S_a += i;

//Cau b: S = 1^2 + 2^2 + ... + n^2
        S_b += i*i;

//Cau c: S = 1 + 1/2 + ... + 1/n
        S_c += 1./i;

//Cau d: S = 1*2*...*n
        S_d *= i;

//Cau e: S = 1! + 2! + ... + n!
        S_e += S_d;
    }

    cout << "a) S = " << S_a << endl;
    cout << "b) S = " << S_b << endl;
    cout << "c) S = " << S_c << endl;
    cout << "d) S = " << S_d << endl;
    cout << "e) S = " << S_e << endl;

    return 0;
}
