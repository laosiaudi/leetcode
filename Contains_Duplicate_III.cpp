// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Contains_Duplicate_III.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-01 16:48:08
// MODIFIED: 2015-06-01 17:04:20
#include <iostream>
using namespace std;

class Solution {
    public:
        //TLE
        bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
            for (int i = 0;i < nums.size(); i += 1) {
                for (int j = i + 1;j <= i + k && j < nums.size(); j ++) {
                    int temp1 = nums[i];
                    int temp2 = nums[j];
                    int dis = temp1 - temp2;
                    if (dis < 0)
                        dis = -dis;
                    if (dis <= t)
                        return true;
                }
            }

            return false;
        }
};
