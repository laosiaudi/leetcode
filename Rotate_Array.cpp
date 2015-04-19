// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Rotate_Array.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-19 10:08:53
// MODIFIED: 2015-04-19 10:47:01
#include <iostream>
using namespace std;

class Solution {
    public:
        void rev(int nums[], int start, int end) {
            while (start < end) {
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
                start ++;
                end --;
            }
        }
        void rotate(int nums[], int n, int k) {
            k = k % n;
            if (k <= 0)
                return;
            rev(nums, 0, n - 1);
            rev(nums, 0, k - 1);
            rev(nums, k, n - 1);
        }

};
