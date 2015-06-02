// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Contains_Duplicate.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-01 15:34:26
// MODIFIED: 2015-06-01 15:40:05
#include <iostream>
using namespace std;

class Solution {
    public:
        bool containsDuplicate(vector<int> &nums) {
            /* can also put nums into a set
             * then check if nums.size() > set.size()
             */
            map<int, int>m;
            for (int i = 0; i < nums.size(); i ++) {
                if (m.find(nums[i]) == m.end())
                    m[nums[i]] = 1;
                else
                    return true;
            }
            return false;
        }
};
