/*********************************************************************************
*     File Name           :     Range_Sum_Query_Immutable.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-11-11 11:00]
*     Last Modified       :     [2015-11-13 15:46]
*     Description         :
**********************************************************************************/


class NumMatrix {
public:
    vector<vector<int>>sum;
    NumMatrix(vector<vector<int>> &nums) {
        if (nums.size() == 0)
            ;
        else {
            sum.resize(nums.size());
            for (int i = 0;i < nums.size(); i ++)
                sum[i].resize(nums[i].size(),0);
            sum[0][0] = nums[0][0];
            for (int i = 1; i < nums[0].size(); i ++)
                sum[0][i] = sum[0][i - 1] + nums[0][i];

            for (int i = 1; i < nums.size(); i ++)
                sum[i][0] = sum[i - 1][0] + nums[i][0];

            for (int i = 1;i < nums.size(); i ++) {
                for (int j = 1; j < nums[0].size(); j ++)
                    sum[i][j] = nums[i][j] + sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        int left = col1 > 0 ? sum[row2][col1 - 1] : 0;
        int right = row1 > 0 ? sum[row1 - 1][col2] : 0;
        int last = (row1 > 0 && col1 > 0) ? sum[row1 - 1][col1 - 1] : 0;
        return (sum[row2][col2] - left - right + last);

    }
};

// Your NumMatrix object will be instantiated and called as such:
// // NumMatrix numMatrix(matrix);
// // numMatrix.sumRegion(0, 1, 2, 3);
// // numMatrix.sumRegion(1, 2, 3, 4);
