#include <iostream>
#include <vector>

using namespace std;


int MAX_ROWS = 9;
int MAX_COLS = 9;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // rule1: Each row must contain the digits 1-9 without repetition
        // rule2: Each column must contain the digits 1-9 wihout repetition
        // rule3: Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition
        
        vector<vector<int>> col_check(9, vector<int>(9, 0));
        vector<vector<int>> sub_check(9, vector<int>(9, 0));
        for (int row_idx = 0 ; row_idx < MAX_ROWS ; row_idx++){
            vector<int> row_check (9,0);
            for (int col_idx = 0 ; col_idx < MAX_COLS ; col_idx++){
                char c = board[row_idx][col_idx];
                //cout << c << "," ;
                if (c == '.'){
                    continue;
                }
                int num = c - '1';

                if ( row_check[num] != 0 ){
                    return false;
                }else{
                    row_check[num] = 1;
                };

                if ( col_check[col_idx][num] != 0 ){
                    return false;
                }else{
                    col_check[col_idx][num] = 1;
                };

                int sub_idx = (int)(row_idx / 3) * 3 + (int) (col_idx / 3);
                if ( sub_check[sub_idx][num] != 0 ){
                    return false;
                }else{
                    sub_check[sub_idx][num] = 1;
                };

            };
            //cout << "\n";
        };

        return true;
    }
};


int main(){
    Solution sol;
    vector<vector<char>> board;
    bool res;

    board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    res = sol.isValidSudoku(board);
    cout << res << endl;

    board = {
        {'5', '3', '.', '3', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    res = sol.isValidSudoku(board);
    cout << "1. First row contains two 3s - error" << endl;
    cout << res << endl;

};

