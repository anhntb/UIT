#include <iostream>
#include <time.h>

using namespace std;

void tao_tudong(int arr[], int &n)
{
    srand(time(0));
    n=rand()%(15-8+1)+8;
    for(int i(0); i<(n/2.); i++)
    {
        arr[i] = -51+rand()%(78+51+1);
        arr[n-1-i] = arr[i];
    }
    for(int i(0); i<n; i++)
        cout << arr[i] << "\t";
}
