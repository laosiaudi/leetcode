/*********************************************************************************
*     File Name           :     Single_Number_III.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-24 14:25]
*     Last Modified       :     [2015-10-24 14:31]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        vector<int> singleNumber(vector<int>& nums) {
            vector<int>result;
            if (nums.size() == 0)
                return result;
            int XOR = nums[0];
            for (int i = 1; i < nums.size(); i ++)
                XOR ^= nums[i];

            int posOfOne = 1;
            while ((posOfOne & XOR) != posOfOne)
                posOfOne = posOfOne << 1;

            int x = 0;
            for (int i = 0;i < nums.size(); i ++) {
                if (nums[i] & posOfOne)
                    x = x ^ nums[i];
            }

            int y = x ^ XOR;
            result.push_back(x);
            result.push_back(y);
            return result;
        }
};


