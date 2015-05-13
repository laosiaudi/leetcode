// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Valid_Parentheses.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-14 00:06:12
// MODIFIED: 2015-05-14 00:14:06
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            int size = s.size();
            if (size == 0)
                return false;
            stack<char>ss;
            map<char, int>m;
            m['('] = 1;
            m[')'] = -1;
            m['['] = 2;
            m[']'] = -2;
            m['{'] = 3;
            m['}'] = -3;
            for (int i = 0; i < size; i ++) {
                if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                    ss.push(s[i]);
                else {
                    if (ss.empty())
                        return false;
                    if (m[ss.top()] + m[s[i]] == 0) 
                        ss.pop();
                    else
                        ss.push(s[i]);
                }
            }

            return ss.empty();
        }
};
