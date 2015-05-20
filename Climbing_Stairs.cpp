// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Climbing_Stairs.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-20 17:28:37
// MODIFIED: 2015-05-20 17:36:56
#include <iostream>
using namespace std;

class Solution {
    public:
        int climbStairs(int n) {
            int size = n;
            vector<int>res(size, 0);
            res[0] = 1;
            res[1] = 2;
            for (int i = 2; i < size; i ++) {
                res[i] = (res[i - 1]  + res[i - 2]);
            }

            return res[size - 1];

        }
};
