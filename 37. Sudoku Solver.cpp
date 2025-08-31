#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0);
    }

private:
    bool solve(vector<vector<char>>& board, int idx) {
        if (idx == 81) return true; 

        int i = idx / 9;
        int j = idx % 9;
        if (board[i][j] != '.')
            return solve(board, idx + 1);

        for (char c = '1'; c <= '9'; ++c) {
            if (isValid(board, i, j, c)) {
                board[i][j] = c;
                if (solve(board, idx + 1))
                    return true;
                board[i][j] = '.';
            }
        }
        return false;
    }

    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int k = 0; k < 9; ++k) {
            if (board[k][col] == c ||
                board[row][k] == c ||
                board[3 * (row / 3) + k / 3][3 * (col / 3) + k % 3] == c)
                return false;
        }
        return true;
    }
};