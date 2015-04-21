// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Container_With_Most_Water.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-04-21 19:57:17
// MODIFIED: 2015-04-21 20:07:09
#include <iostream>
using namespace std;

class Solution {
    public:
        int maxArea(vector<int>& height) {
            int left = 0;
            int right = height.size() - 1;
            int maxValue = 0;
            while (left < right) {
                int shorter = height[left] < height[right] ? height[left] : height[right];
                int area = (right - left) * shorter;
                maxValue = area > maxValue ?  area : maxValue;
                if (height[left] < height[right])
                    left ++;
                else
                    right --;
            }
            return maxValue;
        }
};
