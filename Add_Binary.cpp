// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Add_Binary.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-06 13:34:33
// MODIFIED: 2015-05-06 13:44:44
#include <iostream>
using namespace std;

class Solution {
    public:
        string addBinary(string a, string b) {
            int len1 = a.size();
            int len2 = b.size();
            int maxLen = len1 > len2 ? len1 : len2;
            string res(maxLen, ' ');
            maxLen--;
            int carry = 0;
            for (int i = len1 - 1, j = len2 - 1;i >= 0 || j >= 0; i --, j --) {
                int av = (i >= 0?a[i]:'0') - '0';
                int bv = (j >= 0?b[j]:'0') - '0';
                int temp = av + bv + carry;
                carry = temp / 2;
                temp = temp % 2;
                res[maxLen--] = temp + '0';
            }
            if (carry > 0)
                res = "1" + res;
            return res;

        }
};
