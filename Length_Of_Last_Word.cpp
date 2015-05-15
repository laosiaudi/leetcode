// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Length_Of_Last_Word.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-15 13:43:58
// MODIFIED: 2015-05-15 13:47:24
#include <iostream>
using namespace std;

class Solution {
    public:
        int lengthOfLastWord(string s) {
            int len = s.size();
            int i = 0;
            int res = 0;
            while (i < len) {
                while (s[i] == ' ' && i < len)
                    i ++;
                if (i == len)
                    break;
                int start = i;
                while (s[i] != ' ' && i < len)
                    i ++;
                int end = i - 1;
                res = end - start + 1;
            }
            return res;
        }
};
