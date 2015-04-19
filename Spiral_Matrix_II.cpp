// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Spiral_Matrix_II.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-12 14:18:35
// MODIFIED: 2015-04-12 14:25:30
#include <iostream>
using namespace std;
 
class Solution {
    public:
        vector<vector<int> > generateMatrix(int n) {
            vector<vector<int> >v;
            if (n == 0)
                return v;
            int matrix[n][n];
            int k = 1;
            int top = 0;
            int left = 0;
            int right = n - 1;
            int bottom = n - 1;

            while (left < right && top < bottom) {
                for (int i = left; i < right; i ++)
                    matrix[top][i] = k ++;
                for (int i = top; i < bottom; i ++)
                    matrix[i][right] = k ++;
                for (int i = right; i > left; i --)
                    matrix[bottom][i] = k ++;
                for (int i = bottom; i > top; i --)
                    matrix[i][left] = k ++;
                top ++;
                right --;
                left ++;
                bottom --;
            }
            if (n % 2 != 0)
                matrix[n/2][n/2] = k;
            for (int i = 0; i < n; i ++) {
                vector<int>temp;
                for (int j = 0; j < n; j ++)
                    temp.push_back(matrix[i][j]);
                v.push_back(temp);
            }
            return v;
        }
};
