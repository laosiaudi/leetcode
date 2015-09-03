// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Basic_Calculator.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-08-21 16:13:16
// MODIFIED: 2015-08-21 17:13:06
#include <iostream>
#include <stack>
using namespace std;

class Solution {
    public:
        int calculate(string s) {
            int len = s.size();
            if (len == 0)
                return 0;
            stack<char> charStack;
            stack<int> numStack;

            int base = 0;
            for (int i = 0; i < len; i ++) {
                if (s[i] >= '0' && s[i] <= '9') {
                    base = s[i] - '0';
                    while (s[i + 1] >= '0' && s[i + 1] <= '9') {
                        base = 10 * base + s[i + 1] - '0';
                        i ++;
                    }
                    numStack.push(base);
                    base = 0;
                } else if (s[i] == '+' || s[i] == '-') {
                    while (!charStack.empty() && charStack.top() != '(') {
                        int ele1 = numStack.top();
                        numStack.pop();
                        int ele2 = numStack.top();
                        numStack.pop();
                        if (charStack.top() == '+')
                            numStack.push(ele1 + ele2);
                        else if (charStack.top() == '-')
                            numStack.push(ele2 - ele1);
                        else if (charStack.top() == '*')
                            numStack.push(ele1 * ele2);
                        else if (charStack.top() == '/')
                            numStack.push(ele2 / ele1);
                        charStack.pop();
                    }
                    charStack.push(s[i]);
                } else if (s[i] == '*' || s[i] == '/') {
                    if (!charStack.empty() && charStack.top() != '(' && charStack.top() != '+' && charStack.top() != '-') {
                        int ele1 = numStack.top();
                        numStack.pop();
                        int ele2 = numStack.top();
                        numStack.pop();
                        if (charStack.top() == '*') {
                            numStack.push(ele1 * ele2);
                            charStack.pop();
                        } else if (charStack.top() == '/') {
                            numStack.push(ele2 / ele1);
                            charStack.pop();
                        }
                    }
                    charStack.push(s[i]);
                } else if (s[i] == '(') {
                    charStack.push(s[i]);
                } else if (s[i] == ')') {
                    if (!charStack.empty() && charStack.top() != '(') {
                        int ele1 = numStack.top();
                        numStack.pop();
                        int ele2 = numStack.top();
                        numStack.pop();
                        if (charStack.top() == '+')
                            numStack.push(ele1 + ele2);
                        else if (charStack.top() == '-')
                            numStack.push(ele2 - ele1);
                        else if (charStack.top() == '*')
                            numStack.push(ele1 * ele2);
                        else if (charStack.top() == '/')
                            numStack.push(ele2 / ele1);
                        charStack.pop();
                    }
                    charStack.pop();
                } else if (s[i] == ' ')
                    continue;
            }

            while (!charStack.empty()) {
                char op = charStack.top();
                int ele1 = numStack.top();
                numStack.pop();
                int ele2 = numStack.top();
                numStack.pop();
                if (op == '+')
                    numStack.push(ele1 + ele2);
                else if (op == '-')
                    numStack.push(ele2 - ele1);
                else if (op == '*')
                    numStack.push(ele2 * ele1);
                else if (op == '/')
                    numStack.push(ele2 / ele1);
                charStack.pop();
            }
            return numStack.top();
        }
};

int main() {
    Solution s;
    cout << s.calculate("(1)");
    return 0;
}
