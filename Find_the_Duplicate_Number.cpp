/*********************************************************************************
*     File Name           :     Find_the_Duplicate_Number.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-30 14:52]
*     Last Modified       :     [2015-09-30 15:45]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        int findDuplicate(vector<int>& nums) {
            int size = nums.size();

            int low = 1;
            int high = size - 1;
            while (low <= high) {
                int mid = (low + high) / 2;
                int cnt = count(nums, mid);
                if (cnt > mid) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return low;
        }

        int count(vector<int> &nums, int limit) {
            int cnt = 0;
            for (int i = 0; i < nums.size(); i ++) {
                if (nums[i] <= limit) {
                    cnt ++;
                }
            }
            return cnt;
        }
};


