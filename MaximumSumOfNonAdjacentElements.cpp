Problem statement
You are given an array/list of ‘N’ integers. 
You are supposed to return the maximum sum of the subsequence
 with the constraint that no two elements are adjacent in the 
 given array/list.

Note:
A subsequence of an array/list is obtained by deleting some number
 of elements (can be zero) from the array/list, leaving
  the remaining elements in their original order.

  //code

#include <bits/stdc++.h> 
int solve(vector<int>&nums, int n, vector<int>&dp){

    if(n < 0)
        return 0;

    if(n == 0)
        return nums[0];

    if(dp[n]   != -1){
        return dp[n];
    }

    int incl = solve(nums, n-2,dp) + nums[n];
    int ecl = solve(nums,n-1,dp);

    dp[n] =  max(incl, ecl);
    return dp[n];
}
int maximumNonAdjacentSum(vector<int> &nums){

    int n = nums.size();
   vector<int> dp(n, -1);
   int ans = solve(nums,n-1,dp);
   return ans;

}