Problem statement
You are given an integer 'N'. For a given 'N' x 'N' chessboard, 
find a way to place 'N' queens such that no queen can attack any other queen on the chessboard.

A queen can be killed when it lies in the same row, or same column, 
or the same diagonal of any of the other queens. You have to print all such configurations.

//code

bool isSafe(int row, int col,vector<vector<int>>&board, int n){

    int i;
    int j;

    for(i=0;i<col;i++){
        if(board[row][i]){
            return false;
        }
    }

    for(i=row,j=col; i>=0 && j>=0; i--,j--){
        if(board[i][j]){
            return false;
        }
    }

    for(i=row,j=col;j>=0 && i<n;i++,j--){
        if(board[i][j]){
            return false;
        }

    }

    return true;
}

void addSolution(vector<vector<int>>&board,vector<vector<int> >&ans,int n){

    vector<int> temp;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            temp.push_back(board[i][j]);
        }
    }
    ans.push_back(temp);

}



void solve(int col,vector<vector<int> > &ans,vector<vector<int>>&board,int n){

    if(col >= n){
        addSolution(board,ans,n);
        return;
    }

    for(int row =0;row<n;row++){
        if(isSafe(row,col,board,n)){

            board[row][col] = 1;
            solve(col+1,ans,board,n);
            board[row][col] = 0;
        }
        
 
    }
}



vector<vector<int>> solveNQueens(int n) {
    
    vector<vector<int> > board(n, vector<int>(n,0));
    vector<vector<int> > ans;

    solve(0,ans,board,n);
    return ans;
}