// C/C++ File
// AUTHOR:   LaoSi
// FILE:     next_permutation.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2014-12-14 00:55:56
// MODIFIED: 2014-12-14 02:02:36
#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            int maxNum = num.size();
            int com;
            for (int j = maxNum - 1;j >= 0; j --) {
                if (j == 0) {
                    com = 0;
                }
                else{
                    com = num[j - 1];
                }
                if (num[j] > com) {
                    int i;
                    for (i = maxNum - 1; i >= j; i --) {
                        if (num[i] > num[j - 1])
                            break;
                    }
                    int key = num[i];
                    int len = maxNum - i;
                    int dis = i - j;
                    if (j == 0)
                        num.insert(num.begin(), key);
                    else
                        num.insert(num.begin() + j - 1, key);
                    int ii;
                    for (ii = 0; ii < len - 1; ii ++)
                        num.insert(num.begin() + j + ii, num[num.size() - ii - 1]);

                    for (int i = 0;i < dis -  1; i ++)
                        num.insert(num.begin() + j + ii + i + 1, num[num.size() - len - i - 1]);
                    break;
                }
            }
            int dis = num.size() - maxNum;
            for (int i = 0; i< dis; i ++)
                num.erase(num.begin() + maxNum);
        }
};

int main() {
    Solution ss;
    vector<int>v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(7);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    ss.nextPermutation(v);
    for (int i = 0; i < v.size(); i ++) {
            cout << v[i] << " , ";
    }

    return 0;
}
