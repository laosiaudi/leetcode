// C/C++ File
// AUTHOR:   LaoSi
// FILE:     4Sum.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-22 15:47:17
// MODIFIED: 2015-04-22 16:03:42
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<vector<int> > fourSum(vector<int> &num, int target) {
            vector<vector<int> >v;
            if (num.size() <= 3)
                return v;
            sort(num.begin(), num.end());
            for (int i = 0; i <= num.size() - 4; i ++) {
                if (i > 0 && num[i] == num[i - 1])
                    continue;
                for (int j = i + 1; j <= num.size() - 3; j ++) {
                    if (j > i + 1 && num[j] == num[j - 1])
                        continue;
                    int start = j + 1;
                    int end = num.size() - 1;
                    while (start < end) {
                        if (start > j + 1 && num[start] == num[start - 1]) {
                            start ++;
                            continue;
                        }
                        if (end < num.size() - 1 && num[end] == num[end + 1]) {
                            end --;
                            continue;
                        }
                        if (num[start] + num[end] + num[i] + num[j] == target) {
                            vector<int>temp;
                            temp.push_back(num[i]);
                            temp.push_back(num[j]);
                            temp.push_back(num[start]);
                            temp.push_back(num[end]);
                            v.push_back(temp);
                            start ++;
                            end --;
                        } else if (num[start] + num[end]  + num[i] + num[j] > target) {
                            end --;
                        } else {
                            start ++;
                        }
                    }
                }
            }

        }
};
