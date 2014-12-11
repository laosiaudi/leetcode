// C/C++ File
// AUTHOR:   laosi
// FILE:     Pascal_Trangle.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-11 22:27:07
// MODIFIED: 2014-12-12 00:15:41
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<int> getRow(int rowIndex) {
            vector<int>v;
            v.push_back(1);
            for (int i = 0; i <= rowIndex; i ++) {
                int former = 1;
                int index = i + 1;
                for (int j = 0; j< index; j ++) {
                    if (j == 0) {
                        v[0] = 1;;
                        former = 1;
                    } else if (j == index - 1) {
                        v.push_back(1);
                        v[j - 1] = former;
                    } else {
                        int temp = v[j - 1];
                        v[j - 1] = former;
                        former = temp + v[j];
                    }
                }
            }
            return v;
        }
};


int main() {
    Solution s;
    vector<int>p;
    p = s.getRow(3);
    for (int i = 0;i < p.size();i ++)
        cout << p[i];
    return 0;
}
