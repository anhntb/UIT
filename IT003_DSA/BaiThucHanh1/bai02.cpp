#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int noneSTL(vector<double> v, double n)
{
    int left = 0;
    int right = v.size() - 1;

    while(left<=right)
    {
        int mid = left + (right-left)/2;

        if(n==v.at(mid))
            return mid;

        if(n>v.at(mid))
            left = mid + 1;

        if(n<v.at(mid))
            right = mid - 1;
    }

    return -1;
}

int useSTL(vector<double> v, double n)
{
    return binary_search(v.begin(), v.end(), n);
}

int main()
{
    double arr[] = {1.2, 2, 4, 0.4, -3, -5.4, 11, 3.6, 0, -3.8};
    vector<double> v(arr, arr+10);

    sort(v.begin(), v.end());

    cout << "Vector: " ;
    for(vector<double>::iterator i = v.begin(); i < v.end(); i++)
        cout << *i << "   ";
    cout << endl;

    cout << "Nhap n: ";
    int n;
    cin >> n;

    cout << "a.Khong su dung thu vien STL: " << noneSTL(v, n) << endl;
    cout << "b.Su dung thu vien STL: " << (useSTL(v, n) ? "Find!" : "Not find!");

    return 0;
}
