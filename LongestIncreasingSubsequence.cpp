Problem statement
For a given array with N elements, you need to find the length of 
the longest subsequence from the array such that all the elements
 of the subsequence are sorted in strictly increasing order.

Strictly Increasing Sequence is when each term in the sequence
 is larger than the preceding term.

For example:
[1, 2, 3, 4] is a strictly increasing array, while [2, 1, 4, 3]
 is not.

 //code

int longestIncreasingSubsequence(int arr[], int n){
    int dp[n];
    dp[0] = 1;

    int ans = 1;

    for(int i =1;i<n;i++){
        int maxVal =0;
        for(int j=0;j<i;j++){
            if(arr[i] > arr[j]){
                maxVal = max(maxVal, dp[j]);
            }
        }
        dp[i] = maxVal + 1;
        ans = max(ans,dp[i]);
    }

    return ans;
}

//optimiszed approach Binary Search + DP

#include<algorithm>

int longestIncreasingSubsequence(int arr[], int n)
{
    int dp[n];
    
    int ans = 0;

    for(int i=0;i<n;i++){

        int position = lower_bound(dp,dp + ans, arr[i]) - dp;
        dp[position] = arr[i];

        if(position == ans){
            ans++;
        }
      
    }

    return ans;

}


