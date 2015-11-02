/*********************************************************************************
*     File Name           :     Shortest_Word_Distance.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-11-01 22:47]
*     Last Modified       :     [2015-11-01 22:51]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        int shortestDistance(vector<string>& words, string word1, string word2) {
            int n = words.size();
            int idx1 = -1, idx2 = -1, min_val = INT_MAX;

            for (int i = 0; i < n; i ++) {
                if (words[i] == word1)
                    idx1 = i;
                if (words[i] == word2)
                    idx2 = i;
                if (idx1 != -1 && idx2 != -1)
                    min_val = min(min_val, abs(idx1 - idx2));
            }
            return min_val;
        }
};


