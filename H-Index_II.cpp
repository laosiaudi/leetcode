/*********************************************************************************
*     File Name           :     H-Index_II.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-11 19:53]
*     Last Modified       :     [2015-09-11 20:02]
*     Description         :
**********************************************************************************/

class Solution {
    public:
        int hIndex(vector<int>& citations) {
            int len = citations.size();
            if (len == 0)
                return 0;
            int left = 0;
            int right = len - 1;
            while (left <= right) {
                int mid = (left + right) / 2;
                if (citations[mid] == len - mid)
                    return (len - mid);
                else if (citations[mid] > len - mid)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            return len - left;
        }
};