// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Valid_Sudoku.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-26 13:48:55
// MODIFIED: 2015-04-26 14:11:59
#include <iostream>
using namespace std;

class Solution {
    public:
    bool isValidSudoku(vector<vector<char> > &board) {
        if (board.size() < 9 || board[0].size() < 9)
            return false;

        //check row
        for (int i = 0; i < 9;i ++) {
            vector<bool>checked(9, false);
            for (int j = 0; j < 9; j ++) {
                if ('1' <= board[i][j] && board[i][j] <= '9') {
                   int num = board[i][j] - '1' + 1;
                   if (checked[num - 1])
                       return false;
                   else
                       checked[num - 1] = true;
                }
            }
        }
        //check col
        for (int i = 0; i < 9;i ++) {
            vector<bool>checked(9, false);
            for (int j = 0; j < 9; j ++) {
                if ('1' <= board[j][i] && board[j][i] <= '9') {
                   int num = board[j][i] - '1' + 1;
                   if (checked[num - 1])
                       return false;
                   else
                       checked[num - 1] = true;
                }
            }
        }
        //check sub-grid
        for (int i = 0; i < 9;i ++) {
            vector<bool>checked(9, false);
            for (int j = 0; j < 9; j ++) {
                if ('1' <= board[i / 3 * 3+ j / 3][i % 3 * 3+ j % 3] && board[i / 3 * 3+ j/3][i % 3 * 3 + j % 3] <= '9') {
                   int num = board[i / 3 * 3 + j / 3][i % 3 * 3 + j % 3] - '1' + 1;
                   if (checked[num - 1])
                       return false;
                   else
                       checked[num - 1] = true;
                }
            }
        }
        return true;
    }
};
