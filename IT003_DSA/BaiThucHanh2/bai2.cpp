//Insertion sort

#include <iostream>

using namespace std;

bool myFunc(int a, int b, bool asc)
{
    if(asc)
        return a <= b;

    return a >= b;
}

void insertionSort(int a[], int n, bool asc = 1) //ascending
{
    for(int i=1; i<n; i++)
    {
        int j = i - 1;
        int tmp = a[i];
        while(myFunc(tmp, a[j], asc) && j>=0)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = tmp;
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
    insertionSort(arr, n);
    printArr(arr, n);

    return 0;
}
