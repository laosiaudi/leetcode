// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Unique_Binary_Search_Trees.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-20 22:53:28
// MODIFIED: 2015-05-20 23:06:06
#include <iostream>
using namespace std;

class Solution {
    public:
        int numTrees(int n) {
            vector<int>res(n + 1, 0);
            res[1] = 1;
            res[2] = 2;
            for (int i = 3; i <= n; i ++) {
                res[i] += 2*res[ i - 1];
                int temp = (i - 1)/2;
                for (int j = 1; j <= temp; j ++)
                    if (j * 2 == i - 1)
                        res[i] = res[i] + res[j] * res[i - 1 - j];
                    else
                        res[i] = res[i] + res[j] * res[i - 1 - j] * 2;
            }

            return res[n];
        }
};
