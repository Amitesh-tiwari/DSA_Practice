#include<iostream>
using namespace std;


void printArray(int arr[],int n){
    for(int i = 0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int reverse(int arr[], int n){
    int start = 0;
    int end = n-1;
    while(start<=end){
        swap(arr[start],arr[end]);
        start++;
        end--;
        //cout<<endl;
    }
    cout<<endl;
}
int main(){
    
    int arr[5] = {3,45,67,78,8};
    int arr1[6] = {31,451,675,784,8, 565};

    reverse(arr,5);
    reverse(arr1,6);

    printArray(arr,5);
    printArray(arr1,6);
    return 0;
}