/*********************************************************************************
*     File Name           :     Wiggle_Sort.cpp
*     Created By          :     laosiaudi
*     Creation Date       :     [2015-10-24 16:10]
*     Last Modified       :     [2015-10-24 16:25]
*     Description         :
**********************************************************************************/
//google wiggle sort
#include <vector>
#include <iostream>

using namespace std;
class Solution {
    public:
        void wiggleSort(vector<int>& nums) {
            if (nums.size() <= 1)
                return;
            for (int i = 0; i < nums.size() - 1; i ++) {
               if (i % 2 == 1) {
                   if (nums[i] < nums[i + 1]) {
                       int tmp = nums[i];
                       nums[i] = nums[i + 1];
                       nums[i + 1] = tmp;
                   }
               } else {
                   if (nums[i] > nums[i + 1]) {
                       int tmp = nums[i];
                       nums[i] = nums[i + 1];
                       nums[i + 1] = tmp;
                   }
               }
            }
        }
};

int main() {
    vector<int>v;
    v.push_back(3);
    v.push_back(5);
    v.push_back(2);
    v.push_back(1);
    v.push_back(6);
    v.push_back(4);

    Solution s;
    s.wiggleSort(v);
    for (auto item : v) {
        cout << item << " ";
    }

}



