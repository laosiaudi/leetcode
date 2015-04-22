// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Combination_Sum_II.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-22 18:40:47
// MODIFIED: 2015-04-22 19:54:49
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
            vector<vector<int> >v;
            int size = candidates.size();
            if (size == 0)
                return v;

            sort(candidates.begin(), candidates.end());
            for (int i = 0; i < size; i ++) {
                if (i > 0 && candidates[i] == candidates[i - 1])
                    continue;
                vector<int>temp;
                if (candidates[i] == target) {
                    temp.push_back(candidates[i]);
                    v.push_back(temp);
                } else {
                    temp.push_back(candidates[i]);
                    recursiveFind(v, candidates, i + 1, temp, candidates[i], target);
                    temp.pop_back();
                }
            }
            return v;
        }

        void recursiveFind(vector<vector<int> > &v, vector<int> &candidates, int index, vector<int> &temp, int value, int target) {
            if (value == target) {
                v.push_back(temp);
                return ;
            }
            if (value > target)
                return ;
            int before = candidates[index];
            for (int i = index; i < candidates.size(); i ++) {
                if (i > index && candidates[i] == candidates[i - 1])
                    continue;
                value += candidates[i];
                temp.push_back(candidates[i]);
                recursiveFind(v, candidates, i + 1, temp, value, target);
                value -= candidates[i];
                temp.pop_back();
            }
        }
};

int main() {
    vector<int>v;
    v.push_back(4);
    v.push_back(4);
    v.push_back(2);
    v.push_back(1);
    v.push_back(4);
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    Solution s;
    s.combinationSum2(v, 6);
    return 0;
}
