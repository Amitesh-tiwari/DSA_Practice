#include <iostream>
using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int binarysearch(int arr[], int n, int key)
{
    int start = 0, end = n - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        if (key > arr[mid])
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}
int main(){
    int arr1[6] = {1, 3, 5, 7, 9, 11};
    int arr2[7] = {13,15,17,19,45,57,89};
    int index1 = binarysearch(arr1, 9, 11);
    int index2 = binarysearch(arr2, 7, 45);
    cout << "Index of 11 in arr1 is " << index1 << endl;
    cout << "Index of 31 in arr2 is " << index2 << endl;
    return 0;
}