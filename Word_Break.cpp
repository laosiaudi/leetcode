// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Word_Break.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-19 16:48:49
// MODIFIED: 2015-05-20 17:11:00
#include <iostream>
using namespace std;

//DP
class Solution {
    public:
        bool wordBreak(string s, unordered_set<string> & wordDict) {
            int len = s.size();
            if (len == 0)
                return false;
            vector<bool>possible(len, false);
            for (int i = 0; i < len; i ++) {
                string sub = s.substr(0, i + 1);
                if (wordDict.find(sub) != wordDict.end()) {
                    possible[i] = true;
                    continue;
                }

                for (int j = 0; j <= i - 1; j ++) {
                    possible[i] = possible[j] && wordDict.find(s.substr(j + 1, i - j)) != wordDict.end();
                    if (possible[i])
                        break;
                }

                
            }

            return possible[len - 1];
        }
};
