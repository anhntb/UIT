#include <iostream>

using namespace std;

bool so_ngto(int n);

int tong_ngto(int n)
{
    int s(0);
    for(int i(2); i<n; i++)
        if(so_ngto(i)) s += i;
    return s;
}
