// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Reverse_Integer.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-05 17:44:37
// MODIFIED: 2015-05-05 18:06:21
#include <iostream>
using namespace std;

class Solution {
    public:
        int reverse(int x) {
            bool isNega = false;
            if (x < 0) {
                isNega = true;
                x = - x;
            }
            long long res = 0;//handle overflow
           
            while (x != 0) {
                int temp = x % 10;
                res = res* 10 + temp;
                x = x / 10;
            }
            if (res > INT_MAX || res < INT_MIN) //handle overflow
                return 0;
            return isNega? -res:res;
            
        }
};
