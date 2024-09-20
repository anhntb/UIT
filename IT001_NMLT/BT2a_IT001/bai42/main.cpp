#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int a = n*(n+1)/2;
    for(int i=n; i>0; i--)
    {
        a-=i;
        if(a<n)
        {
            cout << i-1;
            exit(0);
        }
    }
    return 0;
}
