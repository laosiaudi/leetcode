/*********************************************************************************
*     File Name           :     Majority_Element_II.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-24 16:02]
*     Last Modified       :     [2015-09-24 16:07]
*     Description         :
**********************************************************************************/

 //Moore Voting https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm

class Solution {
    public:
        vector<int> majorityElement(vector<int>& nums) {
            int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0;

            vector<int>v;
            int size = nums.size();
            for (int i = 0; i < size; i ++) {
                if (nums[i] == num1)
                    cnt1 ++;
                else if (nums[i] == num2)
                    cnt2 ++;
                else if (cnt1 == 0) {
                    num1 = nums[i];
                    cnt1 = 1;
                } else if (cnt2 == 0) {
                    num2 = nums[i];
                    cnt2 = 1;
                } else {
                    cnt1 --;
                    cnt2 --;
                }
            }

            cnt1 = 0, cnt2 = 0;
            for (int i = 0; i < size; i ++) {
                if (nums[i] == num1)
                    cnt1 ++;
                else if (nums[i] == num2)
                    cnt2 ++;
            }

            if (cnt1 > size / 3)
                v.push_back(num1);
            if (cnt2 > size / 3)
                v.push_back(num2);
            return v;
        }
};


