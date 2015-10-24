/*********************************************************************************
*     File Name           :     Game_Of_Lift.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-24 14:46]
*     Last Modified       :     [2015-10-24 15:11]
*     Description         :
**********************************************************************************/
class Solution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            int m = board.size();
            if (m == 0)
                return;
            int n = board[0].size();
            vector<int>v(n, 0);
            vector<vector<int>>new_board(m, v);

            for (int i = 0; i < m; i ++) {
                for (int j = 0; j < n; j ++) {
                    int tmp = getState(i, j, board, m, n);
                    new_board[i][j] = tmp;
                }
            }
            board = new_board;

        }

        int getState(int i, int j, vector<vector<int>>& board, int m, int n) {
            int x[8] = {0, 0, 1, 1, 1, -1, -1, -1};
            int y[8] = {1, -1, 1, -1, 0, 1, -1, 0};

            int cnt = 0;
            for (int ii = 0; ii < 8; ii ++) {
                if (i + x[ii] < m && j + y[ii] < n && i + x[ii] >= 0 && j + y[ii] >= 0) {
                    if (board[i + x[ii]][j + y[ii]] == 1)
                        cnt ++;
                }
            }
            if (board[i][j] == 1) {
                if (cnt < 2)
                    return 0;
                else if (cnt == 2 || cnt == 3)
                    return 1;
                else
                    return 0;
            } else {
                if (cnt == 3)
                    return 1;
                else
                    return 0;
            }
        }
};

//state 0: dead - dead
//state 1: live - live
//state 2: live - dead
//state 3: dead - live
class BetterSolution {
    public:
        void gameOfLife(vector<vector<int>>& board) {
            int m = board.size();
            if (m == 0)
                return;
            int n = board[0].size();

            for (int i = 0; i < m; i ++) {
                for (int j = 0; j < n; j ++) {
                    board[i][j] = getState(i, j, board, m, n);
                }
            }

            for (int i = 0; i < m; i ++) {
                for (int j = 0; j < n; j ++)
                    board[i][j] %= 2;
            }

        }

        int getState(int i, int j, vector<vector<int>>& board, int m, int n) {
            int x[8] = {0, 0, 1, 1, 1, -1, -1, -1};
            int y[8] = {1, -1, 1, -1, 0, 1, -1, 0};

            int cnt = 0;
            for (int ii = 0; ii < 8; ii ++) {
                if (i + x[ii] < m && j + y[ii] < n && i + x[ii] >= 0 && j + y[ii] >= 0) {
                    if (board[i + x[ii]][j + y[ii]] == 1 || board[i + x[ii]][j + y[ii]] == 2)
                        cnt ++;
                }
            }
            if (board[i][j] == 1 || board[i][j] == 2) {
                if (cnt < 2)
                    return 2;
                else if (cnt == 2 || cnt == 3)
                    return 1;
                else
                    return 2;
            } else {
                if (cnt == 3)
                    return 3;
                else
                    return 0;
            }
        }
};

