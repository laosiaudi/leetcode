// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Gas_Station.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-06-04 12:37:02
// MODIFIED: 2015-06-04 12:59:20
#include <iostream>
using namespace std;

class Solution {
    public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int index = 0;
            int size = gas.size();
            int total = 0;
            int local = 0;
            for (int i = 0; i < size; i ++) {
                int amount = gas[i] - cost[i];
                total += amount;
                local += amount;
                if (local < 0) {
                    index = i + 1;
                    local = 0;
                }
            }
            if (total >= 0)
                return index;
            else
                return -1;
        }
};
