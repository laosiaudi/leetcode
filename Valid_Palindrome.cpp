// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Valid_Palindrome.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-11 17:43:17
// MODIFIED: 2015-05-11 17:52:49
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isPalindrome(string s) {
            int size = s.size();
            if (size == 0)
                return true;
            std::transform(s.begin(), s.end(), s.begin(), ::tolower);
            int start = 0;
            int end = size - 1;
            while (start < end) {
                while (judge(s[start]) == false && start < end) {
                    start ++;
                }

                while (judge(s[end]) == false && start < end) {
                    end --;
                }
                if (s[start] != s[end])
                    return false;
                start ++;
                end --;
            }
            return true;

        }
        bool judge(char s) {
            if (s >= 'a' && s <= 'z')
                return true;
            if (s >= '0' && s <= '9')
                return true;
            return false;
        }
};
