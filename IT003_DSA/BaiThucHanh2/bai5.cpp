#include <iostream>
#include <algorithm>

using namespace std;

void inputArr(int* &a, int &n)
{
    cin >> n;

    a = new int[n];
    for(int i(0); i<n; i++)
        cin >> a[i];
}

int MEX(int* a, int n) //minimum excluded
{
    sort(a, a+n);
    if(a[0] != 0) return 0;

    for(int i=1 ; i<n; i++)
        if(a[i] != a[i-1]+1)
            return a[i-1]+1;
    
    //! tự trả về giá trị đúng mà không cần return
    //! tùy loại trình biên dịch, kết quả trả về khác nhau
    return n;
}

int main()
{
    int n;
    int* arr;

    inputArr(arr, n);
    cout << MEX(arr, n);

    return 0;
}










