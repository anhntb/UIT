#include <iostream>

using namespace std;

bool check2(int n)
{
    if(n<=0) return false;
    if(n==1) return true;
    if(n%2==0) return check2(n/2);
    else return false;
}

int main()
{
    int n;
    cin >> n;
    cout << (check2(n) ? "Yes" : "No");
    return 0;
}
