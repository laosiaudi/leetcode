/*********************************************************************************
*     File Name           :     google_isunique.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-15 23:57]
*     Last Modified       :     [2015-10-16 00:14]
*     Description         :
**********************************************************************************/
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iostream>
using namespace std;
class Solution {
    public:
        map<string, set<string>>abbr_set;
        void buildSet(vector<string> dict) {
                for (string s : dict) {
                    int size = s.size();
                    string abbr = s[0] + to_string(size - 2) + s[size - 1];
                    abbr_set[abbr].insert(s);
                }
        }

        bool isUnique(string word) {
            int n = word.size();
            string abbr = word[0] + to_string(n - 2) + word[n - 1];
            return abbr_set[abbr].count(word) == abbr_set[abbr].size();
        }
};

int main() {
    Solution s;
    vector<string>v;
    v.push_back("deer");
    v.push_back("door");
    v.push_back("cake");
    v.push_back("card");

    s.buildSet(v);
    if (s.isUnique("dear"))
        cout << "error\n";
    if (s.isUnique("cart"))
        cout << "cart\n";
    if (s.isUnique("cane"))
        cout << "error\n";
    if (s.isUnique("make"))
        cout << "make\n";
    return 0;
}




