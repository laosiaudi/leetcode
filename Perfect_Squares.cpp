/*********************************************************************************
*     File Name           :     Perfect_Squares.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-16 19:34]
*     Last Modified       :     [2015-10-16 20:15]
*     Description         :
**********************************************************************************/

#include <iostream>
#include <queue>
#include <vector>
#include <math.h>

using namespace std;
class Solution {
    public:
        int numSquares(int n) {
            vector<int>v;
            v.push_back(0);
            v.push_back(1);
            for (int i = 2; i <= n; i ++) {
                int tmp = sqrt(i);
                if (tmp * tmp == i)
                    v.push_back(1);
                else {
                    int min = INT_MAX;
                    for (int j = tmp; j >= 1; j --) {
                        int cnt = 1 + v[i - j * j];
                        min = min < cnt ? min : cnt;
                    }
                    v.push_back(min);
                }
            }
            return v[n];

        }
};

int main() {
    Solution s;
    cout <<  s.numSquares(3) << endl;
    //cout <<  s.numSquares(12) << endl;
    //cout << s.numSquares(13) << endl;
    //cout << s.numSquares(9) << endl;
    //cout << s.numSquares(48) << endl;
    //cout << s.numSquares(9975) << endl;
    return 0;
}


