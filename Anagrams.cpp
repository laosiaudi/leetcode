// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Anagrams.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-26 10:07:01
// MODIFIED: 2015-04-26 11:16:03
#include <iostream>
using namespace std;

//TLE
class Solution {
    public:
        vector<string> anagrams(vector<string>& strs) {
            vector<string>v;
            map<set<char>, int>m;
            for (int i = 0; i < strs.size(); i ++) {
                set<char>s;
                for (int j = 0; j < strs[i].size(); j ++) {
                   s.insert(strs[i][j]);
                }
                if (strs[i] == "")
                    s.insert('#');
                if (m.find(s) == m.end()) {
                   m[s] = i;
                } else {
                   v.push_back(strs[m[s]]);
                   v.push_back(strs[i]);
                }
            }
            return v;
        }
};

//Sort and hash
class BetterSolution {
    public:
        vector<string> anagrams(vector<string>& strs) {
            vector<string>v;
            map<string,int>m;
            set<string>s;
            for (int i = 0; i < strs.size(); i ++) {
                string c = strs[i];
                sort(c.begin(), c.end());
                if (m.find(c) == m.end()) {
                   m[c] = i;
                } else {
                   if (m[c] >= 0) {
                       v.push_back(strs[m[c]]);
                       m[c] = -1;
                   }
                   v.push_back(strs[i]);
                }
            }
            return v;
        }
};

//也可以为字符串构造hash值，用26个质数代替26个字母的值，这样就保证了hash值唯一
