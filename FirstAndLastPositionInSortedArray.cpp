Problem statement
You have been given a sorted array/list 'arr' consisting of ‘n’ elements. 
You are also given an integer ‘k’.

Now, your task is to find the first and last occurrence of ‘k’ in 'arr'.

Note :
1. If ‘k’ is not present in the array, then the first and the last occurrence will be -1. 
2. 'arr' may contain duplicate elements.

//code

pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)

{
    int first = -1;
    int last = -1;

    int start = 0;
    int end = n-1;

    while(start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == k){
            first = mid;
            end = mid-1;
        }
        else if(arr[mid] < k){
            start = mid +1;
        }
        else{
            end = mid -1;
        }
    
    }

     start = 0;
     end = n-1;
    
    while(start <= end){

        int mid = start + (end - start) / 2;

        if(arr[mid] == k){
            last = mid;
            start = mid+1;
        }
        else if(arr[mid] < k){
            start = mid +1;
        }
        else{
            end = mid -1;
        }
        
    }

    return make_pair(first,last);

}