/*********************************************************************************
*     File Name           :     Paint_Fence.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-22 16:24]
*     Last Modified       :     [2015-10-25 17:52]
*     Description         :
**********************************************************************************/
//google
#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        int numWays(int n, int k) {
            if (n == 0 || k == 0)
                return 0;
            if (n == 1)
                return k;
            int s = k;
            int d = k * (k - 1);
            for (int i = 2; i < n; i ++) {
                int temp = s + d;
                s = d;
                d = (k - 1) * temp;
            }
            return d + s;
        }
};

int main() {
    Solution s;
    for (int i = 1; i <= 20; i ++)
        cout << s.numWays(i, 2) << endl;
}


