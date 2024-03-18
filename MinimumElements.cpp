//also called minimum no. of coins question
Problem statement
You are given an array of ‘N’ distinct integers and an integer ‘X’ 
representing the target sum. 
You have to tell the minimum number of elements you have to take
 to reach the target sum ‘X’.

Note:
You have an infinite number of elements of each type.
For example
If N=3 and X=7 and array elements are [1,2,3]. 
Way 1 - You can take 4 elements  [2, 2, 2, 1] as 2 + 2 + 2 + 1 = 7.
Way 2 - You can take 3 elements  [3, 3, 1] as 3 + 3 + 1 = 7.
Here, you can see in Way 2 we have used 3 coins to reach the target sum of 7.
Hence the output is 3.

//code

int solve(vector<int> &num, int x, vector<int>&dp){

    if(x == 0)
        return 0;

    if(x < 0)
        return INT_MAx;

    if(dp[x] != -1){
        return dp[x];
    }

    int mini = INT_MAX;

    for(int i =0;i<num.size();i++){
        int ans = solve(num, x- num[i]);
        if(ans != INT_MAX){
            mini = min(mini, 1+ans);
        }
    }
    dp[x] = mini;
    return mini;

}

int MinimumElements(vector<int>nums, int x){
    vector<int> dp(x+1, -1);
    int ans = solve(num,x);
    if(ans == INT_MAX){
        return -1;
    }
    else{
        return ans;
    }
}