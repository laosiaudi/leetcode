// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Two_Sum.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-11 20:21:15
// MODIFIED: 2015-04-11 20:57:14
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
    public:
    struct ele {
        int val;
        int index;
        bool operator < (const ele& right) const {
            return val < right.val;
        }
    };
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<ele>number;
        for (int i = 0; i < numbers.size(); i ++) {
            ele temp;
            temp.val = numbers[i];
            temp.index = i;
            number.push_back(temp);
        }
        sort(number.begin(), number.end(), less<ele>());
        vector<int>result;
        bool flag = false;
        for (int i = 0; i < number.size() - 1 && flag == false; i ++) {
            for (int j = i + 1; j < number.size(); j ++) {
                if (target == number[i].val + number[j].val) {
                   int index1;
                   int index2;
                   index1 = number[i].index < number[j].index ? number[i].index : number[j].index;
                   index2 = number[i].index > number[j].index ? number[i].index : number[j].index;
                   result.push_back(index1 + 1);
                   result.push_back(index2 + 1);
                   flag = true;
                   break;
                }
            }
        }
        return result;
    }
};

int main() {
    vector<int>v;
    v.push_back(-1);
    v.push_back(-2);
    v.push_back(-3);
    v.push_back(-4);
    v.push_back(-5);
    vector<int>result;
    Solution s;
    result = s.twoSum(v, -8);
    cout << result[0] << " " << result[1] << endl;
    return 0;
}
