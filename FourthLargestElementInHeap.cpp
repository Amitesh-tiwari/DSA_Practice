You are given an array consisting of 'N' integers. 
You have to find the fourth largest element present in the array.

If there is no such number present in the array, 
then print the minimum value of an integer which is -2147483648.


#include<queue>
#include<climits>

int getFourthLargest(int arr[], int n)
{
    if(n<4){
        return INT_MIN;
    }

    priority_queue<int,vector<int>,greater<int> > pq;
    for(int i=0;i<n;i++){
        pq.push(arr[i]);
        if(pq.size() >4){
            pq.pop();
        }
    }
    return pq.top();
}