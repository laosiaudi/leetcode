// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Largest_Number.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-04 16:52:02
// MODIFIED: 2015-06-04 17:54:57
#include <iostream>
using namespace std;

class Solution {
    public:
        struct Num {
            string val;
            bool operator < (const Num &num) const {
                if (val == "0" && num.val != "0")
                    return true;
                if (val !=  "0" && num.val == "0")
                    return false;
                return (val + num.val < num.val + val);

            }
        };
        string largestNumber(vector<int> &nums) {
            int size = nums.size();
            vector<Num>v;
            Num temp;
            for (int i = 0; i < nums.size(); i ++) {
               temp.val = to_string(nums[i]);
               v.push_back(temp);
            }
            sort(v.begin(), v.end());
            string res;
            for (int i = v.size() - 1; i >= 0; i --) {
                if (res == "0" && v[i].val == "0")
                    continue;
                res += v[i].val;
            }
            return res;
        }
};
