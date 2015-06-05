// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Numbers_Of_1_Bits.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-04 18:16:19
// MODIFIED: 2015-06-04 18:20:58
#include <iostream>
using namespace std;

class Solution {
    public:
        int hammingWeight(uint32_t n) {
           int num[16] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
           int i = 8;
           int res = 0;
           while (i --) {
               uint32_t temp = n & 0xf;
               res += num[temp];
               n = n >> 4;
           }
           return res;
        }
};
