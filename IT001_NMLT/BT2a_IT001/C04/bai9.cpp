#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    char k;
    float n;
    int money;
    cin >> n;
    n = ceil(n);//làm tròn lên, floor(): làm tròn xuống
    if(n>0) k='a';
    else cout << "Error!!!";
    if(n>1) k='b';
    if(n>5) k='c';
    if(n>120) k='d';
    switch(k)
    {
        case 'a':
            money = 15000;
            break;
        case 'b':
            money = 15000 + 13500*(n-1);
            break;
        case 'c':
            money = 15000 + 13500*4 + 11000*(n-5);
            break;
        case 'd':
            money = (15000 + 13500*4 + 11000*(n-5))*0.9;
            break;
    }
    cout << money;
    return 0;
}
