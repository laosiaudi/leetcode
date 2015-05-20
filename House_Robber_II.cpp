// C/C++ File
// AUTHOR:   LaoSi
// FILE:     House_Robber_II.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-20 17:41:28
// MODIFIED: 2015-05-20 17:48:20
#include <iostream>
using namespace std;

class Solution {
    public:
        int rob(vector<int> &num) {
            int size = num.size();
            if (size == 0)
                return 0;
            if (size == 1)
                return num[0];
            //do not rob the first house
            vector<int>res1(size, 0);
            res1[1] = num[1];
            for (int i = 2; i < size; i ++) {
                int temp = res1[i - 2] + num[i];
                res1[i] = res1[i - 1] > temp ? res1[i - 1] : temp;
            }

            //rob the first house
            vector<int>res2(size, 0);
            res2[0] = num[0];
            res2[1] = num[0];
            for (int i = 2; i < size - 1; i ++) {
                int temp = res2[i - 2] + num[i];
                res2[i] = res2[i - 1] > temp ? res2[i - 1] : temp;
            }

            return res1[size - 1] > res2[size - 2] ? res1[size - 1] : res2[size - 2];

        }
};
