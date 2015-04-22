// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Combination_Sum.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-22 17:20:46
// MODIFIED: 2015-04-22 18:39:51
#include <iostream>
using namespace std;

class Solution {
    public:
        vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
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
                    bool flag = recursiveFind(v, candidates, i, temp, candidates[i], target);
                    temp.pop_back();
                }
            }
            return v;
        }

        bool recursiveFind(vector<vector<int> > &v, vector<int> &candidates, int index, vector<int> &temp, int value, int target) {
            if (value == target) {
                v.push_back(temp);
                return true;
            }
            if (value > target)
                return false;
            int before = candidates[index];
            for (int i = index; i < candidates.size(); i ++) {
                if (i > index && candidates[i] == candidates[i - 1])
                    continue;
                value += candidates[i];
                temp.push_back(candidates[i]);
                bool flag = recursiveFind(v, candidates, i, temp, value, target);
                value -= candidates[i];
                temp.pop_back();
            }
        }
};
