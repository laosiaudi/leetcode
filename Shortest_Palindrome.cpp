/*********************************************************************************
*     File Name           :     Shortest_Palindrome.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-29 13:56]
*     Last Modified       :     [2015-10-29 14:20]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        string shortestPalindrome(string s) {
            if (s.size() <= 1)
                return s;


            vector<bool>palin(s.size(), false);
            for (int i = 0; i < s.size(); i ++) {
                if (palindrome(i, s))
                    palin[i] = true;
            }

            int index = s.size();
            for (int i = s.size() - 1; i >= 0;i --) {
                if (palin[i] == true) {
                    index = i + 1;
                    break;
                }
            }

            if (index == s.size())
                return s;
            else {
                string tmp;
                for (int i = index; i < s.size() - 1; i ++)
                    tmp.insert(0, 1, s[i]);
                return tmp + s;
            }
        }

        bool palindrome(int end, string s) {
            int start = 0;
            while (start <= end) {
                if (s[start] != s[end])
                    return false;
                else {
                    start ++;
                    end --;
                }
            }
            return true;
        }
};


