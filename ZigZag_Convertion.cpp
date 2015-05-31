// C/C++ File
// AUTHOR:   LaoSi
// FILE:     ZigZag_Convertion.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-31 14:31:21
// MODIFIED: 2015-05-31 20:22:16
#include <iostream>
using namespace std;

class Solution {
    public:
        string convert(string s, int Rows) {
            if (Rows <= 1)
                return s;
            int X = 2*(Rows - 1);

            int len = s.size();
            string res;
            int index = 0;
            for (int i = 1; i <= Rows && index <= len - 1; i ++) {
                res.push_back(s[index]);
                int step = Rows - i;
                int pre = index;
                int next = pre + 2*step;
                while (1) {
                    if (step == 0) {
                        next = next + X;
                        if (next >= len)
                            break;
                        res.push_back(s[next]);
                    } else {
                        if (next >= len)
                            break;
                        res.push_back(s[next]);
                        pre = next;
                        next = pre + X - 2*step;
                        if (next >= len)
                            break;
                        if (next != pre) {
                            res.push_back(s[next]);
                            pre = next;
                            next = pre + 2*step;
                        } else {
                            pre = next;
                            next = pre + X;
                        }
                    }
                }
                index ++;
            }
            return res;
        }
};

class ShorterSolution {
    public:
        string convert(string s, int Rows) {
            if (Rows <= 1)
                return s;

            int X = 2*(Rows - 1);
            string res;
            for (int i = 1; i <= Rows; i ++) {
                for (int j = i - 1; j < s.size();j += X) {
                   res.push_back(s[j]);
                   if (i != 1 && i != Rows && j + X - 2*(i - 1) < s.size())
                       res.push_back(s[j + X - 2 * (i - 1)]);
                }
            }
            return res;
        }
};
