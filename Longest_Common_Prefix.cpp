/*********************************************************************************
*     File Name           :     Longest_Common_Prefix.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-26 00:20]
*     Last Modified       :     [2015-10-26 00:27]
*     Description         :
**********************************************************************************/
class Solution {
    public:
        string longestCommonPrefix(vector<string>& strs) {
            int size = strs.size();
            if (size == 0)
                return "";
            string compare = strs[0];
            int len = compare.size();

            for (int i = 0; i < len; i ++) {
                for (int j = 1; j < size; j ++) {
                    if (i >= strs[j].size() || compare[i] != strs[j][i])
                        return compare.substr(0, i);
                }
            }

            return compare;
        }
};


