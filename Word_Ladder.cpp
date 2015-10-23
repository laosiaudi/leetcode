/*********************************************************************************
*     File Name           :     Word_Ladder.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-22 17:04]
*     Last Modified       :     [2015-10-22 19:59]
*     Description         :
**********************************************************************************/
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <string>
#include <iostream>
using namespace std;
class Solution {
    public:
        unordered_map<string, vector<string>>dict;
        unordered_set<string>visit;
        int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
            for (int i = 0; i < beginWord.size(); i ++) {
                for (int j = 0; j < 26; j ++) {
                    if (beginWord[i] == 'a' + j)
                        continue;
                    string tmp = beginWord;
                    tmp[i] = 'a' + j;
                    if (wordList.find(tmp) != wordList.end())
                        dict[beginWord].push_back(tmp);
                }
            }
            for (int i = 0; i < endWord.size(); i ++) {
                for (int j = 0; j < 26; j ++) {
                    if (endWord[i] == 'a' + j)
                        continue;
                    string tmp = endWord;
                    tmp[i] = 'a' + j;
                    if (wordList.find(tmp) != wordList.end())
                        dict[tmp].push_back(endWord);
                }
            }

            for (auto item : wordList) {
                for (int i = 0; i < item.size(); i ++) {
                    for (int j = 0; j < 26; j ++) {
                        if (item[i] == 'a' + j)
                            continue;
                        string tmp = item;
                        tmp[i] = 'a' + j;
                        if (wordList.find(tmp) != wordList.end())
                            dict[item].push_back(tmp);
                    }
                }
            }

            queue<string>q;
            q.push(beginWord);
            q.push("#");
            int cnt = 1;
            while (!q.empty()) {
                string tmp = q.front();
                visit.insert(tmp);
                q.pop();
                if (tmp == "#") {
                    if (!q.empty())
                        q.push("#");
                    cnt ++;
                    continue;
                }
                for (auto item : dict[tmp]) {
                    if (item == endWord)
                        return cnt + 1;
                    if (visit.find(item) == visit.end())
                        q.push(item);
                }
            }
            return 0;
        }
};

int main() {
    Solution ss;
    unordered_set<string>s;
    s.insert("hot");
    s.insert("dot");
    s.insert("dog");
    s.insert("lot");
    s.insert("log");
    cout << ss.ladderLength("hit", "cog", s);
}


