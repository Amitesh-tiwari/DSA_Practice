Given a binary matrix mat of size n * m, 
find out the maximum size square sub-matrix with all 1s.

Example 1:

Input: n = 2, m = 2
mat = {{1, 1}, 
       {1, 1}}
Output: 2
Explaination: The maximum size of the square
sub-matrix is 2. The matrix itself is the 
maximum sized sub-matrix in this case.

//code
class Solution{
public:
int solve(int i, int j, vector<vector<int>> mat, int &maxi,vector<vector<int>> &dp){
        if(i >= mat.size() || j >= mat[0].size()){
            
            return 0;
        }
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right = solve(i,j+1,mat,maxi,dp);
        int left = solve(i+1,j,mat,maxi,dp);
        int diagonal = solve(i+1,j+1,mat,maxi,dp);
        
        
        if(mat[i][j] == 1){
            dp[i][j] = 1 + min(right, min(left,diagonal));
            maxi = max( dp[i][j] ,maxi);
            return  dp[i][j] ;
            
        }
    }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        
        int maxi = 0;
        vector<vector<int>> dp(n,vector<int>(m,-1));
        solve(0,0,mat,maxi,dp);
        return maxi;
    }
};