/*********************************************************************************
*     File Name           :     Range_Sum_Query_Immutable.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-11-11 11:00]
*     Last Modified       :     [2015-11-11 11:04]
*     Description         :
**********************************************************************************/


class NumArray {
public:
    int *sum;
    NumArray(vector<int> &nums) {
        if (nums.size() == 0)
            sum = NULL;
        else {
            sum = new int[nums.size()];
            sum[0] = nums[0];
            for (int i = 1;i < nums.size(); i ++)
                sum[i] = sum[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        return i == 0 ? sum[j] : sum[j] - sum[i - 1];
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
