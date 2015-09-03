// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Single_Number_II.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-06 20:27:46
// MODIFIED: 2015-06-06 21:20:47
#include <iostream>
using namespace std;
//each number appears three times or once.
class Solution {
    public:
        //O(n) with extra space
        int singleNumber(vector<int> &nums) {
            vector<int>v(32, 0);
            int res = 0;
            for (int i = 0; i < 32; i ++) {
                for (int j = 0; j < nums.size(); j ++) {
                   if ((nums[j] >> i) & 0x1)
                       v[i] ++;
                }
                res = res | ((v[i] % 3) << i);
            }

            return res;
        }
};
class BetterSolution {
    public:
        //O(n) without extra space
        int singleNumber(vector<int> &nums) {
            int count = 0;
            int res = 0;
            for (int i = 0; i < 32; i ++) {
                for (int j = 0; j < nums.size(); j ++) {
                   if ((nums[j] >> i) & 0x1)
                       count ++;
                }
                res = res | ((count % 3) << i);
                count = 0;
            }

            return res;
        }
};
