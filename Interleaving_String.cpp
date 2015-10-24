/*********************************************************************************
*     File Name           :     Interleaving_String.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-23 21:35]
*     Last Modified       :     [2015-10-23 22:39]
*     Description         :
**********************************************************************************/
#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            if (s3.size() != s1.size() + s2.size())
                return false;
            vector<bool>col(s2.size() + 1, false);
            vector<vector<bool>> v(s1.size() + 1, col);

            v[0][0] = true;

            for (int i = 1; i <= s2.size(); i ++)
                v[0][i] = (s2[i - 1] == s3[i - 1]) && v[0][i - 1];
            for (int i = 1; i <= s1.size(); i ++)
                v[i][0] = (s1[i - 1] == s3[i - 1]) && v[i - 1][0];

            for (int i = 1; i <= s1.size(); i ++) {
                for (int j = 1; j <= s2.size(); j ++) {
                    v[i][j] = ((s2[j - 1] == s3[i + j - 1]) && v[i][j - 1])
                        || ((s1[i - 1]) == s3[i + j - 1] && v[i - 1][j]);
                }
            }

            return v[s1.size()][s2.size()];
        }
};


