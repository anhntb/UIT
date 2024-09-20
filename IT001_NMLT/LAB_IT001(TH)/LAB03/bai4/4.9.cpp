#include <iostream>

using namespace std;

bool chinhphuong(int n);

int tong_chinhphuong(int n)
{
    int s(0);
    for(int i(1); i<n; i++)
        if(chinhphuong(i)) s += i;
    return s;
}
