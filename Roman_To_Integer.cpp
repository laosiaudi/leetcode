// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Roman_To_Integer.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-05 16:01:10
// MODIFIED: 2015-05-05 16:46:53
#include <iostream>
using namespace std;

class Solution {
    public:
        int romanToInt(string s) {
           int size = s.size();
           if (size == 0)
               return 0;
           map<char, int>m;
           m['I'] = 1;
           m['V'] = 5;
           m['X'] = 10;
           m['L'] = 50;
           m['C'] = 100;
           m['D'] = 500;
           m['M'] = 1000;

           int res = m[s[size - 1]];
           for (int i = size - 2; i >= 0; i --) {
               if (m[s[i]] >= m[s[i + 1]])
                   res += m[s[i]];
               else
                   res -= m[s[i]];
           }

           return res;

        }
};
