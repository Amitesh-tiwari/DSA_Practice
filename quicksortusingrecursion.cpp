#include<iostream>
using namespace std;
int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int cnt = 0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<=pivot){
            cnt++;
        }
    }
    int pivotIndex = s+cnt;
    swap(arr[pivotIndex],arr[s]);
    int i=s,j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotIndex;
}

void quick(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int p = partition(arr,s,e);
    quick(arr,s,p-1);
    quick(arr,p+1,e);
}
int main(){
    int arr[5] = {1,34,56,76,54};
    int n=5;
    quick(arr,0,n-1);

    for(int i =0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    return 0;
}
