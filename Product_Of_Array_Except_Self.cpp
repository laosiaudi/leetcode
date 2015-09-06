// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Product_Of_Array_Except_Self.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-09-05 17:01:51
// MODIFIED: 2015-09-05 17:15:14
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> productExceptSelf(vector<int>& nums) {
            int size = nums.size();
            vector<int>result(size, 1);
            if (size == 0 || size == 1)
                return result;

            for (int i = size - 2; i >= 0; i --) {
                result[i] = result[i + 1] * nums[i + 1];
            }

            int tmp = 1;
            for (int i = 0; i < size; i ++) {
                result[i] = result[i] * tmp;
                tmp *= nums[i];
            }

            return result;
        }
};
