// C/C++ File
// AUTHOR:   laosi
// FILE:     Plus_One.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-11 19:01:55
// MODIFIED: 2014-12-11 19:26:37
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> plusOne(vector<int> &digits) {
            int add = 1;
            int temp;
            int newDigit = 0;
            for (int i = digits.size() - 1; i >= 0; i --) {
                if (digits[0] == 9 && add == 1 && i == 0) {
                    digits[0] = 0;
                    newDigit = 1;
                    break;
                }
                temp = digits[i] + add;
                digits[i] = (temp >= 10 )?(temp - 10):(temp);
                add = temp >= 10?1:0;
            }
            if (newDigit == 1)
                digits.insert(digits.begin(), 1);
            return digits;
        }

};

int main() {
    Solution s;
    int k[7] = {9,9,9,9,9,9,9};
    vector<int>v;
    for (int i = 0;i < 7; i ++)
        v.push_back(k[i]);
    s.plusOne(v);
    return 0;
}
