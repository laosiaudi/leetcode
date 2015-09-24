/*********************************************************************************
*     File Name           :     Move_Zeroes.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-24 15:11]
*     Last Modified       :     [2015-09-24 15:18]
*     Description         :
**********************************************************************************/
class Solution {
    public:
        void moveZeroes(vector<int>& nums) {
            int size = nums.size();
            int start = 0;
            int num = 0;
            int i;
            for (i = 0; i < size; i ++) {
                if (nums[i] != 0)
                    nums[i - num] = nums[i];
                else
                    num ++;
            }

            for (int j = i - num; j < size; j ++)
                nums[j] = 0;
        }
};


