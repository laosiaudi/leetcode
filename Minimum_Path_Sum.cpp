// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Minimum_Path_Sum.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2014-12-14 12:43:25
// MODIFIED: 2014-12-14 12:49:35
#include <iostream>
using namespace std;

class Solution {
    public:
        int minPathSum(vector<vector<int> > &grid) {
            for (int i = 0; i < grid.size(); i ++) {
                for (int j = 0; j < grid[i].size(); j ++) {
                    if (i == 0 && j == 0)
                        continue;
                    else {
                        if (i == 0)
                            grid[i][j] += grid[i][j - 1];
                        else if (j == 0)
                            grid[i][j] += grid[i - 1][j];
                        else {
                            grid[i][j] += (grid[i][j - 1] < grid[i - 1][j] ?grid[i][j - 1]:grid[i - 1][j]);
                        }
                    }
                }
            }
            int maxRow = grid.size() - 1;
            int maxCol = grid[maxRow].size() - 1;
            return grid[maxRow][maxCol];
        }
};
