#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    float s(0);
    cin >> n;
    for(int i=1; i<=n; i++) s += pow(-1,i+1)/(i*(i+1)/2);
    cout << s;
    return 0;
}
