// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Best_Time_To_Buy_And_Sell_Stock_II.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-01-30 11:15:10
// MODIFIED: 2015-01-30 11:18:11
#include <iostream>
using namespace std;
 
class Solution {
    public:
    int maxProfit(vector<int> &prices) {
        int length = prices.size();
        if (length == 0)
            return 0;
        int bestProfit = 0;

        for (int i = 1; i < length; i ++) {
            if (prices[i] > prices[i - 1]) {
                bestProfit += (prices[i] - prices[i - 1]);
            } 
        }
        return bestProfit;
    }
};
