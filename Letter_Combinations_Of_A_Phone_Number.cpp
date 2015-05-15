// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Letter_Combinations_Of_A_Phone_Number.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-15 13:50:29
// MODIFIED: 2015-05-15 14:14:01
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            int len = digits.size();
            vector<string>v;
            if (len == 0)
                return v;
            string temp;
            recursiveCombinations(v, digits, 0, len, temp);
            return v;
        }

        void recursiveCombinations(vector<string> &v, string digits, int start, int len, string &temp) {
            if (start == len) {
                v.push_back(temp);
                return;
            }
            int num = digits[start] - '0';
            int step;
            if (num == 1 || num == 0)
                step = 0;
            else if (num == 9 || num == 7)
                step = 3;
            else
                step = 2;
            if (num == 1)
                recursiveCombinations(v, digits, start + 1, len, temp);
            else {
                char startChar = 'a' + (num - 2)*3;
                if (num == 9)
                    startChar ++;
                if (num == 8)
                    startChar ++;
                for (int i = 0; i <= step; i ++) {
                    temp.push_back(startChar + i);
                    recursiveCombinations(v, digits, start + 1, len, temp);
                    temp.pop_back();
                }
            }

        }
};
