// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Minimum_Size_Subarray_Sum.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-13 21:53:16
// MODIFIED: 2015-05-14 00:03:30
#include <iostream>
using namespace std;

class Solution {
    public:
        int minSubArrayLen(int s, vector<int> &nums) {
            int len = nums.size();
            if (len == 0)
                return 0;

            int start = 0, end = 0;
            int sum = 0;
            int res = len + 1;
            for (; end < len; end ++) {
               sum += nums[end];
               while (sum >= s) {
                   res = res < (end - start + 1) ? res : (end - start + 1);
                   sum -= nums[start ++];
               }

            }
            if (res == len + 1)
                return 0;
            return res;
        }
};
