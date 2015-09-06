/*********************************************************************************
*     File Name           :     Trapping_Rain_Water.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-09-05 19:46]
*     Last Modified       :     [2015-09-05 21:56]
*     Description         :
**********************************************************************************/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
    public:
        //best solution 8ms
        //reference:http://blog.unieagle.net/2012/10/31/leetcode%E9%A2%98%E7%9B%AE%EF%BC%9Atrapping-rain-water/
        int bestTrap(vector<int> &water) {
            int size = water.size();
            int sum = 0;
            if (size < 2)
                return sum;
            int *maxHeightLeft = new int[size];
            int maxValue = water[0];
            for (int i = 0; i < size; i ++) {
                maxHeightLeft[i] = maxValue;
                maxValue = maxValue > water[i] ? maxValue : water[i];
            }

            int *maxHeightRight = new int[size];
            maxValue = water[size - 1];
            for (int i = size - 1; i >= 0; i --) {
                maxHeightRight[i] = maxValue;
                maxValue = maxValue > water[i] ? maxValue : water[i];
                int tmp = maxHeightLeft[i] < maxHeightRight[i]? maxHeightLeft[i] : maxHeightRight[i];
                if (tmp > water[i])
                    sum += (tmp - water[i]);
            }
            delete []maxHeightLeft;
            delete []maxHeightRight;
            return sum;
        }

        //12ms
        int trap(vector<int>& water) {
            int size = water.size();
            if (size == 0)
                return 0;
            int sum = 0;
            int start = 0;
            for (int i = 0; i < size; i ++) {
                if (water[i] != 0) {
                    start = i;
                    break;
                }
            }
            int count = 0;
            int i = start + 1;
            if (i >= size)
                return 0;

            stack<int>s;
            while (i < size) {
                if (water[i] < water[start]) {
                    while (!s.empty() && water[s.top()] < water[i]) {
                        count += water[s.top()];
                        s.pop();
                    }
                    s.push(i);
                } else {
                    while (!s.empty()) {
                        count += water[s.top()];
                        s.pop();
                    }
                    sum += (i - start - 1) * water[start];
                    sum -= count;
                    count = 0;
                    start = i;
                }
                i ++;
            }

            if (!s.empty()) {
                i = s.top();
                s.pop();
                int h = water[i];
                while (!s.empty()) {
                    sum += h * (i - s.top() - 1);
                    i = s.top();
                    h = water[i];
                    s.pop();
                }
                sum += h * (i - start - 1);
                sum -= count;
            }
            return sum;
        }
};
