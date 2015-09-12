/*********************************************************************************
*     File Name           :     Valid_Anagram.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-11 14:29]
*     Last Modified       :     [2015-09-11 14:29]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        bool isAnagram(string s, string t) {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }
};


