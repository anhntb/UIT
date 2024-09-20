//Selection sort

#include <iostream>

using namespace std;

bool myFunc(int a, int b, bool asc)
{
    if(asc)
        return a <= b;

    return a >= b;
}

void selectionSort(int a[], int n, bool asc = 1) //ascending
{
    for(int i=0; i<n; i++)
    {
        int min_idx = i;
        for(int j=i+1; j<n; j++)
            if(!myFunc(a[min_idx], a[j], asc))
                min_idx = j;

        int tmp = a[i];        
        a[i] = a[min_idx];
        a[min_idx] = tmp;
    }
}

void inputArr(int* &a, int &n)
{
    cin >> n;

    a = new int[n];
    for(int i(0); i<n; i++)
        cin >> a[i];
}

void printArr(int a[], int n)
{
    for(int i=0; i<n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    int* arr;

    inputArr(arr, n);
    selectionSort(arr, n, 0);
    printArr(arr, n);

    return 0;
}
