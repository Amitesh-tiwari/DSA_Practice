#include<iostream>
using namespace std;

int firstOccurence(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while(start <= end){
        if(arr[mid] == key){
            ans = mid;
            end = mid-1;
        }
        if(key>arr[mid]){
            end = mid -1;
        }
        if(key<arr[mid]){
            start = mid +1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}

int lastOccurence(int arr[], int size, int key){
    int start = 0;
    int end = size-1;
    int mid = start + (end - start) / 2;
    int ans = -1;
    while(start <= end){
        if(arr[mid] == key){
            ans = mid;
            start = mid+1;
        }
        if(key>arr[mid]){
            end = mid -1;
        }
        if(key<arr[mid]){
            start = mid +1;
        }
        mid = start + (end - start) / 2;
    }
    return ans;
}


int main(){
    
    int arr[12] = {1,2,3,3,3,3,3,3,3,3,3,3};
    int index1 = firstOccurence(arr,12,3);
    int index2 = lastOccurence(arr,12,3);
    cout<<"firstOccurence of 3 is : "<<index1<<endl;
    cout<<"lastOccurence of 3 is : "<<index2<<endl;
    return 0;
}