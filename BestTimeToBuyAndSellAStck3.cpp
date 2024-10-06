You are given an array/list say ‘ARR’ of size ‘N’. We call
 pair (i, j) a Reverse Pair when i < j and 'ARR[i]' > 2 *
'ARR[j]'.

Your task is to find the number of Reverse Pairs present
in given 'ARR'.

For example :

For the array [50, 21, 9], if we follow 1-based indexing,
 the Reverse Pairs are (1, 2), (1, 3) and (2, 3). Thus, 
 the total count i.e. the answer becomes 3.
Note :

A single index of the pair (i, j) can be used multiple
times.

//code
#include <bits/stdc++.h> 
int reversePairs(vector<int> &arr, int n){
    int count = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > 2 * arr[j]){
                count++;
            }
        }
    }
    return count;
}