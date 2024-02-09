#include<iostream>
using namespace std;
 bool isPresent(int arr[][4], int target, int i, int j){
    cout<<"Enter the element to search"<<endl;
    cin>>target;
    for(int i =0;i<3;i++ ){
        for(int j=0; j<4;j++){
            if(arr[i][j]==target){
                return 1;
            }
        }
        
    }
    return 0;
 }

int main(){

    int arr[3][4];
    //input
    for(int i =0;i<3;i++ ){
        for(int j=0; j<4;j++){
            cin>>arr[i][j];
        }
    }
    int target;
    if(isPresent(arr,target,3,4)){
        cout<<"Element found"<<endl;
    }
    else{cout<<"Element not found"<<endl;}
    
    return 0;
}