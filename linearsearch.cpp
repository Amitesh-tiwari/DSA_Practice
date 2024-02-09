#include<iostream>
using namespace std;

bool search(int arr[],int size, int key){

    for(int i = 0; i<size; i++){
        if(arr[i] == key){
            return 1;
        }
        return 0;
    }

}
int main(){
    int key,size;
    int arr[10] = {1,3,54,5,56,4,32,213,455,7};
    cout<<"ENter the element to search"<<endl;
    cin>>key;
    bool found = search(arr,10,key);
    if(found){
        cout<<"key is present"<<endl;
    }
    else{ cout<<"key is absent"<<endl;}



    return 0;
}