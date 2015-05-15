// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Count_And_Say.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-15 10:22:48
// MODIFIED: 2015-05-15 10:32:57
#include <iostream>
using namespace std;

class Solution {
    public:
        string countAndSay(int n) {
            string res = "1";
            for (int i = 2; i <= n ; i ++) {
                string temp;
                int count = 1;
                res = res + "#";
                for (int j = 0; j < res.size() - 1; j ++) {
                    if (res[j] == res[j + 1])
                        count ++;
                    else {
                       temp.push_back(count + '0');
                       temp.push_back(res[j]);
                       count = 1;
                    }
                }
                res = temp;
            }
            return res;
        }
};
