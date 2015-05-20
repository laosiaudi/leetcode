// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Implement_strStr.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-18 17:01:53
// MODIFIED: 2015-05-18 17:27:12
#include <iostream>
using namespace std;


//KMP algorithm
class Solution {
    public:
        int strStr(string haystack, string needle) {
            if (needle == "")
                return 0;
            if (haystack == "")
                return -1;
            int m = haystack.size();
            int n = needle.size();
            vector<int> next = getNext(needle);

            int j = -1;
            for (int i = 0; i < m;i ++) {
                while (j >= 0 && haystack[i] != needle[j + 1])
                    j = next[j];
                if (haystack[i] == needle[j + 1])
                    j ++;
                if (j == n - 1)
                    return (i - n + 1);
            }
            return -1;

        }

        vector<int> getNext(string s) {
            int n = s.size();
            vector<int> next(n, -1);
            
            int k = -1;
            int j = 1;

            for (; j < n; j ++) {
                while (k >= 0 && s[k + 1] != s[j])
                    k = next[k];
                if (s[k + 1] == s[j])
                    k ++;
                next[j] = k;
            }


            return next;
        }
};
