#include <iostream>

using namespace std;

int main()
{
    float c_cao, c_nang;
    cout << "Chieu cao(m): ";
    cin >> c_cao;
    cout << "Can nang(kg): ";
    cin >> c_nang;
    cout << "BMI: " << c_nang/(c_cao*c_cao);
    return 0;
}
