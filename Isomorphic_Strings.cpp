/*********************************************************************************
*     File Name           :     Isomorphic_Strings.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-11 14:32]
*     Last Modified       :     [2015-11-01 23:01]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            map<char, char>m;
            map<char, char>r;
            for (int i = 0; i < s.size(); i ++) {
                char sc = s[i];
                char tc = t[i];
                if (m.find(sc) == m.end() && r.find(tc) == r.end()) {
                    m[sc] = tc;
                    r[tc] = sc;
                } else {
                    if (r[tc] != sc)
                        return false;
                    if (m[sc] != tc)
                        return false;
                }
            }
            return true;
        }
};


