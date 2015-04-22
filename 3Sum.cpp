// C/C++ File
// AUTHOR:   LaoSi
// FILE:     3Sum.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-21 23:24:58
// MODIFIED: 2015-04-22 15:40:00
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<vector<int> > threeSum(vector<int> &num) {
            vector<vector<int> >v;
            if (num.size() <= 2)
                return v;
            sort(num.begin(), num.end());
            for (int i = 0; i <= num.size() - 3; i ++) {
                if (i > 0 && num[i] == num[i - 1])
                    continue;
                int start = i + 1;
                int end = num.size() - 1;
                while (start < end) {
                    if (start > i + 1 && num[start] == num[start - 1]) {
                        start ++;
                        continue;
                    }
                    if (end < num.size() - 1 && num[end] == num[end + 1]) {
                        end --;
                        continue;
                    }
                    if (num[start] + num[end] == -num[i]) {
                        vector<int>temp;
                        temp.push_back(num[i]);
                        temp.push_back(num[start]);
                        temp.push_back(num[end]);
                        v.push_back(temp);
                        start ++;
                        end --;
                    } else if (num[start] + num[end] > -num[i]) {
                        end --;
                    } else {
                        start ++;
                    }
                }
            }
            return v;
        }
};
