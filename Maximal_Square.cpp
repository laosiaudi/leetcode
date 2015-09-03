// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Maximal_Square.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-09-02 13:55:45
// MODIFIED: 2015-09-03 17:03:09
#include <iostream>
using namespace std;

class Solution {
    public:
        int maximalSquare(vector<vector<char> >& matrix) {
            int line = matrix.size();
            if (line == 0)
                return 0;
            int col = matrix[0].size();
            vector<int>v(col, 0);
            vector<vector<int> >tmp(line, v);

            int len = 0;
            for (int i = 0;i < line; i ++) {
                for (int j = 0; j < col; j ++) {
                    tmp[i][j] = matrix[i][j] - '0';
                    if (i == 0) {
                        if (tmp[i][j] && len == 0)
                            len = 1;
                    } else if (j == 0) {
                        if (tmp[i][j] && len == 0)
                            len = 1;
                    } else {
                        if (!tmp[i][j]) {
                            tmp[i][j] = 0;
                        } else {
                            tmp[i][j] = getState(tmp[i - 1][j], tmp[i][j - 1], tmp[i - 1][j - 1]);
                            len = len > tmp[i][j] ? len : tmp[i][j];
                        }
                    }
                }
            }
            return len * len;

        }
            int getState(int a, int b, int c) {
                if (a == 0 || b == 0 || c == 0) {
                    return 1;
                } else if (a == b && c >= a) {
                    return a + 1;
                } else if (a == b && c < a) {
                    return a;
                } else {
                    if (a - b == 1 || b - a == 1)
                        return a > b ? a : b;
                    else 
                        return (a < b ? a: b) + 1;
                }
            }

            //best getState function , actually getState can be simplied as below
            //but function below has another perfect idea
            //the state is formed by the min of (a,b,c) + 1
            int bestGetState(int a, int b, int c) {
                int tmp = a < b ? a : b;
                return (tmp < c ? tmp : c) + 1;
            }

};
