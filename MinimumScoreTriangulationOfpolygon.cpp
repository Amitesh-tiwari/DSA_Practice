You have a convex n-sided polygon where each vertex has an integer value. 
You are given an integer array values where values[i] 
is the value of the ith vertex (i.e., clockwise order).

You will triangulate the polygon into n - 2 triangles.
For each triangle, the value of that triangle is
the product of the values of its vertices, 
and the total score of the triangulation is
the sum of these values over all n - 2 triangles 
in the triangulation.

Return the smallest possible total score 
that you can achieve with some triangulation of the polygon.
//code

class Solution {
public:

    int solve(vector<int>& values, int i, int j,vector<vector<int>>&dp){
        if( i+1 == j){
            return 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int ans = INT_MAX;
        for(int k = i+1; k<j; k++){
            ans = min(ans, values[i] * values[j] * values[k] + solve(values,i,k,dp)
            + solve(values,k,j,dp));
        } 
        dp[i][j] = ans;
        return dp[i][j];
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> dp(n, vector<int>(n , -1));
        return solve(values,0,n-1,dp);
    }
};