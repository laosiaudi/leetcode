// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Kth_Largest_Element_In_An_Array.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-31 20:38:23
// MODIFIED: 2015-05-31 21:09:29
#include <iostream>
using namespace std;

class Solution {
    public:
        int findKthLargest(vector<int> &nums, int k) {
            sort(nums.begin(), nums.end());
            return nums[nums.size() - k];
        }
};

class QuickerSolution {
    public:
        int findKthLargest(vector<int> &nums, int k) {
            int L = 0, R = nums.size() - 1;
            while (L < R) {
                int left = L, right = R;
                int key = nums[left];
                while (left < right) {
                    while (left < right && nums[right] < key)
                        right --;
                    nums[left] = nums[right];
                    while (left < right && nums[left] >= key)
                        left ++;
                    nums[right] = nums[left];
                }

                nums[left] = key;
                if (left == k - 1)
                    return nums[left];
                else if (left > k - 1)
                    R = left - 1;
                else
                    L = left + 1;
            }
            return nums[k - 1];
        }
};
