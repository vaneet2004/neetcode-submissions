class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
        // check row
        for(int j = 0; j < 9; j++) {
            if(board[row][j] == dig) {
                return false;
            }
        }

        // check column
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == dig) {
                return false;
            }
        }

        // check 3x3 box
        int srow = (row / 3) * 3;
        int scol = (col / 3) * 3;

        for(int i = srow; i < srow + 3; i++) {
            for(int j = scol; j < scol + 3; j++) {
                if(board[i][j] == dig) {
                    return false;
                }
            }
        }

        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] != '.') {
                    char curr = board[i][j];
                    
                    // remove temporarily
                    board[i][j] = '.';

                    // check validity
                    if(!isSafe(board, i, j, curr)) {
                        return false;
                    }

                    // restore
                    board[i][j] = curr;
                }
            }
        }

        return true;
    }
};