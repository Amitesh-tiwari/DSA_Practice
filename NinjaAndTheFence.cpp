Problem statement
Ninja has given a fence, and he gave a task to paint this fence. 
The fence has 'N' posts, and Ninja has 'K' colors. 
Ninja wants to paint the fence so that not more than two 
adjacent posts have the same color.

Ninja wonders how many ways are there to do the above task,
 so he asked for your help.
Input: 'N' = 3, 'K' = 2
Output: 6

Say we have the colors with the numbers 1 and 0. 
We can paint the fence with 3 posts with the following different combinations.

110
001
101
100
010
011

//code

#include <bits/stdc++.h> 
#define MOD 1000000007

int add(int a, int b){

    return (a%MOD + b%MOD)%MOD;

}

int mul(int a, int b){

    return ((a%MOD)*1LL * (b%MOD))%MOD;

}

int solve(int n, int k, vector<int> &dp){
    if( n == 1)
        return k;

    if(n == 2)
        return add(k , mul(k, k-1));

    if(dp[n] != -1){
        return dp[n];
    }
    
    dp[n] = add(mul(solve(n-2,k,dp) , k-1), mul(solve(n-1,k,dp), k-1));
    return dp[n];
}

int numberOfWays(int n, int k) {
    vector<int> dp(n+1, -1);
    return solve(n,k,dp);
}
