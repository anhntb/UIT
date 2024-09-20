#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int noneSTL(vector<double> v, double n)
{
    v.push_back(n);
    int i = 0;

    while(n!=v.at(i))
        i++;

    return (i==v.size()-1) ? -1 : i;
}

int useSTL(vector<double> v, double n)
{
    return find(v.begin(), v.end(), n) == v.end() ? -1 : find(v.begin(), v.end(), n) - v.begin();
}

int main()
{
    double arr[] = {1.2, 2, 4, 0.4, -3, -5.4, 11, 3.6, 0, -3.8};
    vector<double> v(arr, arr+10);

    cout << "Vector: " ;
    for(vector<double>::iterator i = v.begin(); i < v.end(); i++)
        cout << *i << "   ";
    cout << endl;

    cout << "Nhap n: ";
    int n;
    cin >> n;

    cout << "a.Khong su dung thu vien STL: " << noneSTL(v, n) << endl;
    cout << "b.Su dung thu vien STL: " << useSTL(v, n);

    return 0;
}
