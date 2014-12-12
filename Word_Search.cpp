// C/C++ File
// AUTHOR:   laosi
// FILE:     Word_Search.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-12 22:52:45
// MODIFIED: 2014-12-12 23:20:23
// use DFS, if use BFS, will exceed the limit of stack space
#include <iostream>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
            int m = board.size();
            int n = board[0].size();
            vector<bool> mark(m*n, false);
            for (int i = 0; i < m; ++i){
                        for (int j = 0; j < n; ++j) {
                                        mark.clear();
                                        mark.resize(m*n, false);
                                        if (worker(board, mark, word, i, j, 0))
                                            return true;
                                    }
                                }
                    return false;
                        }
     
     bool worker(vector<vector<char> > &board, vector<bool> &mark, string &word, int x, int y, int k) {
             int m = board.size();
             int n = board[0].size();
             if (k == word.size())
                 return true;
             else if (x < 0 || x >= m || y < 0 || y >= n || mark[x*n + y] == true || word[k] != board[x][y])
                 return false;
             else {
                         mark[x*n+y] = true;
                         if (worker(board, mark, word, x+1, y, k+1))
                             return true;
                         if (worker(board, mark, word, x-1, y, k+1))
                             return true;
                         if (worker(board, mark, word, x, y+1, k+1))
                             return true;
                         if (worker(board, mark, word, x, y-1, k+1))
                             return true;
                         mark[x*n+y] = false;
                         return false;
                     }
             
         }
};
