/*********************************************************************************
*     File Name           :     google_summaryrange.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-16 00:48]
*     Last Modified       :     [2015-10-16 01:03]
*     Description         :
**********************************************************************************/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
    public:
        vector<string> summaryRanges(vector<int> & nums) {
            vector<string>result;
            if (nums.size() == 0)
                return result;
            string tmp;
            tmp.push_back(nums[0] + '0');
            for (int i = 1; i < nums.size(); i ++) {
                if (nums[i] - nums[i - 1] != 1) {
                    if (nums[i - 1] + '0' == tmp[0])
                        result.push_back(tmp);
                    else {
                        tmp += "->";
                        tmp.push_back(nums[i - 1] + '0');
                        result.push_back(tmp);
                    }
                    tmp.clear();
                    tmp.push_back(nums[i] + '0');
                }
            }
            if (nums[nums.size() - 1] + '0' == tmp[0])
                result.push_back(tmp);
            else {
                tmp += "->";
                tmp.push_back(nums[nums.size() - 1] + '0');
                result.push_back(tmp);
            }
            return result;
        }
};

int main() {
    vector<int>v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    v.push_back(4);
    v.push_back(5);
    v.push_back(7);
    Solution s;
    vector<string> r = s.summaryRanges(v);
    for (string s : r)
        cout << s << endl;
    return 0;

}





