// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Search_A_2D_Matrix_II.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-09-02 20:09:24
// MODIFIED: 2015-09-02 20:23:56
#include <iostream>
using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int line = matrix.size();
            if (line == 0)
                return false;
            int top = line - 1;
            int bottom = 0;
            int mid = (top + bottom) / 2;
            while (top >= bottom && matrix[mid][0] <= target) {
                if (matrix[mid][0] == target)
                    return true;
                bottom = mid + 1;
                mid = (bottom + top) / 2;
            }
            if (line != 1 && matrix[mid][0] > target)
                mid = mid - 1;
            int i = mid;
            for (; i >= 0; i --) {
                int size = matrix[i].size();
                top = size - 1;
                bottom = 0;
                while (top >= bottom) {
                    int tmp = (top + bottom) / 2;
                    if (matrix[i][tmp] > target)
                        top = tmp - 1;
                    else if (matrix[i][tmp] < target)
                        bottom = tmp + 1;
                    else
                        return true;
                }
            }
            return false;
        }
};

