// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Factorial_Trailing_Zeroes.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-07 17:12:21
// MODIFIED: 2015-05-07 17:31:22
#include <iostream>
using namespace std;
//TLE when 2147483647
class Solution {
    public:
        int trailingZeroes(int n) {
            if (n < 0)
                return 0;
            int res = 0;
            int base = 5;
            while (n >= base) {
                res += n/base;
                base *= 5;
            }
            return res;
        }
};

class BetterSolution {
    public:
        int trailingZeroes(int n) {
            if (n < 0)
                return 0;
            int res = 0;
            while (n > 0) {
                res += n/5; //每次除以5比每次除大数的时间少
                n = n/5;
            }
            return res;
        }
};
int main() {
    BetterSolution s;
    cout << s.trailingZeroes(2147483647);
}


