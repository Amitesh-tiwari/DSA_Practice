You are given an array of integers 'ARR' of size 'N' and another integer 'K'.
Your task is to find and return 'K'th smallest value present in the array.
Note: All the elements in the array are distinct.



int kthSmallest(int n,int k,vector<int> Arr)
{
    priority_queue<int> maxHeap;
    int i =0;
    for(;i<k;i++){
        maxHeap.push(Arr[i]);
    }

    for(;i<n;i++){
        if(Arr[i] < maxHeap.top()){
            maxHeap.pop();
            maxHeap.push(Arr[i]);
        }
    }
    return maxHeap.top();
}