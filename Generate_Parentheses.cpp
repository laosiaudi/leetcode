// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Generate_Parentheses.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-15 11:10:10
// MODIFIED: 2015-05-15 13:40:13
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<string> generateParenthesis(int n) {
            vector<string>v;
            if (n <= 0)
                return v;
            string temp;
            recursiveGenerate(v, n, n, temp);
            return v;
        }
        void recursiveGenerate(vector<string> &v, int left, int right, string temp) {
            if (left > right)
                return;
            if (left == 0 && right == 0)
                v.push_back(temp);
            if (left > 0) {
                temp.push_back('(');
                recursiveGenerate(v, left - 1, right, temp);
                temp.pop_back();
            }

            if (right > 0) {
                temp.push_back(')');
                recursiveGenerate(v, left, right - 1, temp);
                temp.pop_back();
            }
        }
};
