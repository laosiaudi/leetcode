// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Excel_Sheet_Column_Number.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-07 16:52:35
// MODIFIED: 2015-05-07 16:55:58
#include <iostream>
using namespace std;

class Solution {
    public:
        int titleToNumber(string s) {
            int size = s.size();
            int base = 1;
            int res = 0;
            for (int i = size - 1; i >= 0;i --) {
                res += (s[i] - 'A' + 1)*base;
                base *= 26;
            }
            return res;
        }
};
