/*********************************************************************************
*     File Name           :     Word_Ladder.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-22 17:04]
*     Last Modified       :     [2015-10-22 21:59]
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
        unordered_map<string, bool>visit;
        struct node {
            vector<string>v;
            string val;
        };
        vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordList) {
            vector<vector<string>>result;
            bool find = false;
            queue<struct node>q;
            struct node newNode;
            newNode.val = beginWord;
            newNode.v.push_back(beginWord);
            q.push(newNode);
            struct node ter;
            ter.val = "#";
            q.push(ter);
            while (!q.empty()) {
                struct node tmpNode = q.front();
                string tmp = tmpNode.val;
                q.pop();
                visit[tmp] = true;
                if (tmp == "#") {
                    if (!q.empty()) {
                        struct node ter;
                        ter.val = "#";
                        q.push(ter);
                    }
                    if (find)
                        return result;
                    continue;
                }
                if (equalEnd(tmp, endWord)) {
                    find = true;
                    tmpNode.v.push_back(endWord);
                    result.push_back(tmpNode.v);
                    continue;
                }
                if (find)
                    continue;
                for (int i = 0; i < tmp.size(); i ++) {
                    for (int j = 0; j < 26; j ++) {
                        if (tmp[i] == 'a' + j)
                            continue;
                        string item = tmp;
                        item[i] = 'a' + j;
                        if (wordList.find(item) != wordList.end()) {
                            if (visit.find(item) == visit.end()) {
                                tmpNode.val = item;
                                tmpNode.v.push_back(item);
                                q.push(tmpNode);
                                tmpNode.v.erase(std::begin(tmpNode.v) + tmpNode.v.size() - 1);
                            }
                        }
                    }
                }
            }
            return result;
        }
        bool equalEnd(string tmp, string end) {
            if (tmp.size() != end.size())
                return false;
            int cnt = 0;
            for (int i = 0; i < tmp.size(); i ++) {
                if (tmp[i] != end[i])
                    cnt ++;
                if (cnt > 1)
                    return false;
            }
            return cnt == 1;
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
    vector<vector<string>> result = ss.findLadders("hit", "cog", s);
    for (auto item : result) {
        for (auto i : item) {
            cout << i << " ";
        }
        cout << endl;
    }
}


