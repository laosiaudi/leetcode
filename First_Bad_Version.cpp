/*********************************************************************************
*     File Name           :     First_Bad_Version.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-11-11 19:36]
*     Last Modified       :     [2015-11-11 19:41]
*     Description         :
**********************************************************************************/



// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n;
        int target = 0;
        while (start <= end) {
            
            int mid = start + (end - start) / 2;//(start + end)/2 will cause overflow
            if (isBadVersion(mid)) {
                target = mid;
                end = mid - 1;
            } else {
                start = mid + 1;
                if (isBadVersion(start))
                    return start;
            }
        }
        return target;
    }
};
