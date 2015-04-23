// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Search_In_Rotated_Sorted_Array_II.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-23 17:21:59
// MODIFIED: 2015-04-23 17:41:56
#include <iostream>
using namespace std;

class Solution { //O(n) better to use linear search
    public:
    bool search(vector<int>& nums, int target) {
        int num = nums.size();
        if (num == 0)
            return false;
        return recursiveSearch(nums, target, 0, num - 1);
    }

    bool recursiveSearch(vector<int> &nums, int target, int start, int end) {
        if (start > end)
            return false;
        if (start == end)
            return nums[start] == target? true : false;
        int middle = (start + end)/2;
        if (nums[middle] == target)
            return true;
        if (nums[middle] < nums[end]) {
            if (target > nums[middle] && target <= nums[end]) {
                bool flag = recursiveSearch(nums, target, middle + 1, end);
                if (flag == false)
                    return recursiveSearch(nums, target, start, middle - 1);
                else
                    return true;
            } else {
                bool flag = recursiveSearch(nums, target, start, middle - 1);
                if (flag == false)
                    return recursiveSearch(nums, target, middle + 1, end);
                else
                    return true;
            }
        } else {
            if (target < nums[middle] && target >= nums[start]) {
                bool flag = recursiveSearch(nums, target, start, middle - 1);
                if (flag == false)
                    return recursiveSearch(nums, target, middle + 1, end);
                else
                    return true;
            } else {
                bool flag = recursiveSearch(nums, target, middle + 1, end);
                if (flag == false)
                    return recursiveSearch(nums, target, start , middle - 1);
                else
                    return true;
            }
        }
    }
};

class Solution {
    public:
        bool search(vector<int> &nums, int target) {
            int num = nums.size();
            if(0 == num)
                return false;
            for(int i = 0; i < num; ++i)
                if(nums[i] == target)
                    return true;
            return false;
        }
};
