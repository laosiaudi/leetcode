// C/C++ File
// AUTHOR:   LaoSi
// FILE:     Permutation_Sequence.cpp
// 2014 @laosiaudi All rights reserved
// CREATED:  2015-05-06 10:48:01
// MODIFIED: 2015-05-06 11:33:15
#include <iostream>
using namespace std;

//DFS will TLE, get string directly
//reference: http://fisherlei.blogspot.jp/2013/04/leetcode-permutation-sequence-solution.html
class Solution {
    public:
        string getPermutation(int n, int k) {
            int nums[9];
            int perm = 1;
            for (int i = 0; i < n;i ++) {
                nums[i] = i + 1;
                perm *= (i + 1);
            }

            k --;//index starts from 0
            string target;
            for (int i = 0;i < n;i ++) {
                perm = perm / (n - i);
                int index = k / perm;
                target.push_back(nums[index] + '0');
                //in case of re-use
                for (int j = index;j < n - i; j ++)
                    nums[j] = nums[j + 1];
                k = k % perm;
            }
            return target;
        }
};
