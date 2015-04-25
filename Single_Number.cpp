// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Single_Number.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-25 10:12:20
// MODIFIED: 2015-04-25 10:14:02
#include <iostream>
using namespace std;

//使用异或的思想，出现两次就变成0
class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int n = nums.size();
            if (n == 0)
                return -1;
            int ans = 0;
            for (int i = 0; i < n;i ++)
                ans ^= nums[i];
            return ans;
        }
};
