// C/C++ File
// AUTHOR:   laosi
// FILE:     Pascal_Trangle.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-11 22:27:07
// MODIFIED: 2014-12-11 22:49:54
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        vector<vector<int> > generate(int numRows) {
            vector<vector<int> >v;
            for (int i = 0; i < numRows; i ++) {
                vector<int>temp;
                int index = i + 1;
                for (int j = 0; j< index; j ++) {
                    if (j == 0 || j == index - 1)
                        temp.insert(temp.begin() + j, 1);
                    else {
                        temp.insert(temp.begin() + j,v[i - 1][j - 1] + v[i - 1][j]);
                    }
                }
                v.insert(v.begin() + i, temp);
            }
            return v;
        }
};


int main() {
    Solution s;
    s.generate(5);
    return 0;
}
