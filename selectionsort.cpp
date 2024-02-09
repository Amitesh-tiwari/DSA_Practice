#include<iostream>
using namespace std;

void print(int arr[], int n){
    for(int i = 0;i<n-1;i++){
        cout<<arr[i]; 
}
}

int selectionSort(int arr[], int n)
{   
    for(int i =0;i<n-1;i++){
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }
}
int main(){
    int arr1[5] = {4,6,91,56,7};
    selectionSort(arr1,5);
    print(arr1,5);
    return 0;
}