#include<iostream>
using namespace std;
void print(int arr[], int s, int e){
    for(int i =s;i<=e;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}

bool  binarySearch(int *arr, int s, int e, int key){
    print(arr,s,e);
    if(s>e)
       return false;
    int mid = s+(e-s)/2;

    if(arr[mid] == key)
       return true;

    if(arr[mid]<key)
        return binarySearch(arr,mid+1,e,key);
    else{
        return binarySearch(arr,s,mid-1,key);
    }

}
int main(){
    int arr[6] = {1,2,4,5,7,10};
    int size = 5;
    int key = 1;
    cout<<"present or not"<<binarySearch(arr,0,5,key);
    return 0;
}