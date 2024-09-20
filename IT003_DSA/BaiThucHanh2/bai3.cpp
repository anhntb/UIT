// Quick sort

#include <iostream>
#include <cmath>

using namespace std;

// ascending
int partition_as(int arr[], int low, int high)
{
    int left = low;
    int right = high-1;
    int pivot = arr[high];
    while(true)
    {
        while(arr[left]<pivot && left<=right) left++;
        while(arr[right]>pivot && right>=left) right--;
        if(left>=right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void quickSort_as(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi = partition_as(arr, low, high); //pi: index's pivot
        quickSort_as(arr, low, pi-1);
        quickSort_as(arr, pi+1, high);
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
    quickSort_as(arr, 0, n); // ascending
    printArr(arr, n);

    return 0;
}
