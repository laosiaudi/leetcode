// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Rotate_Image.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-19 10:54:05
// MODIFIED: 2015-04-19 11:33:42
#include <iostream>
using namespace std;

class Solution {
    public:
        void rotate(vector<vector<int> > &matrix) {
            int line = matrix.size();
            if (line <= 1)
                return ;
            int times = line / 2;
            for (int i = 0; i < times; i ++) {
                for (int j = i; j < n - i - 1;j ++) {
                    int start = matrix[i][j];
                    int temp_1 = matrix[j][n - 1 - i];
                    matrix[j][n - 1 - i] = start;
                    int temp_2 = matrix[n - 1 - i][n - 1 - j];
                    matrix[n - 1 - i][n - 1 -  j] = temp_1;
                    int temp_3 = matrix[n - 1 - j][i];
                    matrix[n - 1 - j][i] = temp_2;
                    matrix[i][j] = temp_3;
                }
            }
        }
};
