// C/C++ File
// AUTHOR:   laosi
// FILE:     Triangle.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-12 23:32:45
// MODIFIED: 2014-12-13 00:16:12
#include <iostream>
using namespace std;
//note: using DP, only O(n) extra space used
class Solution {
    public:
        int minimumTotal(vector<vector<int> > &Triangle) {
            int height = Triangle.size();
            if (height == 0)
                return 0;
            if (height == 1)
                return Triangle[0][0];
            int N = Triangle[height - 1].size();
            int *minimum = new int [N];
            for (int i = 0;i < Triangle[height - 1].size(); i ++)
                minimum[i] = Triangle[height - 1][i];
            for (int i = height - 1; i > 0; i --) {
                for (int j = 0; j < Triangle[i].size() - 1; j ++) {
                    int temp1 = minimum[j] + Triangle[i - 1][j];
                    int temp2 = minimum[j + 1] + Triangle[i - 1][j];
                    minimum[j] = temp1 < temp2 ? temp1 : temp2;
                }
            }
            int temp = minimum[0];
            delete []minimum;
            return temp;
        }
};
