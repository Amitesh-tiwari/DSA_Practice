#include<iostream>
using namespace std;

void print(int arr[], int n){
    cout<<"size of the array is"<<n<<endl;
    for(int i = 0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
bool linearSearch(int arr[],int size, int key){
    print(arr,size);
    if(size==0)
      return false;
    if(arr[0] == key)
      return 1;
    else{
        bool remainingPart = linearSearch(arr+1, size-1,key);
        return remainingPart;
    }
}


int main(){
    int arr[5] = {1,23,4,56,7};
    int size = 5;
    int key = 1;
    bool ans = linearSearch(arr,size,key);
    if(ans){
        cout<<"found"<<endl;
    }
    else{
        cout<<"Not found"<<endl;
    }
    return 0;
}