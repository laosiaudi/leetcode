// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Power_Of_Two.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-09-03 17:08:25
// MODIFIED: 2015-09-03 17:22:41
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPowerOfTwo(int n) {
            int sign = (n >> 31) & 0x1;
            int y = n + ~1 + 1;
            int res = n & y;

            return !!n & !sign & !res;
        }
};
