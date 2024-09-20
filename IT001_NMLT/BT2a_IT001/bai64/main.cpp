#include <iostream>

using namespace std;

int main()
{
    float a,b;
    cin >> a >> b;
    if(a==0) cout << ((b!=0) ? "Vo nghiem" : "Vo so nghiem");
    else cout << "x = " << (b==0 ? 0 : -b/a);
    return 0;
}
