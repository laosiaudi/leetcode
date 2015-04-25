// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Happy_Number.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-25 18:13:39
// MODIFIED: 2015-04-25 18:19:19
#include <iostream>
using namespace std;

class Solution {
    public:
        bool isHappy(int n) {
            map<int, bool>check;
            int temp = n;
            while (1) {
                int ans = 0;
                while (1) {
                    ans += (temp % 10) * (temp % 10);
                    temp = temp / 10;
                    if (temp == 0)
                        break;
                }
                if (ans == 1)
                    return true;
                if (check.find(ans) == check.end()) {
                    check[ans] = true;
                } else {
                    return false;
                }
                temp = ans;
            }
        }
};
