// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Evaluate_Reverse_Polish_Notation.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-01 17:04:36
// MODIFIED: 2015-06-01 17:14:44
#include <iostream>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
            stack<int>s;
            for (int i = 0; i < tokens.size(); i ++) {
                string temp = tokens[i];
                if (temp == "+") {
                    int operand_1 = s.top();
                    s.pop();
                    int operand_2 = s.top();
                    s.pop();
                    s.push(operand_1 + operand_2);
                } else if (temp == "-") {
                    int operand_1 = s.top();
                    s.pop();
                    int operand_2 = s.top();
                    s.pop();
                    s.push(operand_2 - operand_1);
                } else if (temp == "*") {
                    int operand_1 = s.top();
                    s.pop();
                    int operand_2 = s.top();
                    s.pop();
                    s.push(operand_1 * operand_2);
                } else if (temp == "/") {
                    int operand_1 = s.top();
                    s.pop();
                    int operand_2 = s.top();
                    s.pop();
                    s.push(operand_2 / operand_1);
                } else {
                    s.push(stringToNum(temp));
                }

            }
            return s.top();

        }

        int stringToNum(string s) {
            int res = 0;
            int sign = 1;
            for (int i = 0; i < s.size(); i ++) {
                if (s[i] == '-')
                    sign = -sign;
                else
                    res = res * 10 + s[i] - '0';
            }
            return sign*res;
        }
};
