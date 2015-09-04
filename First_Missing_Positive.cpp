// C/C++ File
// AUTHOR:   LaoSi
// FILE:     First_Missing_Positive.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-09-04 00:14:01
// MODIFIED: 2015-09-04 17:07:00
#include <iostream>
using namespace std;

class Solution {
    public: //O(nlogn)
        int firstMissingPositive(vector<int> &nums) {
            int n = nums.size();
            if (n == 0)
                return 1;
            sort(nums.begin(), nums.end());

            int tmp = 0;
            for (int i = 0; i < n; i ++) {
                if (nums[i] > 0) {
                    if (i > 0 && nums[i] == nums[i - 1])
                        continue;
                    if (nums[i] - tmp == 1) {
                        tmp ++;
                    } else {
                        return tmp + 1;
                    }
                }
            }
            return nums[n - 1] + 1;
        }

        //O(n) using hash table, make a[i] = i + 1
        int bestFirstMissingPositive(vector<int> &nums) {
            int n = nums.size();
            for (int i = 0 ;i < n; i ++) {
                while (i != nums[i] - 1) {
                    if (nums[i] <= 0 || nums[i] > n || nums[i] ==nums[nums[i] - 1])
                        break;
                    int tmp = nums[i];
                    nums[i] = nums[nums[i] - 1];
                    nums[tmp - 1] = tmp;
                }
            }

            for (int i = 0; i < n; i ++) {
                if (nums[i] != i + 1)
                    return i + 1;
            }

            return n + 1;
        }
};
