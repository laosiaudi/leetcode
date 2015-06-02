// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Contains_Duplicate_II.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-01 15:55:10
// MODIFIED: 2015-06-01 16:26:04
#include <iostream>
using namespace std;

class Solution {
    public:
        //sliding window 76ms
        bool containsNearbyDuplicate(vector<int> &nums, int k) {
           int start = 0, end = 0;
           set<int>s;
           for (int i = 0; i < nums.size(); i ++) {
               if (s.find(nums[i]) == s.end()) {
                   s.insert(nums[i]);
                   end ++;
               } else {
                   return true;
               }

               if (end - start > k) {
                   s.erase(nums[start]);
                   start ++;
               }
           }
           return false;
        }

        //using struct to keep index and value, 20ms
        struct Node {
            int value;
            int index;
            bool operator < (const Node& nd) const {
                if (value < nd.value)
                    return true;
                else if (value > nd.value)
                    return false;
                else {
                    return index < nd.index;
                }
            }
        };
        bool containsNearbyDuplicate(vector<int> &nums, int k) {
            if (nums.size() == 0)
                return false;
            vector<Node>v;
            for (int i = 0; i < nums.size(); i ++) {
               Node temp;
               temp.value = nums[i];
               temp.index = i;
               v.push_back(temp);
            }
            sort(v.begin(), v.end());
            int start = 0, end = 1;
            while (start <= nums.size() - 1 && end <= nums.size() - 1) {
                if (v[start].value == v[end].value) {
                    if (v[end].index - v[start].index <= k)
                        return true;
                    else {
                        start = end;
                        end ++;
                    }
                }
                if (end == nums.size())
                    break;

                if (v[start].value != v[end].value) {
                    start = end;
                    end = end + 1;
                }
            }
            return false; 
        }
};
