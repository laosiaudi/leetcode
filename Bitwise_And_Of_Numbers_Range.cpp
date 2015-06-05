// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Bitwise_And_Of_Numbers_Range.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-04 18:30:04
// MODIFIED: 2015-06-05 11:40:52
#include <iostream>
using namespace std;

class Solution {
    public:
        int rangeBitwiseAnd(int m, int n) {
            int mask = ~0;
            while (mask != 0) {
                if ((m & mask) == (n & mask))
                    break;
                mask = mask << 1;
            }
            return m & mask;
        }
};

int main() {
    Solution s;
    cout << (2147483646 & 2147483647);
    cout << s.rangeBitwiseAnd(2147483646, 2147483647);
}
