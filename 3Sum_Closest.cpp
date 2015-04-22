// C/C++ File
// AUTHOR:   LaoSi
// FILE:     3Sum_Closest.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-22 17:03:11
// MODIFIED: 2015-04-22 17:17:54
#include <iostream>
using namespace std;

class Solution {
    public:
        int threeSumClosest(vector<int> &num, int target) {
            if (num.size() <= 2)
                return 0;
            sort(num.begin(), num.end());
            int minValue = 999999;
            int result = 0;

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
                    if (num[start] + num[end] + num[i] - target >= 0) {
                        int e  = abs(num[start] + num[end] + num[i] - target);
                        if (e < minValue) {
                            result = num[start] + num[end] + num[i];
                            minValue = e;
                        }
                        end --;
                        
                    } else {
                        int e  = abs(num[start] + num[end] + num[i] - target);
                        if (e < minValue) {
                            result = num[start] + num[end] + num[i];
                            minValue = e;
                        }
                        start ++;
                    }
                }
            }
            return result;
        }

};
