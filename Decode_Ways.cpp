// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Decode_Ways.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-15 10:35:29
// MODIFIED: 2015-05-15 10:59:54
#include <iostream>
using namespace std;

class Solution {
    public:
        int numDecodings(string s) {
            int num = 0;
            int len = s.size();
            if (len == 0)
                return 0;
            vector<int>res(len + 1, 1);
            if (s[len - 1] != '0')
                res[1] = 1;
            else
                res[1] = 0;
            for (int i = 2; i <= len ; i ++) {
                int d1 = s[len - i] - '0';
                if (d1 == 0) {
                    res[i] = 0;
                    continue;
                }
                int d2 = s[len - i + 1] - '0';
                int temp = d1 * 10 + d2;
                if (temp <= 26)
                    res[i] = res[i - 1] + res[i - 2];
                else
                    res[i] = res[i - 1];
            }
            return res[len];
        }
};
