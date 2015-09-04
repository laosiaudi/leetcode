// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Missing_Number.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-09-03 17:26:45
// MODIFIED: 2015-09-03 20:49:31
#include <iostream>
using namespace std;

class Solution {
    public:
        int missingNumber(vector<int> &nums) {
           int n = nums.size();
           int temp = 1;
           for (int i = 2; i <= n; i ++)
               temp = temp ^ i;
           for (int i = 0;i < n; i ++)
               temp = temp ^ nums[i];
           return temp;
        }
};
