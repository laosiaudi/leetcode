// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Excel_Sheet_Column_Title.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-06 15:03:35
// MODIFIED: 2015-05-06 15:34:12
#include <iostream>
using namespace std;

//进制转换
class Solution {
    public:
        string convertToTitle(int n) {
            stack<char>s;
            while (n > 0) {
                int digit = (n - 1) % 26;
                n = (n - 1) / 26;
                s.push(digit + 'A');
            }
            string res;
            while (!s.empty()) {
               res.push_back(s.top());
               s.pop();
            }
            return res;
        }
};
