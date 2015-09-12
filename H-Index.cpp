/*********************************************************************************
*     File Name           :     H-Index.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-11 18:58]
*     Last Modified       :     [2015-09-11 19:44]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int cnt = 0;
            sort(citations.begin(), citations.end(), std::greater<int>());
            for (int i = 0; i < citations.size(); i ++) {
                if (i < citations[i])
                    cnt ++;
            }
            return cnt;
        }
};


