Problem statement
You have been given a 9x9 2d integer matrix 'MAT' representing a Sudoku puzzle. 
The empty cells of the Sudoku are filled with zeros, and the rest of the cells are filled with integers from 1 to 9. 
Your task is to fill all the empty cells such that the final matrix represents a Sudoku solution.

Note:
A Sudoku solution must satisfy all the following conditions-
1. Each of the digits 1-9 must occur exactly once in each row.
2. Each of the digits 1-9 must occur exactly once in each column.
3. Each of the digits 1-9 must occur exactly once in each of the 9, 3x3 sub-grids of the grid.

//code

#include <bits/stdc++.h> 

bool isSafe(int row, int col,vector<vector<int>>& board,int val)
{

    for(int i=0;i<board.size();i++){
        if(board[row][i] == val){
            return false;
        }

        if(board[i][col] == val){
            return false;
        }

        if(board[3*(row/3) + i/3] [3*(col/3) + i%3] == val){
            return false;
        }
    }

    return true;

}

bool solve(vector<vector<int>>& board){

    int n = board[0].size();

    for(int row=0; row<n;row++){
        for(int col=0;col<n;col++){

            if(board[row][col] == 0){
                for(int val=1;val<=9;val++){
                    if(isSafe(row,col,board,val)){
                        board[row][col] = val;
                        bool further = solve(board);
                        if(further)
                            return true;
                        
                        else{
                            board[row][col] = 0;
                        }
                    }
                }
                return false;
            }

        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solve(sudoku);
}