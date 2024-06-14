Problem statement
You have been given a 9 X 9 2D matrix 'MATRIX' 
with some cells filled with digits(1 - 9), and 
some empty cells (denoted by 0).

You need to find whether there exists a way to fill all the 
empty cells with some digit(1 - 9) such that the final matrix 
is a valid Sudoku solution.

A Sudoku solution must satisfy all the following conditions-

1. Each of the digits 1 - 9 must occur exactly once in each row.
2. Each of the digits 1 - 9 must occur exactly once in each column.
3. Each of the digits 1 - 9 must occur exactly once in each
of the 9, 3 x 3 sub-matrices of the matrix.
Note
1. There will always be a cell in the matrix which is empty.
2. The given initial matrix will always be consistent 
according to the rules mentioned in the problem statement.

//code
bool isItSudoku(int matrix[9][9]) {
    // Check if a digit is already present in the same row
    unordered_map<int, bool> row[9];
    // Check if a digit is already present in the same column
    unordered_map<int, bool> col[9];
    // Check if a digit is already present in the same 3x3 sub-matrix
    unordered_map<int, bool> subMatrix[3][3];

    // Initialize the unordered maps
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int digit = matrix[i][j];
            if (digit != 0) {
                row[i][digit] = true;
                col[j][digit] = true;
                subMatrix[i / 3][j / 3][digit] = true;
            }
        }
    }

    // Perform backtracking to fill the empty cells
    return solveSudoku(matrix, row, col, subMatrix, 0, 0);
}

bool solveSudoku(int matrix[9][9], unordered_map<int, bool> row[9], unordered_map<int, bool> col[9], unordered_map<int, bool> subMatrix[3][3], int i, int j) {
    // Base case: If all cells have been filled, return true
    if (i == 9) {
        return true;
    }

    // If the current cell is not empty, move to the next cell
    if (matrix[i][j] != 0) {
        if (j == 8) {
            return solveSudoku(matrix, row, col, subMatrix, i + 1, 0);
        } else {
            return solveSudoku(matrix, row, col, subMatrix, i, j + 1);
        }
    }

    // Try all possible digits from 1 to 9
    for (int digit = 1; digit <= 9; digit++) {
        // Check if the digit is not already present in the same row, column, or sub-matrix
        if (!row[i][digit] && !col[j][digit] && !subMatrix[i / 3][j / 3][digit]) {
            // Place the digit in the current cell
            matrix[i][j] = digit;
            row[i][digit] = true;
            col[j][digit] = true;
            subMatrix[i / 3][j / 3][digit] = true;

            // Move to the next cell
            if (j == 8) {
                if (solveSudoku(matrix, row, col, subMatrix, i + 1, 0)) {
                    return true;
                }
            } else {
                if (solveSudoku(matrix, row, col, subMatrix, i, j + 1)) {
                    return true;
                }
            }

            // If the current digit does not lead to a valid solution, backtrack
            matrix[i][j] = 0;
            row[i][digit] = false;
            col[j][digit] = false;
            subMatrix[i / 3][j / 3][digit] = false;
        }
    }

    // If no digit leads to a valid solution, return false
    return false;
}