// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Best_Time_To_Buy_And_Sell_Stock.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-01-10 11:46:14
// MODIFIED: 2015-01-10 11:51:44
#include <iostream>
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int> &prices) {
        int length = prices.size();
        if (length == 0)
            return 0;
        int minPrice = prices[0];
        int bestProfit = 0;

        for (int i = 1; i < length; i ++) {
            if (prices[i] <= minPrice) {
                minPrice = prices[i];
            } else {
               int temp = price[i] - minPrice;
               bestProfit = bestProfit > temp ? bestProfit : temp;
            }
        }
        return bestProfit;
    }
};
