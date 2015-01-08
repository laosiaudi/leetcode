// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Majority_Element.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-01-08 19:50:03
// MODIFIED: 2015-01-08 20:06:42
#include <iostream>
using namespace std;

class Solution {
    public:
    int majorityElement(vector<int> &num) {
            int length = num.size();
            int limit = length/2;
            map<int,int>record;

            for (int i = 0; i < length; i ++) {
                if (record.find(num[i]) == record.end()) {
                    record[num[i]] = 0;
                } else {
                    record[num[i]] ++;
                }
                if (record[num[i]] == limit)
                    return num[i];
            }
    }
};
