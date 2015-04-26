// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Longest_Substring_Without_Repeating_Characters.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-26 11:18:23
// MODIFIED: 2015-04-26 11:55:18
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
            map<char,int>m;
            int maxLen = 0;
            if (s.size() == 0)
                return 0;
            m[s[0]] = 0;
            int index = 1;
            int last = 0;
            for (int i = 1; i < s.size(); i ++) {
               if (m.find(s[i]) == m.end()) {
                   index ++;
                   m[s[i]] = i;
               } else {
                   if (m[s[i]] >= last) {
                       if (index > maxLen)
                           maxLen = index;
                       index = i - m[s[i]];
                       last = m[s[i]];
                       m[s[i]] = i;
                   } else {
                       index ++;
                       m[s[i]] = i;
                   }

               }
            }
            return maxLen > index ? maxLen : index;
        }
};

int main() {
    Solution s;
    cout << s.lengthOfLongestSubstring("abba") << endl;
    cout << s.lengthOfLongestSubstring("bbbbb") << endl;
    cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << s.lengthOfLongestSubstring("abcdefbcdefghi") << endl;
    return 0;
}
