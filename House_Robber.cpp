// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Hose_Robber.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-20 17:22:45
// MODIFIED: 2015-05-20 17:26:09
#include <iostream>
using namespace std;

class Solution {
    public:
        int rob(vector<int> &num) {
            int size = num.size();
            vector<int>res(size + 2, 0);
            for (int i = 2; i < size + 2; i ++) {
                int temp = res[i - 2] + num[i - 2];
                res[i] = res[i - 1] > temp ? res[i - 1] : temp;
            }

            return res[size + 1];
        }
};
