#include <iostream>
#include <time.h>

using namespace std;

void arr_tudong(float arr[], int &n)
{
    cout << "Nhap n: ";
    cin >> n;
    srand(time(0));
    for(int i(0); i<n; i++)
    {
        arr[i] = (-990 + rand()%(990+990+1))/10.; // random [-990;990] / 10
        cout << arr[i] << "   ";
    }
    cout << endl;
}
