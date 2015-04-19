// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Set_Matrix_Zeroes.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-18 16:12:42
// MODIFIED: 2015-04-18 16:40:10
#include <iostream>
using namespace std;

//O(m+n) space
class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
           int line = matrix.size();
           if (line == 0)
               return ;
           int col = matrix[0].size();

           vector<bool>row(line);
           vector<bool>column(col);

           for (int i = 0; i < line; i ++) {
               for (int j = 0; j < col; j ++) {
                    if (matrix[i][j] == 0) {
                        row[i] = true;
                        column[j] = true;
                    }
               }
           }

           for (int i = 0; i < line; i ++) {
               for (int j = 0; j < col; j ++) {
                    if (row[i] || column[j])
                        matrix[i][j] = 0;
               }
           }
        }
};

//O(1) space
//use first row and col to record
class Solution {
    public:
        void setZeroes(vector<vector<int> > &matrix) {
           int line = matrix.size();
           if (line == 0)
               return ;
           int col = matrix[0].size();

           bool firstRowZero = false;
           bool firstColZero = false;

           for (int i = 0 ;i < col; i ++) {
                if (matrix[0][i] == 0) {
                    firstRowZero = true;
                    break;
                }
           }

           for (int i = 0 ;i < line; i ++) {
                if (matrix[i][0] == 0) {
                    firstColZero = true;
                    break;
                }
           }

           for (int i = 0; i < line; i ++) {
               for (int j = 0; j < col; j ++) {
                    if (matrix[i][j] == 0) {
                        matrix[0][j] = 0;
                        matrix[i][0] = 0;
                    }
               }
           }

           for (int i = 1; i < line; i ++) {
               for (int j = 1; j < col; j ++) {
                   if (matrix[i][0] == 0)
                       matrix[i][j] = 0;
                   if (matrix[0][j] == 0)
                       matrix[i][j] = 0;
               }
           }

           if (firstRowZero) {
               for (int i = 0; i < col; i ++)
                   matrix[0][i] = 0;
           }

           if (firstColZero) {
               for (int i = 0; i < line; i ++)
                   matrix[i][0] = 0;
           }
        }
};
