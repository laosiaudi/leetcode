/*********************************************************************************
*     File Name           :     Longest_Valid_Parentheses.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-23 22:43]
*     Last Modified       :     [2015-10-24 00:24]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        int longestValidParentheses(string s) {
            int size = s.size();
            if (size == 0)
                return 0;
            stack<int>ss;
            int start = 0;
            int maxLen = 0;
            for (int i = 0;i < size; i ++) {
                if (s[i] == '(') {
                    ss.push(i);
                } else {
                    if (!ss.empty()) {
                        ss.pop();
                        if (ss.empty())
                            maxLen = maxLen > (i - start + 1) ? maxLen : (i - start + 1);
                        else
                            maxLen = maxLen > (i - ss.top()) ? maxLen : (i - ss.top());
                    } else {
                        start = i;
                    }
                }
            }
            return maxLen;
        }
};


