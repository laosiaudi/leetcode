// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Subset_II.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2014-12-13 22:11:50
// MODIFIED: 2014-12-14 00:13:15
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<vector<int> > subsetsWithDup(vector<int> &S) {
            vector<vector<int> >subsets;
            if (S.size() == 0)
                return subsets;

            sort(S.begin(), S.end());
            vector<int>ele;
            vector<int>time;
            int num = 1;
            bool flag = false;
            for (int i = 0;i < S.size();i ++) {
                if (i == 0)
                    ele.push_back(S[i]);
                else {
                    if (S[i] == S[i - 1]) {
                        num ++;
                        if (i == S.size() - 1)
                            time.push_back(num);
                    } else {
                        flag = true;
                        time.push_back(num);
                        num = 1;
                        ele.push_back(S[i]);
                        if (i == S.size() - 1)
                            time.push_back(1);
                    }
                }
            }
            if (flag == false)
                time.push_back(num);
            for (int jj = 0; jj <= time[0]; jj ++) {
                vector<int>temp;
                for (int i = 0; i < jj; i ++)
                    temp.push_back(ele[0]);
                insert(subsets, 1, ele, time, temp, ele.size());
            }
            return subsets;
        }

        void insert(vector<vector<int> >&v, int index, vector<int>ele, vector<int>time, vector<int> temp, int length) {
            if (index == length) {
                v.push_back(temp);
            } else {
                for (int i = 0; i <= time[index]; i ++) {
                    vector<int> t = temp;
                    for (int j = 0; j < i;j ++) {
                        t.push_back(ele[index]);
                    }
                    insert(v, index + 1, ele, time, t, length);
                }
            }
        }
};

int main() {
    Solution ss;
    vector<int>v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(3);
    vector<vector<int> >s = ss.subsetsWithDup(v);
    for (int i = 0; i < s.size(); i ++) {
        for (int j = 0; j< s[i].size(); j ++)
            cout << s[i][j] << " , ";
        cout << "\n";
    }

    return 0;

}
