There is a pizza with 3n slices of varying size, 
you and your friends will take slices of pizza as follows:

You will pick any pizza slice.
Your friend Alice will pick the next slice in the anti-clockwise 
direction of your pick.
Your friend Bob will pick the next slice in the 
clockwise direction of your pick.
Repeat until there are no more slices of pizzas.
Given an integer array slices that represent the sizes of the pizza slices 
in a clockwise direction, return the maximum possible sum of slice sizes that
you can pick.

Example 1:


Input: slices = [1,2,3,4,5,6]
Output: 10
Explanation: Pick pizza slice of size 4, 
Alice and Bob will pick slices with size 3 and 5 respectively. 
Then Pick slices with size 6, finally Alice and Bob will pick 
slice of size 2 and 1 respectively. 
Total = 4 + 6.

//code
class Solution {
public:

    int solve(int index, int endIndex ,vector<int>& slices, int n,vector<vector<int>>& dp ){
        if(n == 0 || index > endIndex){
            return 0;
        }

        if(dp[index][n] != -1){
            return dp[index][n];
        }

        int take = slices[index] + solve(index + 2,endIndex,slices,n-1,dp);
        int notTake = 0 + solve(index + 1, endIndex, slices , n,dp);
        return dp[index][n] = max(take, notTake);
    }
    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k, vector<int> (k,-1));
        int case1 = solve(0,k-2,slices,k/3,dp1);
        vector<vector<int>> dp2(k, vector<int> (k,-1));
        int case2 = solve(1,k-1,slices,k/3,dp2);

        return max(case1, case2);
        
    }
};