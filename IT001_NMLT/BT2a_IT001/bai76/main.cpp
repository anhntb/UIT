#include <iostream>

using namespace std;

bool check3(int n)
{
    if(n<=0) return false;
    if(n==1) return true;
    if(n%3==0) return check3(n/3);
    else return false;
}

int main()
{
    int n;
    cin >> n;
    cout << (check3(n) ? "Yes" : "No");
    return 0;
}
