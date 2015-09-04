// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Summary_Ranges.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-09-04 17:10:50
// MODIFIED: 2015-09-04 17:22:02
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<string> summaryRanges(vector<int> &nums) {
            int n = nums.size();
            string result = "";
            vector<string> v;
            if (n == 0)
                return v;
            int start = nums[0];
            int tmp = nums[0];
            for (int i = 1; i < n; i ++) {
                if (nums[i] - tmp == 1)
                    tmp = nums[i];
                else {
                    if (tmp == start)
                        result = to_string(start);
                    else
                        result =  to_string(start) + "->" + to_string(tmp);
                    v.push_back(result);
                    start = nums[i];
                    tmp = nums[i];
                }
            }

            if (tmp == start)
                v.push_back(to_string(tmp));
            else
                v.push_back(to_string(start) + "->" + to_string(tmp));
            return v;
        }
};
