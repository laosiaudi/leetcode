// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Compare_Version_Numbers.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-15 01:05:04
// MODIFIED: 2015-05-15 10:20:25
#include <iostream>
using namespace std;

class Solution {
    public:
        int compareVersion(string version1, string version2) {
            int len1 = version1.size();
            int len2 = version2.size();

            int p1 = 0;
            int p2 = 0;
            vector<int>v1;
            vector<int>v2;
            for (;p1 < len1; p1 ++) {
                int temp = 0;
                while (version1[p1] != '.' && p1 < len1) {
                    temp = temp * 10 + version1[p1] - '0';
                    p1 ++;
                }
                v1.push_back(temp);
                if (p1 == len1)
                    break;
            }
            for (;p2 < len2; p2 ++) {
                int temp = 0;
                while (version2[p2] != '.' && p2 < len2) {
                    temp = temp * 10 + version2[p2] - '0';
                    p2 ++;
                }
                v2.push_back(temp);
                if (p2 == len2)
                    break;
            }
            int i, j;
            len1 = v1.size();
            len2 = v2.size();
            for (i = 0, j = 0;i < len1 && j < len2; i ++, j ++) {
                if (v1[i] > v2[j])
                    return 1;
                else if (v1[i] < v2[j])
                    return -1;
            }

            if (i == len1 && j == len2)
                return 0;
            else if (i == len1 && j != len2) {
                return v2[j] == 0 ? 0 : -1;
            } else if (i != len1 && j == len2) {
                return v1[i] == 0 ? 0 : 1;
            }


        }
};
