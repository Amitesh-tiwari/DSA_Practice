#include<iostream>
#include<queue>
using namespace std;

class Heap{
    public:
        int arr[100];
        int size;

        Heap(){
            arr[0] = -1;
            size = 0;
        }

    void insert(int val){

        size = size+1;
        int index = size;
        arr[index] = val;       


        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else{
                return;
            }
            
        }
    }

    void print(){
        for(int i =1;i<=size;i++){
            cout<<arr[i]<<" ";
        }cout<<endl;
    }

    void deleteFromHeap(){
        if(size == 0){
            cout<<"Nothing to delete"<<endl;
            return ;
        }
        arr[1] = arr[size];
        size--;

        int i =1;
        while(i<size){
            int leftPart = 2*i;
            int rightPart = 2*i+1;

            if(leftPart < size && arr[i] < arr[leftPart]){
                swap(arr[i], arr[leftPart]);
                i = leftPart;
            }
            else if(rightPart < size && arr[i] < arr[rightPart]){
                swap(arr[i], arr[rightPart]);
                i = rightPart;
            }
            else{
                return;
            }
        }
    }
};

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i+1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[], int n){

    int size = n;
    while(size>1){
        swap(arr[size],arr[1]);
    }
    heapify(arr,size,1);
}

int main(){

    Heap h;
    h.insert(10);
    h.insert(40);
    h.insert(30);
    h.insert(90);
    h.insert(60);
    h.insert(70);
   // h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i =n/2;i>0;i--){
        heapify(arr,n,i);
    }
    
    cout<<"Printing the array now"<<endl;
    for(int i =0;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    heapSort(arr,n);

    cout<<"Printing the Sorted array now"<<endl;
    for(int i =1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

    cout<<"Using Priority Queue here"<<endl;
    //maxheap
    priority_queue<int> pq;
    pq.push(2);
    pq.push(3);
    pq.push(4);
    pq.push(5);

    cout<<"Queue top is "<<pq.top() << endl;

    //minheap
    priority_queue<int,vector<int>,greater<int> > minheap;
    minheap.push(2);
    minheap.push(3);
    minheap.push(4);
    minheap.push(5);

    cout<<"top of the queue is "<<minheap.top() <<endl;

    return 0;
}