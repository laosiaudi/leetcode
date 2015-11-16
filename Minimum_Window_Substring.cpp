/*********************************************************************************
*     File Name           :     Minimum_Window_Substring.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-11-14 17:04]
*     Last Modified       :     [2015-11-14 17:36]
*     Description         :
**********************************************************************************/

class Solution {
        public:
            string minWindow(string s, string t) {
                int cnt[256];
                int show[256];
                for (int i = 0; i < 256; i ++) {
                    cnt[i] = 0;
                    show[i] = 0;
                }
    
                for (int i = 0; i < t.size(); i ++)
                    show[t[i]] ++;
                int minLen = s.size() + 1;
                int start = -1;
    
                int left = 0;
                int right = -1;
                int tmpcnt = 0;
                while (left < s.size()) {
                    right ++;
                    for (;right < s.size();right ++) {
                        if (show[s[right]] != 0) {
                            cnt[s[right]] ++;
                            if (cnt[s[right]] <= show[s[right]])
                                tmpcnt ++;
                            if (tmpcnt == t.size())
                                break;
                        }
                    }
                    if (tmpcnt == t.size()) {
                        for (;left <= right;left ++) {
                            if (show[s[left]] != 0) {
                                if (cnt[s[left]] == show[s[left]]) {
                                    if (right - left + 1 < minLen) {
                                        minLen = right - left + 1;
                                        start = left;
                                    }
                                    cnt[s[left]] --;
                                    left = left + 1;
                                    tmpcnt --;
                                    break;
                                } else {
                                    cnt[s[left]] --;
                                }
                            }
                        }
                    } else {
                        if (minLen < s.size() + 1)
                            return s.substr(start, minLen);
                        else
                            return "";
                    }
                }
    
                return s.substr(start, minLen);
            }
    };
    
    
