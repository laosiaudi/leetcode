/*********************************************************************************
*     File Name           :     Word_Break_II.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-16 16:53]
*     Last Modified       :     [2014-12-31 19:04]
*     Description         :
**********************************************************************************/
#include <vector>
#include <unordered_set>
#include <iostream>
#include <string>
#include <map>
using namespace std;
class Solution {
    public:
        vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
            vector<bool>possible(s.size(), false);
            for (int i = 0; i < s.size(); i ++) {
                string tmp = s.substr(0, i + 1);
                if (wordDict.find(tmp) != std::end(wordDict)) {
                    possible[i] = true;
                    continue;
                }
                for (int  j = 0; j <= i - 1; j ++) {
                    possible[i] = possible[j] && (wordDict.find(s.substr(j + 1, i - j)) != std::end(wordDict));
                    if (possible[i])
                        break;
                }
            }
            vector<string>result;
            if (!possible[s.size() - 1])
                return result;
            for (int i = 0; i< s.size(); i ++) {
                if (possible[i] && wordDict.find(s.substr(0, i + 1)) != std::end(wordDict)) {
                    string tmp = s.substr(0, i + 1);
                    recursiveFind(i + 1, s, result, tmp, possible, wordDict);
                }
            }
            return result;
        }

        void recursiveFind(int start, string s, vector<string> & result, string tmp, vector<bool>possible, unordered_set<string>wordDict) {
            if (start == s.size()) {
                result.push_back(tmp);
                return;
            }
            for (int i = start; i < s.size(); i ++) {
                string new_str = s.substr(start, i - start + 1);
                if (possible[i] && wordDict.find(new_str) != std::end(wordDict)) {
                    string ss = (tmp + " " + new_str);
                    recursiveFind(i + 1, s, result, ss, possible, wordDict);
                }
            }
            return;
        }
};


int main() {
    Solution s;
    unordered_set<string> wordDict;
    wordDict.insert("aaaa");
    wordDict.insert("aaa");
    vector<string>res = s.wordBreak("aaaaaaa", wordDict);
    for (auto s : res)
        cout << s << endl;

    return 0;

}


