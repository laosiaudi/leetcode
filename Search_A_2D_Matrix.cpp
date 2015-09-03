// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Search_A_2D_Matrix.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-18 16:44:58
// MODIFIED: 2015-08-01 23:16:40
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        bool searchMatrix(vector<vector<int> > &matrix, int target) {
            int line = matrix.size();
            if (line == 0)
                return false;
            int col = matrix[0].size();
            if (target < matrix[0][0])
                return false;
            int start = 0;
            int end = line - 1;
            int mid = (start + end)/2;
            while (start <= end) {
                mid = (start + end)/2;
                if (matrix[mid][0] == target)
                    return true;
                else if (target < matrix[mid][0])
                    end = mid - 1;
                else
                    start = mid + 1;
            }
            start = end;

            int rowStart = 0;
            int rowEnd = col - 1;
            int rowMid = (rowStart + rowEnd)/2;
            if (matrix[start][rowMid] == target)
                return true;
            while (rowStart <= rowEnd) {
                rowMid = (rowStart + rowEnd)/2;
                if (matrix[start][rowMid] == target)
                    return true;
                else if (target < matrix[start][rowMid])
                    rowEnd = rowMid - 1;
                else
                    rowStart = rowMid + 1;
            }

            return false;
        }
};

int main() {
    vector<vector<int> >v;
    vector<int>vv;
    vv.push_back(1);
    vv.push_back(1);
    v.push_back(vv);

    Solution s;
    s.searchMatrix(v, 2);
    return 0;
}
