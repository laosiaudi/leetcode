// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Reverse_Bits.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-04 17:59:36
// MODIFIED: 2015-06-04 18:12:58
#include <iostream>
using namespace std;

//to optimize, can split the 32bits to chunks of 4bits, and store 
//reversed representations of every 4-bit patterns, e.g. 1000 --> 0001
class Solution {
    public:
        uint32_t reverseBits(uint32_t n) {
            int counter = 31;
            uint32_t res = 0;
            while (counter--){
                res += (n & 0x1);
                res = res << 1;
                n = n >> 1;
            }
            return res + (n & 0x1);
        }
};
