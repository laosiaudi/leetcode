// C/C++ File
// AUTHOR:   laosi
// FILE:     Subset.cpp
// ROLE:     TODO (some explanation)
// CREATED:  2014-12-13 00:19:39
// MODIFIED: 2015-01-05 16:26:03
#include <iostream>
using namespace std;
//note: no-descending order--->> sort first, and select not to include the element first
class Solution {
    public:
        vector<vector<int> > subsets(vector<int> &S) {
           vector<vector<int> >subsets;
           sort(S.begin(), S.end());
           if (S.size() == 0)
               return subsets;
           vector<int>temp;
           temp.push_back(S[0]);
           vector<int>temp2;
           insert(subsets, 1, S.size(), temp2, S);
           insert(subsets, 1, S.size(), temp, S);
           return subsets;
        }

        void insert(vector<vector<int> >&v, int index, int length, vector<int> temp, vector<int> &S) {
            if (index == length) {
               v.push_back(temp);
            } else {
               insert(v, index + 1, length, temp, S);
               temp.push_back(S[index]);
               insert(v, index + 1, length, temp, S);
            }
        }

};
